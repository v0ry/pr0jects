#include <stdio.h>

int main(void) {

  while (1) {
    char character = 0;
    printf("Insert character: ");

    scanf("%c", &character);

    // this clears all remaining chars in the input buffer
    int unused_char;
    while ((unused_char = getchar()) != '\n' && unused_char != EOF) {
    }

    if ((character >= 'A' && character <= 'Z') ||
        (character >= 'a' && character <= 'z')) {
      printf("Number:           %d\n", character);
      printf("ASCII Character:  %c\n", character);
    } else {
      printf("[ERROR] not a valid Character [A-Z or a-z]\n");
    }

    if (character == 'Q' || character == 'q') {
      printf("GOODBYE\n");
      return 0;
    }
    printf("----------------------------------\n");

    int number = 0;
    printf("Insert number: ");
    scanf("%d", &number);

    // this clears all remaining chars in the input buffer
    while ((unused_char = getchar()) != '\n' && unused_char != EOF) {
    }

    if ((number >= 32 && number <= 126)) {
      printf("Number:           %d\n", number);
      printf("ASCII Character:  %c\n", number);
    } else {
      printf("[ERROR] not a visible ASCII-Character\n");
    }
    printf("----------------------------------\n");
    printf("----------------------------------\n");
  }
  return 0;
}
