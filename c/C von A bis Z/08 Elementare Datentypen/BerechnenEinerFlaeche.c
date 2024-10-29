#include <stdio.h>

int main(int agrc, char* argv[]) 
{ 
    
	float l, b; // Declare two variables

	printf("Berechnen einer Flaeche\n");
	printf("Flaeche Laenge\n: ");
	scanf("%f", &l);

	printf("Flaeche Breite\n: ");
	scanf("%f", &b);

	printf("Das Rechteck: %f\n", l * b);
    return 0;
}


