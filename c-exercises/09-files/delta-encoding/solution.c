#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>

#define USAGE "Compression:   %s -c 'compressed_file' 'uncompressed_file'\n" \
              "Decompression: %s -d 'uncompressed_file' 'compressed_file'\n"

const char SIGNAL_NEW = CHAR_MIN;

typedef enum
{
  NEW,
  DIFF
} State;

void compress(FILE* compressed, FILE* uncompressed);
void decompress(FILE* uncompressed, FILE* compressed);

int main(int argc, char* argv[])
{
  char mode;

  if (argc != 4)
  {
    printf(USAGE, argv[0], argv[0]);
    return 1;
  }

  if (strcmp(argv[1], "-c") == 0)
  {
    mode = 'c';
  }
  else if (strcmp(argv[1], "-d") == 0)
  {
    mode = 'd';
  }
  else
  {
    printf(USAGE, argv[0], argv[0]);
    return 1;
  }

  FILE* original_file = fopen(argv[3], "r");
  if (original_file == NULL)
  {
    printf("The file %s may not exist.\n", argv[3]);
    return 2;
  }

  FILE* new_file = fopen(argv[2], "w");
  if (new_file == NULL)
  {
    fclose(original_file);
    printf("The file %s cannot be created.\n", argv[2]);
    return 3;
  }

  if (mode == 'c')
  {
    compress(new_file, original_file);
  }
  else
  {
    decompress(new_file, original_file);
  }

  printf("Completed successfully.\n");

  fclose(original_file);
  fclose(new_file);
  return 0;
}

void compress(FILE* compressed, FILE* uncompressed)
{
  int previous_number = 0;
  int next_number = 0;
  State state = NEW;

  while (fscanf(uncompressed, "%d", &next_number) != EOF)
  {
    int diff = next_number - previous_number;

    if (state == NEW)
    {
      fwrite(&next_number, 4, 1, compressed);
      state = DIFF;
      previous_number = next_number;
      continue;
    }

    if (CHAR_MIN < diff && diff <= CHAR_MAX)
    {
      fwrite(&diff, 1, 1, compressed);
    }
    else
    {
      fwrite(&SIGNAL_NEW, 1, 1, compressed);
      fwrite(&next_number, 4, 1, compressed);
    }

    previous_number = next_number;
  }
}

void decompress(FILE* uncompressed, FILE* compressed)
{
  int previous_number = 0;
  int next_number = 0;
  State state = NEW;

  char bytes[4];

  while (fread(bytes, 1, 1, compressed) >= 1)
  {
    if (state == DIFF && bytes[0] == SIGNAL_NEW)
    {
      state = NEW;
      previous_number = 0;
      continue;
    }

    if (state == NEW)
    {
      fread(bytes + 1, 1, 3, compressed);
      next_number = *((int*) bytes);
      state = DIFF;
    }
    else
    {
      next_number = previous_number + bytes[0];
    }

    fprintf(uncompressed, "%d\n", next_number);
    previous_number = next_number;
  }
}
