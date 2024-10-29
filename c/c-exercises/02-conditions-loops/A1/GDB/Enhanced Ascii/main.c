#include <stdio.h>

int main(void) {
  int count = 1;
  for (;;) {
    printf("Round %d:\n", count);

    char character;
    printf("Insert character: ");
    scanf(" %c", &character);
    if ((character >= 'A' && character <= 'Z') ||
        (character >= 'a' && character <= 'z')) {
      printf("Number: %d\n", character);
      printf("ASCII character: %c\n", character);
    } else {
      printf("[ERROR] not a valid character [A-Z] or [a-z]\n");
    }
    if (character == 'q' || character == 'Q') {
      printf("GOODBYE\n");
      return 0;
    }
    count++;
    // NOTE: The same as count = count + 1;
  }
  return 0;
}
