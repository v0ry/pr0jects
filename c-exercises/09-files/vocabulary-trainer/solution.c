#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//------------------------------------------------------------------------------
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//------------------------------------------------------------------------------
#define CAPACITY_STEP 8

typedef struct
{
  void* start_;
  size_t element_size_;

  size_t length_;
  size_t capacity_;
} DynArray;

void dynArray_init(DynArray* array, size_t data_size)
{
  array->start_ = NULL;
  array->element_size_ = data_size;
  array->length_ = 0;
  array->capacity_ = 0;
}

void dynArray_destroy(DynArray* array)
{
  if (array->start_ != NULL)
  {
    free(array->start_);
    array->start_ = NULL;
  }
  array->element_size_ = 0;
  array->length_ = 0;
  array->capacity_ = 0;
}

int dynArray_push_back(DynArray* array, void* object)
{
  if (array->start_ == NULL)
  {
    array->start_ = malloc(array->element_size_ * CAPACITY_STEP);
    if (array->start_ == NULL)
    {
      return -1;
    }

    memcpy(array->start_, object, array->element_size_);
    array->length_ = 1;
    array->capacity_ = CAPACITY_STEP;

    return 0;
  }

  if (array->capacity_ > array->length_)
  {
    memcpy((char*) array->start_ + (array->length_ * array->element_size_), object, array->element_size_);
    array->length_++;

    return 0;
  }

  void* new_start = realloc(array->start_, (array->capacity_ + CAPACITY_STEP) * array->element_size_);
  if (new_start == NULL)
  {
    return -1;
  }

  array->start_ = new_start;
  memcpy((char*) array->start_ + (array->length_ * array->element_size_), object, array->element_size_);
  array->length_++;
  array->capacity_ += CAPACITY_STEP;

  return 0;
}

int dynArray_pop_back(DynArray* array)
{
  if (array->start_ == NULL)
  {
    return -1;
  }

  if (array->capacity_ - 7 == array->length_)
  {
    if (array->capacity_ > CAPACITY_STEP)
    {
      void* new_start = realloc(array->start_, (array->capacity_ - CAPACITY_STEP) * array->element_size_);
      if (new_start == NULL)
      {
        return -1;
      }
      array->start_ = new_start;
    }
    else
    {
      free(array->start_);
      array->start_ = NULL;
    }
    array->capacity_ -= CAPACITY_STEP;
  }
  array->length_--;

  return 0;
}

void* dynArray_at(DynArray* array, size_t position)
{
  if (position >= array->length_)
  {
    return NULL;
  }
  
  return (void*) ((char*) array->start_ + (position * array->element_size_));
}
//------------------------------------------------------------------------------
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//------------------------------------------------------------------------------

typedef struct
{
  char original[32];
  char translation[32];
} Vocabulary;

typedef enum
{
  NEWLINE,
  BEGIN,
  ORIGINAL,
  MIDDLE,
  TRANSLATION,
  END
} State;

int parseVocabularies(FILE* file, DynArray* vocabularies);
void trainVocabularies(DynArray* vocabularies);
int handleVocabulary(char* print, char* compare);

int main(int argc, char* argv[])
{
  if (argc < 2)
  {
    printf("usage: %s filename\n", argv[0]);
    return 1;
  }

  FILE* file = fopen(argv[1], "r");
  if (!file)
  {
    printf("ERROR: cannot open file %s\n", argv[1]);
    return 2;
  }

  DynArray vocabularies;
  dynArray_init(&vocabularies, sizeof(Vocabulary));

  int parse_value = parseVocabularies(file, &vocabularies);
  if (parse_value == 3)
  {
    printf("ERROR: file %s invalid\n", argv[1]);

    dynArray_destroy(&vocabularies);
    fclose(file);
    return 3;
  }
  if (parse_value == 4)
  {
    printf("ERROR: Out of Memory\n");

    dynArray_destroy(&vocabularies);
    fclose(file);
    return 4;
  }

  trainVocabularies(&vocabularies);

  dynArray_destroy(&vocabularies);
  fclose(file);
  return 0;
}

int parseVocabularies(FILE* file, DynArray* vocabularies)
{
  Vocabulary v; // dummy for push back

  State state = NEWLINE;
  char next_char = 0;
  size_t counter = 0;
  Vocabulary* voc;

  while ((next_char = fgetc(file)) != EOF)
  {
    if (next_char == ' ')
    {
      switch (state)
      {
        case NEWLINE:
          state = BEGIN;
          continue;
        case ORIGINAL:
          voc->original[counter] = 0;
          state = MIDDLE;
          continue;
        case TRANSLATION:
          state = END;
          continue;
        default:
          continue;
      }
    }

    if (next_char == '\n')
    {
      if (state == TRANSLATION || state == END)
      {
        state = NEWLINE;
        voc->translation[counter] = 0;
      }
      else
        return 3;
      continue;
    }

    switch (state)
    {
      case NEWLINE:
      case BEGIN:
        if (dynArray_push_back(vocabularies, &v))
          return 4;
        voc = dynArray_at(vocabularies, vocabularies->length_ - 1);
        counter = 0;
        state = ORIGINAL;
      case ORIGINAL:
        voc->original[counter++] = next_char;
        break;

      case MIDDLE:
        counter = 0;
        state = TRANSLATION;
      case TRANSLATION:
        voc->translation[counter++] = next_char;
        break;

      case END:
        return 3;
    }
  }

  if (state != NEWLINE)
    return 3;

  return 0;
}

void trainVocabularies(DynArray* vocabularies)
{
  size_t correct_counter = 0;

  for (size_t i = 0; i < vocabularies->length_; i++)
  {
    Vocabulary* voc = dynArray_at(vocabularies, i);
    if (i % 2 == 0)
    {
      if (handleVocabulary(voc->original, voc->translation))
      {
        puts("correct");
        correct_counter++;
      }
      else
      {
        puts("incorrect");
      }
    }
    else
    {
      if (handleVocabulary(voc->translation, voc->original))
      {
        puts("correct");
        correct_counter++;
      }
      else
      {
        puts("incorrect");
      }
    }
  }

  printf("%lu / %lu\n", correct_counter, vocabularies->length_);
}

int handleVocabulary(char* print, char* compare)
{
  char input[32];
  int valid = 0;

  printf("%s - ", print);
  fgets(input, 32, stdin);

  for (size_t i = 0; input[i]; i++)
  {
    if (input[i] == '\n')
    {
      input[i] = 0;
      valid = 1;
      break;
    }
  }

  if (!valid)
  {
    while (getchar() != '\n');
    return 0;
  }

  if (strcmp(input, compare) != 0)
  {
    return 0;
  }
  
  return 1;
}
