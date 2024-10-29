#include <stdio.h>
#include <inttypes.h>
#include <math.h>

unsigned int countPrimes(uint32_t element_list[], unsigned int elements);
int isPrime(uint32_t number);

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

unsigned int countPrimes(uint32_t element_list[], unsigned int elements)
{
  unsigned int counter = 0;

  for (size_t pos = 0; pos < elements; pos++)
  {
    counter += isPrime(element_list[pos]);
  }

  return counter;
}

int isPrime(uint32_t number)
{
  if (number < 2)
    return 0;
  if (number == 2)
    return 1;
  if (number % 2 == 0)
    return 0;

  uint32_t upper_boundary = sqrt(number);
  for (size_t divisor = 3; divisor <= upper_boundary; divisor += 2)
  {
    if (number % divisor == 0)
    {
      return 0;
    }
  }

  return 1;
}
