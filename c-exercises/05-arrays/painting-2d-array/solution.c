#include <stdio.h>

#define MAX_WIDTH 70
#define ASCII_SPACE 32

void printFrame()
{
  for(int width_counter = 0; width_counter < MAX_WIDTH + 2; width_counter++)
  {
    printf("-");
  }
  printf("\n");
}

void printPainting(char picture[][MAX_WIDTH], int height)
{
  printFrame();
  for(int line_counter = 0; line_counter < height; line_counter++)
  {
    printf("|");
    for(int char_counter = MAX_WIDTH - 1; char_counter >= 0 ; char_counter--)
    {
      printf("%c", picture[line_counter][char_counter]);
    }
    printf("|\n");
  }
  printFrame();
}

int main(void)
{
  printf("--- Painting Calculator (max-width %d) ---\n", MAX_WIDTH);
  int nr_lines = 0;
  printf("How many lines do you need? ");
  scanf("%d", &nr_lines);
  getchar();

  char picture[nr_lines][MAX_WIDTH];

  for(int line_counter = 0; line_counter < nr_lines; line_counter++)
  {
    for (int counter = 0; counter < MAX_WIDTH; counter++)
    {
      picture[line_counter][counter] = ASCII_SPACE; // set it all to space for printing
    }
  }

  char input_letter;
  for(int line_counter = 0; line_counter < nr_lines; line_counter++)
  {
    for (int counter = 0; (input_letter = getchar()) != '\n' && counter < MAX_WIDTH; counter++)
    {
      picture[line_counter][counter] = input_letter;
    }
  }

  printPainting(picture, nr_lines);
  return 0;
}
