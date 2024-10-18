#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int startRound(void);
char safeInput(void);
char computerInput(void);
int calculateResult(char player_input, char computer_input);

int main(void)
{
  puts("Welcome to Rock-Paper-Scissors!");
  puts("Options: Rock (R,r), Paper (P,p), Scissors (S,s), Quit (Q,q)");

  int rounds_player = 0;
  int rounds_computer = 0;
  int round_counter = 1;

  srand(time(NULL));

  do
  {
    printf("\nRound %d: You: %d vs. Computer: %d\n", round_counter, rounds_player, rounds_computer);

    int outcome = startRound();
    if (outcome == 1)
    {
      rounds_player++;
    }
    else if (outcome == 2)
    {
      rounds_computer++;
    }
    else if (outcome == 3)
    {
      return 0;
    }

    round_counter++;
  } while (rounds_player < 3 && rounds_computer < 3);

  printf("\nResults: You: %d vs. Computer: %d\n", rounds_player, rounds_computer);
  if (rounds_player == 3)
  {
    puts("Congratulations! You won!");
  }
  else
  {
    puts("You lost! Better luck next time!");
  }

  return 0;
}

int startRound(void)
{
  char player_input = toupper(safeInput());
  if (player_input == EOF || player_input == 'Q')
  {
    return 3;
  }

  char computer_input = computerInput();
  return calculateResult(player_input, computer_input);
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

char computerInput(void)
{
  char computer_input;
  switch (rand() % 3)
  {
    case 0:
      computer_input = 'S';
      break;
    case 1:
      computer_input = 'R';
      break;
    case 2:
      computer_input = 'P';
      break;
  }

  printf("Computer: %c\n", computer_input);
  return computer_input;
}

int calculateResult(char player_input, char computer_input)
{
  if (player_input == computer_input)
  {
    printf("Draw!\n");
    return 0;
  }
  if ((player_input == 'S' && computer_input == 'P') ||
      (player_input == 'P' && computer_input == 'R') ||
      (player_input == 'R' && computer_input == 'S'))
  {
    printf("You won!\n");
    return 1;
  }

  printf("You lost!\n");
  return 2;
}
