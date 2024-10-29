#include <stdio.h>

int lucas(int number);

int main() {
  int index_position = 0;
  /*for (;;) {*/
  printf("Enter index position: ");
  scanf(" %d", &index_position);
  if (index_position < 0) {
    printf("Entered position must be a non-negative integer\n");
  } else {
    int lucas_number = lucas(index_position);
    printf("lucas(%d) = %d", index_position, lucas_number);
    /*}*/
  }
  // Read input, validate input, calculate Lucas number and print the result

  return 0;
}

int lucas(int number) {
  // Implement Lucas number recursively
  if (number == 0) {
    return 2;
  } else if (number == 1) {
    return 1;
  } else {
    return lucas(number - 1) + lucas(number - 2);
  }
}
