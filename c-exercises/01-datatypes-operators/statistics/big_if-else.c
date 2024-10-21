#include <stdio.h>

int main(void) {
  int a = 8, b = 3, c = 76, big;

  if (a > b) {
    if (a > c) {
      big = a;
    } else {
      big = c;
    }
  } else {
    if (b > c) {
      big = b;
    } else {
      big = a;
    }
  }

  printf("..%d\n", big);
}
