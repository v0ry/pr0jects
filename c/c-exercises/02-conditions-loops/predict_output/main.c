#include <stdio.h>

int main(void)
{
  unsigned char aleks_cows = 250;
  unsigned char david_cows = -1;
  short michael_cows = -2;

  while(david_cows > 0 && david_cows > aleks_cows)
  {
    if(++michael_cows)
    {
      printf("David has %d cows, Michael has %d cows\n", david_cows, michael_cows);
    }
    david_cows--;
  }
  return 0;
}
