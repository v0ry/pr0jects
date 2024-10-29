#include <stdio.h>

//-----------------------------------------------------------------------------
//
// Function: xgcd
//
// Computes the extended euclidean algorithm for a number of input pairs.
//
// Input args:
// size: The number of XGCDs we want to compute
// a: Array for a values
// b: Array for b values
// x: Array for x values
// y: Array for y values
// gcd: Array for gcd values
//
//-----------------------------------------------------------------------------
void xgcd(int size, int *a, int *b, int *x, int *y, int *gcd) {

}

//-----------------------------------------------------------------------------
//
// Function: input
//
// The first value from stdin is the number of input pairs. After that all
// input pairs are read and stored to arrays a and b given as parameters. At
// most of 10 values are read.
//
// Input args:
// a: Array for a values
// b: Array for b values
//
// Return value:
// The number of elements read.
//
//-----------------------------------------------------------------------------
int input(int *a, int *b) {
    int size;
    if (fscanf(stdin, "%08x\n", &size) != 1)
        return 0;

    for (int i = 0; i < 10; i++) {
        if (fscanf(stdin, "%08x\n%08x\n", a, b) != 2) {
            return size;
        }
        a++;
        b++;
    }
    return size;
}

//-----------------------------------------------------------------------------
//
// Function: output
//
// Prints all data back to stdout
//
// Input args:
// size: Number of elements to print
// a: Array for a values
// b: Array for b values
// x: Array for x values
// y: Array for y values
// gcd: Array for gcd values
//
//-----------------------------------------------------------------------------
void output(int size, int *a, int *b, int *x, int *y, int *gcd) {
    for (int i = 0; i < size; i++) {
        fprintf(stdout,
                "%08x\n%08x\n%08x\n%08x\n%08x\n",
                (unsigned int)a[i],
                (unsigned int)x[i],
                (unsigned int)b[i],
                (unsigned int)y[i],
                (unsigned int)gcd[i]
        );
    }
}

//-----------------------------------------------------------------------------
//
// Main function
//
// Reads input data (At most 10 values), calls xgcd() to compute the extended
// euclidean algorithm for all input data, and finally calls output() to return
// the data back to stdout.
//
//-----------------------------------------------------------------------------
int main(void) {
    int a[10], b[10], x[10], y[10], gcd[10];
    int size;

    return 0;
}
