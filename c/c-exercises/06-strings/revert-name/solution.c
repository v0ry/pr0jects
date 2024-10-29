#include <stdio.h>
#include <ctype.h>

int reversePrint(char* name);

int main(void)
{
  char input_letter = 0;
  char string[100];

  size_t counter;
  for (counter = 0; (input_letter = getchar()) != '\n'; counter++)
  {
    string[counter] = input_letter;
  }
  string[counter] = 0;

  return reversePrint(string);
}

int reversePrint(char* name)
{
  size_t length;
  for (length = 0; name[length]; length++);

  if (length == 0)
    return 1;
  
  size_t front_cursor = 0;
  for (size_t rear_cursor = 0; rear_cursor <= length; rear_cursor++)
  {
    if (name[rear_cursor] == ' ' || name[rear_cursor] == 0)
    {
      if (front_cursor == 0 && rear_cursor == length)
      {
        return 2;
      }

      char safe_char = name[rear_cursor - 1];
      name[rear_cursor - 1] = tolower(name[front_cursor]);
      name[front_cursor] = toupper(safe_char);

      for (size_t front_char = front_cursor + 1; front_char < (front_cursor + rear_cursor) / 2; front_char++)
      {
        size_t back_char = (rear_cursor - 1) + (front_cursor - front_char);

        char safe_char = name[back_char];
        name[back_char] = name[front_char];
        name[front_char] = safe_char;
      }

      front_cursor = rear_cursor + 1;
    }
  }

  printf("%s\n", name);

  return 0;
}
