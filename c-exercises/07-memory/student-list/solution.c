#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STRING_LENGTH 32


void setNullbyte(char* input)
{
  bool found_newline = false;
  for (size_t i = 0; input[i]; i++)
  {
    if (input[i] == '\n')
    {
      input[i] = 0;
      found_newline = true;
    }
  }

  if(!found_newline)
    while ( getchar() != '\n' ); // throw away if there is still more to read from stdin
}

char** readAndGetNames(int len_names)
{
  char** name_collection = (char**)malloc(len_names * sizeof(char*));

  char tmp_string[MAX_STRING_LENGTH] = {0};
  for(int len_counter = 0; len_counter < len_names; len_counter++)
  {
    switch(len_counter + 1)
    {
      case 1:
        printf("Enter %dst name: ", len_counter + 1);
        break;
      case 2:
        printf("Enter %dnd name: ", len_counter + 1);
        break;
      case 3:
        printf("Enter %drd name: ", len_counter + 1);
        break;
      default:
        printf("Enter %dth name: ", len_counter + 1);
        break;
    }
    fgets(tmp_string, MAX_STRING_LENGTH, stdin);

    setNullbyte(tmp_string);


    int cur_name_len = strlen(tmp_string);
    char* cur_name = (char*)malloc(cur_name_len * sizeof(char) + 1); // copy also nullbyte

    strncpy(cur_name, tmp_string, cur_name_len + 1);
    name_collection[len_counter] = cur_name;
  }

  return name_collection;

}

void freeList(char** array, int len)
{
  for(int counter = 0; counter < len; counter++)
  {
    free(array[counter]);
  }
  free(array);
}


int main(void)
{

  // Do not change the main function - only the functions readAndGetNames() and freeList() should be written
  int len_names = 0;
  printf("How many students are in class? ");
  scanf("%d", &len_names);
  getchar();

  // TODO: implement this function
  char** array = readAndGetNames(len_names);

  printf("Student list:\n");
  printf("----------------------------------------\n");

  for(int i = 0; i < len_names; i++)
  {
    printf("|%3d: %-32s |\n", i+1, array[i]);
  }
  printf("----------------------------------------\n");

  // TODO: implement this function
  freeList(array, len_names);
  return 0;
}
