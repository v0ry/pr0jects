#include <stdio.h>

void bubbleSort(int array[], size_t length);
int binarySearch(int array[], size_t length, int number);

int main(void)
{
  size_t length = 0;
  printf("Length of the array: ");
  scanf("%lu", &length);

  int array[length];
  printf("Numbers:\n");
  for (size_t i = 0; i < length; i++)
  {
    scanf("%d", array + i);
  }

  bubbleSort(array, length);
  printf("Sorted Array:\n");
  for (size_t i = 0; i < length - 1; i++)
  {
    printf("%d ", array[i]);
  }
  printf("%d\n", array[length - 1]);

  int number = 0;
  printf("Enter number: ");
  while (scanf("%d", &number) != EOF)
  {
    if (binarySearch(array, length, number))
    {
      printf("%d was found.\n", number);
    }
    else
    {
      printf("%d was not found.\n", number);
    }

    printf("Enter number: ");
  }

  printf("\n");
  return 0;
}

void bubbleSort(int array[], size_t length)
{
  for (size_t counter = 0; counter < length; counter++)
  {
    for (size_t position = 0; position < length - 1 - counter; position++)
    {
      if (array[position] > array[position + 1])
      {
        int tmp = array[position];
        array[position] = array[position + 1];
        array[position + 1] = tmp;
      }
    }
  }
}

int binarySearch(int array[], size_t length, int number)
{
  if (length == 1)
  {
    return array[0] == number;
  }
  if (length == 2)
  {
    return array[0] == number || array[1] == number;
  }

  size_t half_length = (length + 1) / 2;
  if (array[half_length - 1] == number)
  {
    return 1;
  }
  if (array[half_length - 1] < number)
  {
    return binarySearch(array + half_length, length / 2, number);
  }
  else
  {
    return binarySearch(array, half_length - 1, number);
  }

  return 0;
}
