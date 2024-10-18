#include <stdio.h>

int main(void)
{
  char input = 0;

  puts("Tests for Rock-Paper-Scissors!");
  do
  {
    // TODO: Call the modified safeInput with rock paper scissors inputs

    if (input == EOF)
    {
      printf("\nYour input was: EOF\n");
    }
    else
    {
      printf("Your input was: %c\n", input);
    }
  } while (input != 'Q' && input != 'q' && input != EOF);

  puts("Tests for Four-in-a-Row!");
  do
  {
    // TODO: Call the modified safeInput with four in a row inputs

    if (input == EOF)
    {
      printf("\nYour input was: EOF\n");
    }
    else
    {
      printf("Your input was: %c\n", input);
    }
  } while (input != 'Q' && input != 'q' && input != EOF);

  return 0;
}
