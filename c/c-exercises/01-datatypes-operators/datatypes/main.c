#include <limits.h>
#include <stdio.h>

int main(void) {

  // Char
  signed char s_char_variable = 0;
  unsigned char u_char_variable = 0;
  printf("(signed) char: %d | unsigned char: %d\n", s_char_variable,
         u_char_variable);

  s_char_variable--;
  u_char_variable--;
  printf("decrementing\n");

  printf("(signed) char: %d | unsigned char: %d\n", s_char_variable,
         u_char_variable);
  printf("---------------------------------------\n");

  s_char_variable = 127;
  u_char_variable = 255;

  printf("(signed) char: %d | unsigned char: %d\n", s_char_variable,
         u_char_variable);

  printf("incrementing\n");
  s_char_variable++;
  u_char_variable++;

  printf("(signed) char: %d | unsigned char: %d\n", s_char_variable,
         u_char_variable);
  printf("---------------------------------------\n");

  // Short
  signed short s_short_variable = 0;
  unsigned short u_short_variable = 0;
  printf("(signed) short: %d | unigned short: %d\n", s_short_variable,
         u_short_variable);

  printf("decrementin\n");
  s_short_variable--;
  u_short_variable--;

  // Warum ist das ergebnis von u_short_variable dekrimentiert 65535?
  printf("(signed) short: %d | unigned short: %d\n", s_short_variable,
         u_short_variable);

  printf("sizeof\n");
  printf("Sizeof (signed) short: %lu | Sizeof unigned short: %lu\n",
         sizeof(short), sizeof(unsigned short));

  // We use %d, because SCHAR_MAX and SCHAR_MIN are constants!
  printf("Min unsigned short %d | Max unsigned short %d\n", SCHAR_MIN,
         SCHAR_MAX);
  printf("---------------------------------------\n");

  s_short_variable++;
  u_short_variable++;
  printf("increment\n");
  printf("(signed) short %d | unsigned short: %d\n", s_short_variable,
         u_short_variable);

  printf("---------------------------------------\n");
  // Gleitkommerzahlen
  float float_varialbe = 0.0;

  float_varialbe++;
  printf("incremented float variable: %f\n", float_varialbe);
  float_varialbe--;
  printf("decrement float variable: %f\n", float_varialbe);

  printf("The value of CHAR_BIT: %d\n", CHAR_BIT);
  printf("The value of SCHAR_MIN: %d\n", SCHAR_MIN);
  printf("The value of SCHAR_MAX: %d\n", SCHAR_MAX);
  printf("The value of UCHAR_MAX: %u\n", UCHAR_MAX);
  printf("The value of CHAR_MIN: %d\n", CHAR_MIN);
  printf("The value of CHAR_MAX: %d\n", CHAR_MAX);
  printf("The value of MB_LEN_MAX: %d\n", MB_LEN_MAX);
  printf("The value of SHRT_MIN: %d\n", SHRT_MIN);
  printf("The value of SHRT_MAX: %d\n", SHRT_MAX);
  printf("The value of USHRT_MAX: %u\n", USHRT_MAX);
  printf("The value of INT_MIN: %d\n", INT_MIN);
  printf("The value of INT_MAX: %d\n", INT_MAX);
  printf("The value of UINT_MAX: %u\n", UINT_MAX);
  printf("The value of LONG_MIN: %ld\n", LONG_MIN);
  printf("The value of LONG_MAX: %ld\n", LONG_MAX);
  printf("The value of ULONG_MAX: %lu\n", ULONG_MAX);
  return 0;
}
