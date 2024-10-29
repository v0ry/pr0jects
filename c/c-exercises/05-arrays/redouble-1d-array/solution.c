#include <stdio.h>

int main(void)
{
  printf("--- Redouble Calculator ---\n");
  long number = 0;
  printf("Enter your number: ");
  scanf("%ld", &number);
  getchar();

  int len = 0;
  printf("How many times: ");
  scanf("%d", &len);
  getchar();

  long array[len];

  for(int i = 0; i < len; i++)
  {
    array[i] = number;
    number = number * 2;
  }

  for(int i = 0; i < len - 1; i++)
  {
    printf("%ld ", array[i]);
  }
  printf("%ld", array[len - 1]);
  printf("\n");

  for(int i = len - 1; i > 0; i--)
  {
    printf("%ld ", array[i]);
  }
  printf("%ld", array[0]);
  printf("\n");

  return 0;
}