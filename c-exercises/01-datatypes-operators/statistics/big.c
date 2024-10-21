#include <stdio.h>

int main(void) {
  int a = 8, b = 3, c = 76, big;
  printf("Die größte Zahl ist: ");
  big = (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
  printf("..%d\n", big);
  return 0;
}
