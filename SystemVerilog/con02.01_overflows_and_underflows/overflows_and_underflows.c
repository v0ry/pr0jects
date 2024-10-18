#include <stdio.h>
#include <limits.h>

int main()
{
  printf("CHAR_BIT  : %d\n", CHAR_BIT);
  printf("CHAR_MAX  : %d\n", CHAR_MAX);
  printf("CHAR_MIN  : %d\n", CHAR_MIN);
  printf("UCHAR_MAX : %d\n", UCHAR_MAX);
  printf("INT_MAX   : %d\n", INT_MAX);
  printf("INT_MIN   : %d\n", INT_MIN);
  printf("UINT_MAX  : %u\n\n", (unsigned int) UINT_MAX);

  printf("Overflow signed vs. unsigned:\n");
  int signed_value = INT_MAX;
  printf("signed value in hex:   %#x (%d) + 1 = %#x (%d) \n", signed_value, signed_value, signed_value + 1, signed_value + 1);

  unsigned int unsigned_value = INT_MAX;
  printf("unsigned value in hex: %#x (%u) + 1 = %#x (%u) \n\n", unsigned_value, unsigned_value, unsigned_value + 1, unsigned_value + 1);

  printf("Underflow signed vs. unsigned:\n");
  signed_value = 0;
  printf("signed value in hex:   0x%x (%d) - 1 = %#x (%d) \n", signed_value, signed_value, signed_value - 1, signed_value - 1);

  unsigned_value = 0;
  printf("unsigned value in hex: 0x%x (%u) - 1 = %#x (%u) \n", unsigned_value, unsigned_value, unsigned_value - 1, unsigned_value - 1);

  return 0;
}
