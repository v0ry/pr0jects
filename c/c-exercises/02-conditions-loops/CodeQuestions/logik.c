#include <stdio.h>

char one = 42;
char two = 1;
int main(void) {
  if (one & two) {
    printf("if\n");
  } else {
    printf("else\n");
  }
  return 0;
}
