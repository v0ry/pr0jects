#include <stdio.h>

int main(void) {
  unsigned long one = 1234;
  printf("What's ONE: %lu \n", one);
  switch (one) {
  case 1234:
    printf("Richtig\n");
    // NOTE: Important include break, else both *case* and *default* will return
    break;
  default:
    printf("Maybe Next time\n");
  }
  return 0;
}
