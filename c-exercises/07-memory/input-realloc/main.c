#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_BUFFERSIZE 8
#define ERROR 1

char* getLine()
{
  // TODO: write here the function logic
  char* line = NULL;

  return line;
}

int main()
{
  char* teststring = getLine();
  if(teststring == NULL)
    return ERROR;
  printf("The teststring is '%s'\n", teststring);

  return 0;
}
