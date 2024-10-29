#include <stdio.h>
#include <ctype.h>

char safeInput(void);

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

char safeInput(void)
{
  while (1)
  {
    printf("> ");

    char input = getchar();
    if (input == EOF)
    {
      return EOF;
    }
    else if (input == '\n')
    {
      printf("Invalid input!\n");
      continue;
    }

    char next_char = getchar();
    if (next_char == EOF)
    {
      return EOF;
    }
    else if (next_char == '\n')
    {
      if (tolower(input) == 'p' || tolower(input) == 'q' || 
          tolower(input) == 'r' || tolower(input) == 's')
      {
        return input;
      }

      printf("Invalid input!\n");
      continue;
    }

    while (1)
    {
      next_char = getchar();
      if (next_char == EOF)
      {
        return EOF;
      }
      else if (next_char == '\n')
      {
        printf("Invalid input!\n");
        break;
      }
    }
  }

  return EOF;
}
