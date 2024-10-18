#include <stdio.h>
#include <ctype.h>

char safeInput(int validChars(char));
int charsRockPaperScissors(char input);
int charsFourInARow(char input);

int main(void)
{
  char input = 0;

  puts("Tests for Rock-Paper-Scissors!");
  do
  {
    // TODO: Call the modified safeInput function
    input = safeInput(charsRockPaperScissors);
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
    // TODO: Call the modified safeInput function
    input = safeInput(&charsFourInARow);
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

char safeInput(int validChars(char))
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
      if (validChars(input))
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

int charsRockPaperScissors(char input)
{
  if (tolower(input) == 'p' || tolower(input) == 'q' || 
      tolower(input) == 'r' || tolower(input) == 's')
  {
    return 1;
  }
  return 0;
}

int charsFourInARow(char input)
{
  if (('1' <= input && input <= '7') || tolower(input) == 'q')
  {
    return 1;
  }
  return 0;
}
