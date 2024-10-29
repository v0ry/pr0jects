#include <stdio.h>

int main(void)
{
  char input_letter = 0;
  char string[100];

  printf("String: ");
  size_t counter;
  for (counter = 0; (input_letter = getchar()) != '\n'; counter++)
  {
    string[counter] = input_letter;
  }
  string[counter] = 0;

  int start_key = 0;
  printf("Key: ");
  scanf("%d", &start_key);

  unsigned int encrypted_chars = cipher(string, start_key);
  printf("Cipher text: %s\n", string);
  printf("Encrypted chars: %u\n", encrypted_chars);

  return 0;
}
