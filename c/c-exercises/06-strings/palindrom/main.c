#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int isPalindrome(char name[100]);

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

  if(isPalindrome(string))
  {
    printf("%s is a Palindrome\n", string);
  }
  else
  {
    printf("%s is not a Palindrome\n", string);
  }
  return 0;
}
