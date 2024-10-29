#include <stdio.h>

int main() {
  int lower_limit = 0;
  int upper_limit = 0;

  printf("Enter lower limit: ");
  scanf("%d", &lower_limit);

  printf("Enter upper limit: ");
  scanf("%d", &upper_limit);

  if (lower_limit >= upper_limit) {
    printf("Upper limit must be higher than lower limit\n");
    return 1;
  }

  int sum = 0;
  int count = 0;

  // Loop to find the sum of even numbers
  for (int i = lower_limit; i < upper_limit; i++) {
    if ((i % 2) == 0) {
      sum = sum + i;
      count++;
    }
  }

  // Calculate the average of the even numbers
  float average =
      (count > 0) ? sum / (float)count : 0; // Avoid division by zero
  printf("Sum of even numbers: %d\n", sum);
  printf("Average of even numbers: %f\n", average);

  return 0;
}
