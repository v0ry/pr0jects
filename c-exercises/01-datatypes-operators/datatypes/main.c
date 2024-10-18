#include <stdio.h>

int main(void)
{

  signed char s_char_variable = 0;
  unsigned char u_char_variable = 0;
  printf("(signed) char: %d | unsigned char: %d\n", s_char_variable, u_char_variable);

  s_char_variable--;
  u_char_variable--;
  printf("decrementing\n");

  printf("(signed) char: %d | unsigned char: %d\n", s_char_variable, u_char_variable);
  printf("---------------------------------------\n");

  s_char_variable = 127;
  u_char_variable = 255;

  printf("(signed) char: %d | unsigned char: %d\n", s_char_variable, u_char_variable);

  printf("incrementing\n");
  s_char_variable++;
  u_char_variable++;

  printf("(signed) char: %d | unsigned char: %d\n", s_char_variable, u_char_variable);
  return 0;
}
