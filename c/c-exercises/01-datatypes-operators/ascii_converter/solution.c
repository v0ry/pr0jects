#include <stdio.h>

int main(void)
{
  char character = 0;
  printf("Insert character: ");
  scanf("%c", &character);

  printf("Number:           %d\n", character);
  printf("ASCII Character:  %c\n", character);

  printf("----------------------------------\n");
  int number = 0;
  printf("Insert number: ");
  scanf("%d", &number);

  printf("Number:          %d\n", number);
  printf("ASCII Character: %c\n", number);

  return 0;
}
