#include <stdio.h>

int main(void)
{
  char input_letter = 0;
  char string[100];

  size_t counter;
  for (counter = 0; (input_letter = getchar()) != '\n'; counter++)
  {
    string[counter] = input_letter;
  }
  string[counter] = 0;

  return reversePrint(string);
}
