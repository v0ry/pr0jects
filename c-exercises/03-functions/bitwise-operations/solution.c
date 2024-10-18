#include <stdio.h>
#include <inttypes.h>

void printNumber(uint32_t number);

int main(void)
{
  uint32_t first_number = 0;
  uint32_t second_number = 0;
  uint32_t result_number = 0;
  uint32_t carry_bit = 0;
  uint32_t overflow_detected = 0;

  printf("Insert first number:  ");
  scanf("%u", &first_number);

  printf("Insert second number: ");
  scanf("%u", &second_number);

  printf("\nBits of first number:  ");
  printNumber(first_number);

  printf("\nBits of second number: ");
  printNumber(second_number);
  printf("\n");

  for (uint32_t bit_mask = 0x1; bit_mask; bit_mask <<= 1)
  {
    uint32_t first_number_bit = first_number & bit_mask;
    uint32_t second_number_bit = second_number & bit_mask;
    uint32_t result_number_bit = first_number_bit ^ second_number_bit ^ carry_bit;
    uint32_t new_carry_bit = (first_number_bit & second_number_bit) | 
      (first_number_bit & carry_bit) | (second_number_bit & carry_bit);

    result_number |= result_number_bit;
    carry_bit = new_carry_bit << 1;

    if (new_carry_bit)
      overflow_detected = 1;
    else
      overflow_detected = 0;
  }

  printf("\nBits of result number: ");
  printNumber(result_number);

  if (overflow_detected)
  {
    printf("\nAn overflow occured!\n");
  }
  else
  {
    printf("\nDecimal value of the result number: %u\n", result_number);
  }

  return 0;
}

void printNumber(uint32_t number)
{
  for (size_t i = 32; i > 0; i--)
  {
    uint32_t bit = (number >> (i - 1)) & 0x1;
    printf("%u", bit);

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
