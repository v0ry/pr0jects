#include <stdio.h>
#include <limits.h> // limits is needed for INT_MIN and INT_MAX

int main(int agrc, char* argv[]) 
{ 

	// Explain why %lu and not %d?
	// And why %d for INT_MIN and INT_MAX?
	printf("Size of a byte: %lu\n", sizeof(int));
	printf("Wertebereich von %d bis %d", INT_MIN, INT_MAX );
    return 0;
}


