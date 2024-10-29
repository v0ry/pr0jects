#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 64
#define MAX_ITEMS 50
#define QUIT_STRING "quit"
#define TRUE 1
#define FALSE 0

void readInput(char* input)
{
  printf("Enter item: ");
  fgets(input, MAX_INPUT_SIZE, stdin);

  // set the nullbyte at the end of the string
  for (size_t i = 0; input[i]; i++)
  {
    if (input[i] == '\n')
    {
      input[i] = 0;
      return;
    }
  }
  while (getchar() != '\n');
  printf("Input too long!\n");
}

char* getMemoryForString()
{
  return (char*)malloc(MAX_INPUT_SIZE * sizeof(char));
}

void freeList(char** list, unsigned char len)
{
  for(unsigned char iterator = 0; iterator < len; iterator++)
  {
    free(list[iterator]);
  }
}

void putInputInList(char** list, char* input, unsigned char position)
{
  list[position] = input;
}

int checkInputForQuit(char* input)
{
  char tmp_input[MAX_INPUT_SIZE] = {0};
  for(unsigned char i = 0; input[i]; i++)
  {
    tmp_input[i] = tolower(input[i]);
  }
  if(strcmp(tmp_input,QUIT_STRING) == 0)
  {
    return TRUE;
  }
  return FALSE;
}

void printList(char** list, unsigned char len)
{
  printf("Current ToDo List:\n");
  for(unsigned char i = 0; i < len; i++)
  {
    printf("%d: %s\n", i, list[i]);
  }
  printf("----------------------\n");
}

int main(void)
{
  printf("---- Starting ToDo List ----\n");

  char* list[MAX_ITEMS];
  unsigned char cur_list_length = 0;


  while(1)
  {
    char* input = getMemoryForString();
    readInput(input);
    putInputInList(list, input, cur_list_length);
    cur_list_length++;

    if(checkInputForQuit(input))
    {
      break;
    }
    printList(list, cur_list_length);
    if(cur_list_length == MAX_ITEMS)
    {
      printf("Maximum Number of Items reached\n");
      break;
    }
  }
  freeList(list, cur_list_length);
  return 0;
}
