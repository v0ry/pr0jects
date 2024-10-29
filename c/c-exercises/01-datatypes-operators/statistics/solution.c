#include <stdio.h>

int main(void)
{
  double first_number = 0;
  double second_number = 0;
  double third_number = 0;

  printf("Insert first number: ");
  scanf("%lf", &first_number);
  
  printf("Insert second number: ");
  scanf("%lf", &second_number);

  printf("Insert third number: ");
  scanf("%lf", &third_number);

  double mean = (first_number + second_number + third_number) / 3;
  double min = first_number < second_number && first_number < third_number ? first_number :
               (second_number < third_number ? second_number : third_number);
  double max = first_number > second_number ? 
               (first_number > third_number ? first_number : third_number) :
               (second_number > third_number ? second_number : third_number);

  printf("Mean: %.2f\n", mean);
  printf("Min: %.2f\n", min);
  printf("Max: %.2f\n", max);

  return 0;
}
