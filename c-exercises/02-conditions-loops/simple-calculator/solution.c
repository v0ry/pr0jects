#include <stdio.h>
#include <math.h>

int main(void)
{
  char operation = 0;
  float first_number = 0;
  float second_number = 0;
  float result = 0;

  printf("First number: ");
  scanf("%f", &first_number);
  getchar();

  printf("Operation: ");
  scanf("%c", &operation);
  getchar();

  printf("Second number: ");
  scanf("%f", &second_number);

  switch (operation)
  {
    case '+':
      result = first_number + second_number;
      break;
    case '-':
      result = first_number - second_number;
      break;
    case '*':
      result = first_number * second_number;
      break;
    case '/':
      if (-0.0001 < second_number && second_number < 0.0001)
      {
        puts("Division through 0 not allowed!");
        return 1;
      }
      result = first_number / second_number;
      break;
    case 'p':
      if (first_number < 0 || second_number < 0)
      {
        puts("Base and exponent have to be at least 0!");
        return 1;
      }
      result = pow(first_number, second_number);
      break;
    case 's':
      if (first_number < 0)
      {
        puts("Square root only defined for numbers at least 0!");
        return 1;
      }
      result = sqrtf(first_number);
      break;
    case 'e':
      result = expf(first_number);
      break;
    default:
      puts("Invalid operation!");
      return 1;
  }

  printf("Result: %.2f\n", result);
  return 0;
}
