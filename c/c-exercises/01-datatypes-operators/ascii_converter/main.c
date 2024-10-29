#include <stdio.h>

int main(void) {
  char character = 0;
  // Frage nach einem Buchstaben
  printf("Insert character: ");
  // Speichern des Buchstaben & Assign der Variable
  scanf("%c", &character);

  // The number Thing
  printf("Number: %i\n", character);          /* Convert char into Number */
  printf("ASCII Character: %c\n", character); /* ASCII == Plain Text! */

  printf("----------------------------------\n");

  // The Integer Thing
  int number = 0;
  printf("Insert number: ");
  scanf("%i", &number);

  printf("Number: %i\n", number);
  printf("ASCII Character: %c\n", number);

  return 0;
}
