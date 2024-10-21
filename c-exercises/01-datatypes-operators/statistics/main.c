#include <stdio.h>

// For debugging purposes

int main(void) {
  double first_number, second_number, third_number, mean, min, max, min2, max2;
  printf("Insert first number: ");
  scanf("%lf", &first_number);

  printf("Insert second number: ");
  scanf("%lf", &second_number);

  printf("Insert third number: ");
  scanf("%lf", &third_number);

  mean = (first_number + second_number + third_number) / 3;

  max = (first_number > second_number)
            ? ((first_number > third_number) ? first_number : third_number)
            : ((second_number > third_number) ? second_number : third_number);

  min = (first_number < second_number)
            ? ((first_number < third_number) ? first_number : third_number)
            : ((second_number < third_number) ? second_number : third_number);
  printf("Mean: %lf\n", mean);
  printf("Max: %lf\n", max);
  printf("Min: %lf\n", min);

  printf("----------------------------------------------------------\n");

  if (first_number > second_number) {
    if (first_number > third_number) {
      max2 = first_number;
    } else {
      max2 = third_number;
    }
  } else {
    if (second_number > third_number) {
      max2 = second_number;
    } else {
      max2 = third_number;
    }
  }

  if (first_number < second_number) {
    if (first_number < third_number) {
      min2 = first_number;
    } else {
      min2 = third_number;
    }
  } else {
    if (second_number < third_number) {
      min2 = second_number;
    } else {
      min2 = third_number;
    }
  }

  printf("Mean Stays the Same: %lf\n", mean);
  printf("Max: %lf\n", max2);
  printf("Min: %lf\n", min2);
}
