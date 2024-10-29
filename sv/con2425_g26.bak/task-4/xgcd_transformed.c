#include <stdio.h>

//-----------------------------------------------------------------------------
// RISC-V Register set
size_t zero = 0;
size_t a0, a1;                      // fn args or return args
size_t a2, a3, a4, a5, a6, a7;      // fn args
size_t t0, t1, t2, t3, t4, t5, t6;  // temporaries
// Callee saved registers, must be stacked befor using it in a function!
size_t s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11;
//-----------------------------------------------------------------------------

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
void xgcd(void) {

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
// a0: Address of array for a values
// a1: Address of array for b values
//
// Return value:
// a0: The number of elements read.
//
//-----------------------------------------------------------------------------
void input(void) {
    // Read size
    t0 = a0; // Save a0
    a0 = fscanf(stdin, "%08x\n", (int*)&t1);
    t4 = 1;
    if (a0 == t4) goto input_continue;
    // Early exit
    a0 = 0;
    return;

input_continue:
    t4 = 2;
    t5 = 10;
input_loop_begin:
    if(t5 == 0) goto after_input_loop;
    a0 = fscanf(stdin, "%08x\n%08x\n", (int*)&t2, (int*)&t3);
    if(a0 == t4) goto continue_read;
    // Exit, because read was not successful
    a0 = t1;
    return;
continue_read:
    *(int*)t0 = t2;
    *(int*)a1 = t3;
    // Pointer increment for next iteration
    t0 = t0 + 4;
    a1 = a1 + 4;
    // Loop counter decrement
    t5 = t5 - 1;
    goto input_loop_begin;

after_input_loop:
    a0 = t1;
    return;
}

//-----------------------------------------------------------------------------
//
// Function: output
//
// Prints all data back to stdout
//
// Input args:
// a0: Number of elements to print
// a1: Addres of array for a values
// a2: Addres of array for b values
// a3: Addres of array for x values
// a4: Addres of array for y values
// a5: Addres of array for gcd values
//
//-----------------------------------------------------------------------------
void output(void) {
before_output_loop:
    if (a0 == 0) goto after_output_loop;

    fprintf(stdout,
            "%08x\n%08x\n%08x\n%08x\n%08x\n",
            (unsigned int)*(int*)a1,
            (unsigned int)*(int*)a3,
            (unsigned int)*(int*)a2,
            (unsigned int)*(int*)a4,
            (unsigned int)*(int*)a5
    );

    // Pointer increment for next iteration
    a1 = a1 + 4;
    a2 = a2 + 4;
    a3 = a3 + 4;
    a4 = a4 + 4;
    a5 = a5 + 4;
    // Decrement loop counter
    a0 = a0 - 1;
    goto before_output_loop;

after_output_loop:
    return;
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
