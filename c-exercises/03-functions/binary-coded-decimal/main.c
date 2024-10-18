#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    printf("Usage: %s number\n", argv[1]);
    return 1;
  }

  unsigned long number = strtoul(argv[1], NULL, 10);
  if (number < 1 || number >= UINT_MAX)
  {
    printf("Number out of range: allowed range is %u\n", UINT_MAX);
    return 2;
  }

  // TODO...

  return 0;
}
