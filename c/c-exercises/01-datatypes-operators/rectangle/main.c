#include <stdio.h>

int main(void) {
  // Prompt user for
  // Lenge Breite

  // Why to use unsigned int?
  // NOTE: Unsigned bedeutet ausschliesslich positive zahlen! Inklusiv 0
  unsigned int uint_lenght = 0;
  printf("Insert length: ");
  scanf("%d", &uint_lenght);

  unsigned int uint_width = 0;
  printf("Insert width: ");
  scanf("%d", &uint_width);

  unsigned int var_Area = uint_lenght * uint_width;
  unsigned int var_Perimeter = (uint_width * 2) + (uint_lenght * 2);
  // This is a integere division, thus l and w are both integers
  // NOTE: Aspact Ratio ist grundsaetzlich laenge / breite, da aber bei der
  // Integer division das Ergebnis ungenau waehre muessen wir zuerst sowohl
  // laenge, als auch Breite in eine float casten.
  float float_lenght = uint_lenght;
  float float_width = uint_width;

  // TODO: Cast int into Float
  float var_Aspectratio = float_lenght / float_width;

  // Output
  printf("Area: %d\n", var_Area);
  printf("Perimeter: %d\n", var_Perimeter);
  printf("Aspect ratio: %.2f\n", var_Aspectratio);
}
