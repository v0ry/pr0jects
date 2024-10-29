#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct _Word_
{
  char* solution_;
  size_t guesses_;

  struct _Word_* next_;
} Word;

int parseFile(FILE* file, Word** start);
int readLine(FILE* file, char** word);
Word* createWord(char* word);

int hangman(Word* start);
int revealLetters(char* shown_word, char* solution, char input);
void freeMemory(Word* current_element);

int main(int argc, char* argv[])
{
  if (argc != 2)
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

  Word* start = NULL;
  int return_value = parseFile(file, &start);
  fclose(file);

  if (return_value == 3)
  {
    freeMemory(start);
    printf("ERROR: file %s invalid\n", argv[1]);
    return 3;
  }
  if (return_value == 4)
  {
    freeMemory(start);
    printf("ERROR: Out of Memory\n");
    return 4;
  }

  if (hangman(start) == 4)
  {
    freeMemory(start);
    printf("ERROR: Out of Memory\n");
    return 4;
  }

  freeMemory(start);
  return 0;
}

int parseFile(FILE* file, Word** start)
{
  Word* current;
  while (1)
  {
    char* word = NULL;
    int error = readLine(file, &word);

    if (error != 0)
      return error;

    Word* next_word = createWord(word);
    if (!next_word)
    {
      free(word);
      return 4;
    }

    if (*start == NULL)
      *start = next_word;
    else
      current->next_ = next_word;
    current = next_word;
  }
  return 0;
}

int readLine(FILE* file, char** word)
{
  // This function is not really complete, it should be possible to
  // handle arbitrary long inputs, not restricted to 100 chars
  // All the checks should be improved as well...

  char buffer[100];
  if (fgets(buffer, 100, file) == NULL)
    return -1;

  char* actual_word = strtok(buffer, " \n");
  if (actual_word == NULL || strtok(NULL, " \n") != NULL)
    return 3;

  for (size_t i = 0; actual_word[i]; i++)
  {
    if (!(('A' <= actual_word[i] && actual_word[i] <= 'Z') || 
          ('a' <= actual_word[i] && actual_word[i] <= 'z')))
      return 3;
  }

  *word = malloc(sizeof(char) * (strlen(actual_word) + 1));
  if (!*word)
    return 4;

  strcpy(*word, actual_word);
  return 0;
}

Word* createWord(char* word)
{
  Word* next_word = malloc(sizeof(Word));
  if (next_word)
  {
    next_word->guesses_ = 0;
    next_word->solution_ = word;
    next_word->next_ = NULL;
  }
  return next_word;
}

int hangman(Word* start)
{
  size_t word_counter = 0;
  size_t solved_counter = 0;

  for (Word* current = start; current != NULL; current = current->next_)
  {
    size_t length = strlen(current->solution_);
    char* shown_word = malloc(sizeof(char) * (length + 1));
    if (!shown_word)
      return 4;
    
    shown_word[0] = current->solution_[0];
    for (size_t i = 1; i < length; i++)
      shown_word[i] = '_';
    shown_word[length] = 0;

    while (current->guesses_ < 11)
    {
      printf("%s (%lu)\n", shown_word, current->guesses_);
      printf("Your guess: ");

      // Very unsafe input parsing
      char input = tolower(getchar());
      if (input != '\n')
        getchar();

      if (revealLetters(shown_word, current->solution_, input))
      {
        if (strcmp(shown_word, current->solution_) == 0)
          break;
      }
      else
      {
        current->guesses_++;
      }
    }

    if (current->guesses_ < 11)
    {
      printf("%s (%ld)\n", current->solution_, current->guesses_);
      solved_counter++;
    }
    else
    {
      printf("%s (x_x)\n", current->solution_);
    }

    free(shown_word);
    word_counter++;
  }

  printf("won (%lu/%lu)\n", solved_counter, word_counter);
  return 0;
}

int revealLetters(char* shown_word, char* solution, char input)
{
  int return_value = 0;

  for (size_t i = 0; solution[i]; i++)
  {
    if (tolower(solution[i]) == input)
    {
      shown_word[i] = solution[i];
      return_value = 1;
    }
  }

  return return_value;
}

void freeMemory(Word* current_element)
{
  while (current_element != NULL)
  {
    Word* next_element = current_element->next_;
    free(current_element->solution_);
    free(current_element);
    current_element = next_element;
  }
}
