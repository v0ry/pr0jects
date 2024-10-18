#include <stdio.h>
#include <string.h>

int readInput(char* input);
int checkFormat(char* input);
int isRoman(char letter);
int convertToInt(char* input);
int parseSequence(char* input, size_t* position, const char ONE, const char FIVE, const char TEN);

int main(void)
{
  char input[32];
  while (!readInput(input) || !checkFormat(input) || !convertToInt(input));

  return 0;
}

int readInput(char* input)
{
  printf("Enter roman number: ");
  fgets(input, 32, stdin);

  for (size_t i = 0; input[i]; i++)
  {
    if (input[i] == '\n')
    {
      input[i] = 0;
      return 1;
    }
  }

  while (getchar() != '\n');
  printf("Input too long!\n");

  return 0;
}

int checkFormat(char* input)
{
  int state = 0;

  size_t result_counter = 0;
  char result[30];

  for (size_t i = 0; input[i]; i++)
  {
    if (!isRoman(input[i]) && input[i] != ' ')
    {
      printf("No roman number could be found!\n");
      return 0;
    }

    if (state == 0 && isRoman(input[i]))
    {
      state = 1;
      result[result_counter++] = input[i];
      continue;
    }
    if (state == 1 && input[i] == ' ')
    {
      state = 2;
      continue;
    }
    if (state == 2 && isRoman(input[i]))
    {
      state = 3;
      continue;
    }

    if (state == 1)
    {
      result[result_counter++] = input[i];
    }
  }

  if (state == 3)
  {
    printf("No roman number could be found!\n");
    return 0;
  }

  result[result_counter++] = 0;
  strncpy(input, result, result_counter);
  return 1;
}

int isRoman(char letter)
{
  switch (letter)
  {
    case 'I':
    case 'V':
    case 'X':
    case 'L':
    case 'C':
    case 'D':
    case 'M':
      return 1;
    default:
      return 0;
  }

  return 0;
}

int convertToInt(char* input)
{
  int result = 0;
  size_t position = 0;

  while (input[position] == 'M')
  {
    result += 1000;
    position++;
  }

  int hundrets, tens, ones;

  if ((hundrets = parseSequence(input, &position, 'C', 'D', 'M')) == -1 ||
      (tens = parseSequence(input, &position, 'X', 'L', 'C')) == -1 ||
      (ones = parseSequence(input, &position, 'I', 'V', 'X')) == -1 ||
      (input[position] != 0))
  {
    printf("Invalid roman number!\n");
    return 0;
  }

  result += hundrets * 100 + tens * 10 + ones;
  printf("Decimal number: %d\n", result);

  return 1;
}

int parseSequence(char* input, size_t* position, const char ONE, const char FIVE, const char TEN)
{
  int result = 0;

  if (input[*position] == ONE)
  {
    if (input[*position + 1] == TEN)
    {
      *position += 2;
      return 9;
    }
    if (input[*position + 1] == FIVE)
    {
      *position += 2;
      return 4;
    }
  }
  else if (input[*position] == FIVE)
  {
    result += 5;
    (*position)++;
  }

  for (size_t counter = 1; input[*position] == ONE; counter++)
    {
      result += 1;
      (*position)++;

      if (counter > 3)
        return -1;
    }

  return result;
}
