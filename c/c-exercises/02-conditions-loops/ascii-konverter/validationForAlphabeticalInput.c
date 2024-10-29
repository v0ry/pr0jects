#include <stdio.h>

int main(void) {
  char input = 0;
  printf("Enter a character: ");
  // NOTE: This works, because the input is read as a character Thus f returns
  // 102... and so on
  scanf("%c", &input);

  if ((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z')) {
    printf("Valid input\n");
  } else {
    printf("Invalid input\n");
  }
}
