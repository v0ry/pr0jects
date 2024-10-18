#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_BUFFERSIZE 8
#define ERROR 1

char* getLine()
{
  // initialize the line size with 8 - if we need more, we increase the size
  int line_size = BLOCK_BUFFERSIZE;
  char* line = (char*) malloc(line_size * sizeof(char));
  if(line == NULL)
    return NULL;

  printf("Input: ");
  fgets(line, BLOCK_BUFFERSIZE, stdin); // fgets reads 7 characters and add the \0 behind

  char* newline_char = strchr(line, '\n');
  // if we do not found a '\n' inside 'line' we know that we have to read more from input
  if (newline_char == NULL)
  {
    printf("This input has more than 7 characters (incl. the \\n)\n");
    line_size += BLOCK_BUFFERSIZE;

    line = (char*)realloc(line, (line_size * sizeof(char)));
    if(line == NULL)
      return NULL;

    // we want at the end of the string and concat the remaining characters here
    char* line_end = line + BLOCK_BUFFERSIZE - 1;
    fgets(line_end, BLOCK_BUFFERSIZE, stdin);  // fgets reads 7 characters and add the \0 behind
  }
  else
  {
    *newline_char = '\0'; // set null byte on '\n' position
    return line;
  }

  // if we do not find a '\n' here this string is too long
  newline_char = strchr(line, '\n');
  if (newline_char == NULL)
  {
    printf("This input has more than 14 characters (incl. the \\n) and is too big for this example\n");
    // at the end of the string we already have a \0 because fgets set it there
  }
  else
  {
    *newline_char = '\0'; // set null byte on '\n' position
  }
  return line;
}

int main()
{
  char* teststring = getLine();
  if(teststring == NULL)
    return ERROR;
  printf("The teststring is '%s'\n", teststring);

  free(teststring);

  return 0;
}
