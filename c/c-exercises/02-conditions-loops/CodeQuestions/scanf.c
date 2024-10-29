#include <stdio.h>

int main(void) {
  unsigned one = 1234;
  unsigned input = 0;
  printf("What's ONE: ");
  scanf("%ul", &input);
  input == one ? printf("Correct\n") : printf("False\n");
  return 0;
}
