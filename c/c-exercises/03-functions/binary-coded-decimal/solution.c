#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

unsigned long convertBinaryToBCD(unsigned long number);
unsigned long convertBCDToBinary(unsigned long number);
void print(unsigned long number, unsigned long bcd, unsigned long binary);
void printBits(unsigned long number);

int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    printf("Usage: %s number\n", argv[0]);
    return 1;
  }

  unsigned long number = strtoul(argv[1], NULL, 10);
  if (number < 1 || number >= UINT_MAX)
  {
    printf("Number out of range: allowed range is %u\n", UINT_MAX - 1);
    return 2;
  }

  unsigned long bcd = convertBinaryToBCD(number);
  unsigned long binary = bcd != UINT_MAX ? convertBCDToBinary(bcd) : UINT_MAX;
  print(number, bcd, binary);

  return 0;
}

unsigned long convertBinaryToBCD(unsigned long number)
{
  unsigned long bcd = 0;

  for (size_t nibble = 0; nibble < 8; nibble++)
  {
    unsigned long decimal = number % 10;
    number = (number - decimal) / 10;

    bcd |= decimal << (nibble * 4);
  }

  if (number > 0)
    return UINT_MAX;

  return bcd;
}

unsigned long convertBCDToBinary(unsigned long number)
{
  unsigned long binary = 0;
  unsigned long factor = 1;

  for (size_t nibble = 0; nibble < 8; nibble++)
  {
    unsigned long decimal = (number >> (nibble * 4)) & 0xf;
    if (decimal > 9)
      return UINT_MAX;

    binary += decimal * factor;
    factor *= 10;
  }

  return binary;
}

void print(unsigned long number, unsigned long bcd, unsigned long binary)
{
  printf(" Input: %10lu - ", number);
  printBits(number);

  if (bcd != UINT_MAX)
  {
    printf("\n   BCD: %10lu - ", bcd);
    printBits(bcd);
  }
  else
  {
    printf("\n   BCD: Binary Code too large.");
  }
  
  if (binary != UINT_MAX)
  {
    printf("\nBinary: %10lu - ", binary);
    printBits(binary);
  }
  else
  {
    printf("\nBinary: Binary Code too large.");
  }
  printf("\n");
}

void printBits(unsigned long number)
{
  for (size_t i = 32; i > 0; i--)
  {
    unsigned long bit = (number >> (i - 1)) & 0x1;
    printf("%lu", bit);

    if (i % 4 == 1 && i > 1)
    {
      printf(" ");
    }
    if (i % 8 == 1 && i > 1)
    {
      printf("| ");
    }
  }
}
