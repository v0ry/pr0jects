#include <stdio.h>

unsigned int cipher(char* cipher_str, int start_key);
char cipherChar(char letter, int key);
int calculateKey(char letter, int current_key, int start_key);

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

unsigned int cipher(char* cipher_str, int start_key)
{
  int current_key = start_key;
  size_t counter = 0;

  for (size_t i = 0; cipher_str[i]; i++)
  {
    if (('A' <= cipher_str[i] && cipher_str[i] <= 'Z') || 
        ('a' <= cipher_str[i] && cipher_str[i] <= 'z'))
    {
      char encrypted_char = cipherChar(cipher_str[i], current_key);
      current_key = calculateKey(cipher_str[i], current_key, start_key);
      cipher_str[i] = encrypted_char;
      counter++;
    }
  }

  return counter;
}

char cipherChar(char letter, int key)
{
  char addition = letter < 'a' ? 'A' : 'a';
  letter = (letter - addition + (key % 2 ? -key : key)) % 26;
  if (letter < 0)
    letter += 26;
  return letter + addition;
}

int calculateKey(char letter, int current_key, int start_key)
{
  if (current_key == 0)
    return start_key;
  return ((letter < 'a' ? letter - 'A' : letter - 'a') + 1) % current_key;
}
