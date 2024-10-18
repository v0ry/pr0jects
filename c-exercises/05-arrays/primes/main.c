#include <stdio.h>
#include <inttypes.h>

int main(void)
{
  uint32_t array[1024] = { 0 };
  unsigned int elements = 0;
  
  while (elements < 1024)
  {
    if (scanf("%d", array + elements) == EOF)
    {
      break;
    }
    elements++;
  }

  printf("Number of primes: %u\n", countPrimes(array, elements));
  return 0;
}
