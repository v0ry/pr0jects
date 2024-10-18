#include <stdio.h>

int invertByValue(int number) // Call by value
{
  return number * -1;
}

void invertByRef(int* number) // call by reference
{
  *number = *number * -1;
}

void swapNumbers(int* number1, int* number2)
{
  int tmp = *number1;
  *number1 = *number2;
  *number2 = tmp;
}

void editReferences(int* number1, int* number2)
{
  *number1 = *number1 * -1;
  *number2 = *number2 / *number1;
}

int main(void)
{
  // PART 1: Call-by-value / call-by-reference difference
  int inverting_number = 0;

  printf("PART 1\nEnter a Number you want to convert: ");
  scanf("%d", &inverting_number);
  getchar();

  // 1. call by value
  int inverted_number_by_value = invertByValue(inverting_number);

  // 2. call by reference
  invertByRef(&inverting_number);

  printf("Number inverted by value:     %d\n", inverted_number_by_value);
  printf("Number inverted by reference: %d\n", inverting_number);
  printf("-----------------------------------\n");
  //------------------------------------------------------------------------------------
  // PART 2: swapNumbers() function

  int michael_cows = 0;
  int david_cows = 0;
  printf("PART 2\nHow many cows does Michael have? ");
  scanf("%d", &michael_cows);
  getchar();

  printf("How many cows does David have? ");
  scanf("%d", &david_cows);
  getchar();

  printf("You entered:\n   Michael %d    David %d\n", michael_cows, david_cows);
  printf("------ lets swap the numbers ------\n");

  // call here your swapNumbers() function
  swapNumbers(&michael_cows, &david_cows);

  printf("After swapping:\n   Michael %d    David %d\n", michael_cows, david_cows);
  printf("-----------------------------------\n");
  //------------------------------------------------------------------------------------
  // PART 3: editReferences() function
  int alex_shoesize = -44;
  int david_age = 1100;

  // call here editReferences() function
  editReferences(&alex_shoesize, &david_age);

  printf("PART3\nAlex shoe size %d (desired 44)\nDavid is %d years old (desired 25)\n", alex_shoesize, david_age);
  return 0;
}
