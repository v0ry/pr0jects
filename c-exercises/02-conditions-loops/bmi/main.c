#include <stdio.h>

int main(void) {
  // NOTE: If initialice weight, without assigning a value to it, does it
  // default to = 0? No, matter of facts you'll get a warning... Because it is
  // not initialiced
  int weight = 100;
  printf("Bitte geben Sie Ihr Gewicht in kg ein: %d\n", weight);
  /*scanf("%d", &weight);*/

  int hight = 180;
  printf("Bitte geben Sie Ihre Körpergröße in cm ein: %d\n", hight);
  /* scanf("%d", &hight); */

  // Calculate BMI without <math.h> library. Thus it's ^2 which is the same as
  // *2...

  // cast hight into a double
  // Why does this not work?
  /*double bmi = ((weight) / (hight * hight / 1000.0));*/

  double bmi = weight / (hight / 100. * hight / 100.);
  // %LF for Long double, although literature says it's %lf...
  printf("BMI: %.1f\n", bmi);

  // Not that i particulary like switch cases but how could I do this with
  // switch cases?
  if (bmi < 16.0)
    printf("Kategorie: Starkes Untergewicht\n");
  else if (bmi < 17.0)
    printf("Kategorie: Mäßiges Untergewicht\n");
  else if (bmi < 18.5)
    printf("Kategorie: Leichtes Untergewicht\n");
  else if (bmi < 25.0)
    printf("Kategorie: Normalgewicht\n");
  else if (bmi < 30.0)
    printf("Kategorie: Präadipositas\n");
  else if (bmi < 35.0)
    printf("Kategorie: Adipositas Grad I\n");
  else if (bmi < 40.0)
    printf("Kategorie: Adipositas Grad II\n");
  else
    printf("Kategorie: Adipositas Grad III\n");
  return 0;
}
