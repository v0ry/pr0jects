#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STRING_LENGTH 32


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
