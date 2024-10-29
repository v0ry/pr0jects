#include <stdio.h>

int main(void)
{
  char input = 0;
  do
  {
    input = safeInput();
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
