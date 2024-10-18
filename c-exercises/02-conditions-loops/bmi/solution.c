#include <stdio.h>

int main(void)
{
  int height = 0;
  int weight = 0;

  printf("Bitte geben Sie Ihr Gewicht in kg ein:\n");
  scanf("%d", &weight);

  printf("Bitte geben Sie Ihre Körpergröße in cm ein:\n");
  scanf("%d", &height);

  double bmi = weight / (height / 100. * height / 100.);
  printf("BMI: %.1lf\n", bmi);

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
