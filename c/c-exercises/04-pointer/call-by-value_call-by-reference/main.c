#include <stdio.h>

int main(void)
{
  // PART 1: Call-by-value / call-by-reference difference
  int inverting_number = 0;

  printf("Enter a Number you want to convert: ");
  scanf("%d", &inverting_number);
  getchar();

  // todo: call here 2x invert function
  // 1. call by value

  // 2. call by reference


  printf("Number inverted: %d\n", inverting_number);
  printf("-----------------------------------\n");
  //------------------------------------------------------------------------------------
  // PART 2: swapNumbers() function

  int michael_cows = 0;
  int david_cows = 0;
  printf("How many cows does Michael have? ");
  scanf("%d", &michael_cows);
  getchar();

  printf("How many cows does David have? ");
  scanf("%d", &david_cows);
  getchar();

  printf("You entered:\n   Michael %d    David %d\n", michael_cows, david_cows);
  printf("--------------------- lets swap the numbers ----------------------\n");

  // TODO: call here your swapNumbers() function

  printf("After swapping:\n   Michael %d    David %d\n", michael_cows, david_cows);
printf("-----------------------------------\n");
  //------------------------------------------------------------------------------------
  // PART 3: editReferences() function
  int alex_shoesize = -44;
  int david_age = 1100;

  // TODO: call here editReferences() function

  printf("PART3\nAlex shoe size %d (desired 44)\nDavid is %d years old (desired 25)\n", alex_shoesize, david_age);

  return 0;
}
