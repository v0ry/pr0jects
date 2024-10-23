#include <stdio.h>

int main(void) {
  for (;;) {
    char character = 0;
    printf("Insert character: ");

    scanf("%c", &character);

    // Explain how this cleans the buffer?
    // Basicly goes through each char till end of line is reached.
    int unused_char;
    /*while ((unused_char = getchar()) != '\n' && unused_char != EOF) {}*/
    // This is the same as doing while(1)
    // NOTE: In a while loop:
    for (;;) {
      unused_char = getchar();
      if (unused_char == '\n' || unused_char == EOF) {
        break;
      }
    }
    if ((character >= 'A' && character <= 'Z') ||
        (character >= 'a' && character <= 'z')) {
      // NOTE: The take away message here is, that you can use %d to print out a
      // char as a number. and %c as a character... This is the same reason, why
      // we can compare the caracters above... Because in C ASCII letters are
      // represented with numerical values.

      printf("Number:       %d\n", character);
      printf("ASCII Character    %c\n", character);
    } else {
      printf("[ERROR] not a valid Character [A-Z or a-z]\n");
    }
    // NOTE: If you use character = 'q' instead of == 'q' you will assign
    // character the value of q!

    if ((character == 'Q') || (character == 'q')) {
      printf("GOODBYE\n");
      break;
    }

    // Clean buffer again, this time using the while function

    printf("----------------------");
    while ((character = getchar() != '\n' && character != EOF)) {
    }
    int number = 0;
    printf("Insert number: ");
    scanf("%d", &number);

    if (number > 30 && number < 128) {
      printf("Number:       %d\n", number);
      printf("ASCII Char:   %c\n", number);
    } else {
      printf("[ERROR] not a visible ASCII-Character\n");
    }

    printf("----------------------");
    printf("----------------------");
  }
}
