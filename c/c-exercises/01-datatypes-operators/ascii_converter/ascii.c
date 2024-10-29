#include <stdio.h>

int main(void) {
  // Einlesen des Characters
  char insert_Character = 0;
  printf("Insert character: ");
  // Alocaate Character to insert_character
  scanf("%c", &insert_Character);

  // Ausgeben Als number
  printf("Number: %d\n", insert_Character);
  // Ausgabe als ASCII Character
  printf("ASCII Character: %c\n", insert_Character);

  // Zwischen den beiden Abfragen 34x ---
  printf("----------------------------------\n");
  // Prompt user for Integer
  int insert_Integer = 0;
  printf("Insert number: ");
  scanf("%i", &insert_Integer);

  printf("Number: %d\n", insert_Integer);
  printf("ASCII Character: %c\n", insert_Integer);

  return 0;
}
