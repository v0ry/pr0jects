#include <stdio.h>
#include <inttypes.h>


int add(int number1, int number2)
{
  return number1 + number2;
}

int min(int number1, int number2)
{
  if(number1 < number2)
  {
    return number1;
  }
  return number2;
}

int max(int number1, int number2)
{
  return number1 > number2 ? number1 : number2;
}

int abs(int number)
{
  if(number < 0)
  {
    return number * -1;
  }
  return number;
}

float mean(int number1, int number2)
{
  return (number1 + number2) / (float)2;
}


int main(void)
{

  int x,y;
  printf("First number: ");
  scanf("%d", &x);
  getchar();

  printf("Second number: ");
  scanf("%d", &y);


  printf("Addition of %d and %d is %d\n", x,y, add(x,y));
  printf("Min      of %d and %d is %d\n", x,y, min(x,y));
  printf("Max      of %d and %d is %d\n", x,y, max(x,y));
  printf("Absolute of %d is %d\n",x, abs(x));
  printf("Absolute of %d is %d\n",y, abs(y));
  printf("Mean     of %d and %d is %f\n", x,y, mean(x,y));

  return 0;
}
