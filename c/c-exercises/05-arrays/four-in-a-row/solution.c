#include <stdio.h>
#include <ctype.h>

const int ROWS = 6;
const int COLS = 7;

const char EMPTY = ' ';
const char RED = 'R';
const char YELLOW = 'Y';
const char* RED_PROMPT = "RED > ";
const char* YELLOW_PROMPT = "YELLOW > ";

const char* GAMEFIELD_ENUMERATION = "  01   02   03   04   05   06   07";
const char* GAMEFIELD_BOUNDARY = "------------------------------------";
const char* RED_DOT = "\x1b[31;1m\u2b24\x1b[0m";
const char* YELLOW_DOT = "\x1b[33;1m\u2b24\x1b[0m";
const char* COLUMN_FULL = "Column is full!";

//------------------------------------------------------------------------------
void initGamefield(char gamefield[6][7]);
void printGamefield(char gamefield[6][7]);
int insertGamefield(char gamefield[6][7], char active_player, int input);
int won(char gamefield[6][7], char active_player, char input);

char safeInput(int validChars(char));
int charsFourInARow(char input);

//------------------------------------------------------------------------------
int main(void)
{
  char active_player = YELLOW;
  char input;
  int won_return_value = 0;

  char gamefield[6][7];
  initGamefield(gamefield);

  do
  {
    active_player = active_player == RED ? YELLOW : RED;
    printGamefield(gamefield);

    do
    {
      if (active_player == RED)
        puts("REDs turn:");
      else
        puts("YELLOWs turn:");

      input = safeInput(charsFourInARow);
      if (input == 'Q' || input == 'q' || input == EOF)
      {
        return 0;
      }
      input -= '1';

    } while (!insertGamefield(gamefield, active_player, input));

  } while (!(won_return_value = won(gamefield, active_player, input)));

  printGamefield(gamefield);

  if (won_return_value == -1)
  {
    printf("Draw! Nobody won the game!\n");
  }
  else if (active_player == RED)
  {
    printf("Player RED won the game!\n");
  }
  else
  {
    printf("Player YELLOW won the game!\n");
  }

  return 0;
}

//------------------------------------------------------------------------------
void initGamefield(char gamefield[6][7])
{
  for (size_t row = 0; row < ROWS; row++)
  {
    for (size_t col = 0; col < COLS; col++)
    {
      gamefield[row][col] = EMPTY;
    }
  }
}

//------------------------------------------------------------------------------
void printGamefield(char gamefield[6][7])
{
  printf("\n%s\n", GAMEFIELD_ENUMERATION);
  puts(GAMEFIELD_BOUNDARY);

  for (size_t row = 0; row < ROWS; row++)
  {
    printf("|");

    for (size_t col = 0; col < COLS; col++)
    {
      if (gamefield[row][col] == RED)
      {
        printf(" %s  |", RED_DOT);
      }
      else if (gamefield[row][col] == YELLOW)
      {
        printf(" %s  |", YELLOW_DOT);
      }
      else
      {
        printf("    |");
      }
    }
    printf("\n%s\n", GAMEFIELD_BOUNDARY);
  }
  puts(GAMEFIELD_ENUMERATION);
}

//------------------------------------------------------------------------------
int insertGamefield(char gamefield[6][7], char active_player, int input)
{
  for (size_t row = ROWS; row > 0; row--)
  {
    if (gamefield[row - 1][input] == EMPTY)
    {
      gamefield[row - 1][input] = active_player;
      return 1;
    }
  }

  puts(COLUMN_FULL);
  return 0;
}

//------------------------------------------------------------------------------
int won(char gamefield[6][7], char active_player, char input)
{
  size_t input_row = 0;
  size_t input_col = input;

  size_t counter = 0;
  for (size_t row = 0; row < ROWS; row++)
  {
    if (gamefield[row][input_col] == EMPTY)
    {
      input_row = row + 1;
      continue;
    }
    if (gamefield[row][input_col] == active_player)
    {
      counter++;
      if (counter == 4)
      {
        return 1;
      }
    }
    else
    {
      break;
    }
  }

  counter = 0;
  for (size_t col = 0; col < COLS; col++)
  {
    if (gamefield[input_row][col] == active_player)
    {
      counter++;
      if (counter == 4)
      {
        return 1;
      }
    }
    else
    {
      counter = 0;
    }
  }

  size_t row_diag_start = input_row > input_col ? input_row - input_col : 0;
  size_t col_diag_start = input_col > input_row ? input_col - input_row : 0;

  counter = 0;
  for (size_t diag = 0; row_diag_start + diag < ROWS && col_diag_start + diag < COLS; diag++)
  {
    if (gamefield[row_diag_start + diag][col_diag_start + diag] == active_player)
    {
      counter++;
      if (counter == 4)
      {
        return 1;
      }
    }
    else
    {
      counter = 0;
    }
  }

  size_t col_from_right = COLS - 1 - input_col;
  row_diag_start = input_row > col_from_right ? input_row - col_from_right : 0;
  col_diag_start = col_from_right > input_row ? input_col + input_row : COLS - 1;

  counter = 0;
  for (size_t diag = 0; row_diag_start + diag < ROWS && col_diag_start - diag + 1 > 0; diag++)
  {
    if (gamefield[row_diag_start + diag][col_diag_start - diag] == active_player)
    {
      counter++;
      if (counter == 4)
      {
        return 1;
      }
    }
    else
    {
      counter = 0;
    }
  }

  for (size_t row = 0; row < ROWS; row++)
  {
    for (size_t col = 0; col < COLS; col++)
    {
      if (gamefield[row][col] == EMPTY)
      {
        return 0;
      }
    }
  }

  return -1;
}

//------------------------------------------------------------------------------
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

//------------------------------------------------------------------------------
int charsFourInARow(char input)
{
  if (('1' <= input && input <= '7') || tolower(input) == 'q')
  {
    return 1;
  }
  return 0;
}
