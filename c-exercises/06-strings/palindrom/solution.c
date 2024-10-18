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

int isPalindrome(char string[100])
{
  size_t length;
  for (length = 0; string[length]; length++);

  if (length == 0)
    return 0;
  if(length == 1)
    return 1;

  // we copy the "tolower" string inside this string - we don't want to modify the original
  char tmp_string[100]; 

  for(size_t front_it = 0, back_it = length - 1; front_it < length; front_it++, back_it--)
  {
    tmp_string[front_it] = tolower(string[front_it]);
    tmp_string[back_it] = tolower(string[back_it]);

    if(tmp_string[front_it] != tmp_string[back_it])
    {
      break;
    }
    if(front_it >= back_it)
    {
      return 1;
    }
  }
  return 0;
}
