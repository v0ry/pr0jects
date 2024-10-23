#include <stdio.h>

int main(void) {
  // NOTE: If initialice weight, without assigning a value to it, does it
  // default to = 0? No, matter of facts you'll get a warning... Because it is
  // not initialiced
  int weight = 100;
  printf("Bitte geben Sie Ihr Gewicht in kg ein: %d\n", weight);
  /*scanf("%d", &weight);*/

  float hight = 1.8;
  printf("Bitte geben Sie Ihre Körpergröße in cm ein: %f\n", hight);
  /* scanf("%d", &hight); */

  // Calculate BMI without <math.h> library. Thus it's ^2 which is the same as
  // *2...

  // cast hight into a double
  float BMI = ((weight) / ((hight) * 2));
  // %LF for Long double, although literature says it's %lf...
  printf("%f\nKategorie: ", BMI);

  // Not that i particulary like switch cases but how could I do this with
  // switch cases?
  if (BMI < 16.0) {
    printf("Starkes Untergewicht\n");
  } else if ((BMI <= 17.0) && (BMI >= 16.0)) {
    printf("Maessiges Untergewicht\n");
  } else if ((BMI <= 18.5) && (BMI >= 17.0)) {
    printf("Leichtes Untergewicht\n");
  } else if ((BMI <= 25.0) && (BMI >= 18.5)) {
    printf("Normalgewicht\n");
  } else if ((BMI <= 30.0) && (BMI >= 25.0)) {
    printf("Präadipositas\n");
  } else if ((BMI <= 35.0) && (BMI >= 30.0)) {
    printf("Adipositas Grad I\n");
  } else if ((BMI <= 40.0) && (BMI >= 35.0)) {
    printf("Adipositas Grad II\n");
  } else if (BMI >= 40.0) {
    printf("Adipositas Grad III\n");
  }
  return 0;
}
