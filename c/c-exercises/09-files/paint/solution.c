#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef enum
{
  BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE, QUIT, NONE
} Color;

char* COMMANDS[] = { "black", "red", "green", "yellow", "blue", 
                     "magenta", "cyan", "white", "quit" };
char* COLORS[] = { "\x1b[30m", "\x1b[31m", "\x1b[32m", "\x1b[33m", "\x1b[34m", 
                   "\x1b[35m", "\x1b[36m", "\x1b[37m" };
int RGB_COLORS[][3] = { {0, 0, 0}, {255, 0, 0}, {0, 255, 0}, {255, 255, 0}, 
                  {0, 0, 255}, {255, 0, 255}, {0, 255, 255}, {255, 255, 255}};

size_t inputSize(char* size_type);
Color** allocateMemory(size_t height, size_t width);
void freeMemory(Color** field, size_t height);
void printField(Color** field, size_t height, size_t width);
Color parseInput(char* input);
void storeToFile(Color** field, size_t height, size_t width);
void printPixelToFile(FILE* file, Color pixel);

int main(void)
{
  size_t height = inputSize("height");
  size_t width = inputSize("width");

  Color** field = allocateMemory(height, width);
  if (!field)
  {
    printf("Out of memory!\n");
    return 1;
  }

  while (1)
  {
    printField(field, height, width);

    Color input_color = NONE;
    size_t row;
    size_t col;

    while (1)
    {
      char input[50];
      printf(" > ");
      fgets(input, 50, stdin);

      char* command_ptr = strtok(input, " \n");
      if (command_ptr == NULL)
      {
        continue;
      }
      for (size_t pos = 0; input[pos]; pos++)
      {
        input[pos] = tolower(input[pos]);
      }
      input_color = parseInput(command_ptr);

      if (input_color == NONE)
      {
        printf("Invalid input!\n");
        continue;
      }
      if (input_color == QUIT)
      {
        break;
      }

      char* row_ptr = strtok(NULL, " \n");
      char* col_ptr = strtok(NULL, " \n");
      if (!row_ptr  || !col_ptr || 
          strlen(row_ptr) != 1 || strlen(col_ptr) != 1) 
      {
        printf("Invalid input!\n");
        continue;
      }

      row = *row_ptr - '0';
      col = *col_ptr - '0';
      if (row >= height || col >= width || strtok(NULL, " \n") != NULL)
      {
        printf("Invalid input!\n");
        continue;
      }
      break;
    }

    if (input_color == QUIT)
    {
      break;
    }
    field[row][col] = input_color;
  }

  storeToFile(field, height, width);
  freeMemory(field, height);
  return 0;
}

size_t inputSize(char* size_type)
{
  size_t size = 0;

  do
  {
    printf("Insert %s: ", size_type);
    scanf("%lu", &size);
    getchar();
    if (size < 1 || size > 10)
    {
      printf("Invalid %s!\n", size_type);
    }
  } while (size < 1 || size > 10);

  return size;
}

Color** allocateMemory(size_t height, size_t width)
{
  Color** field = calloc(height, sizeof(Color*));
  if (!field)
  {
    return NULL;
  }

  for (size_t row = 0; row < height; row++)
  {
    field[row] = malloc(width * sizeof(Color));
    if (!field[row])
    {
      freeMemory(field, height);
      return NULL;
    }

    for (size_t col = 0; col < width; col++)
    {
      field[row][col] = BLACK;
    }
  }

  return field;
}

void freeMemory(Color** field, size_t height)
{
  for (size_t row = 0; row < height; row++)
  {
    free(field[row]);
  }
  free(field);
}

void printField(Color** field, size_t heigth, size_t width)
{
  printf("   ");
  for (size_t col = 0; col < width; col++)
  {
    printf(" %lu", col);
  }
  printf("\n   ");
  for (size_t col = 0; col < width * 2; col++)
  {
    printf("-");
  }
  printf("\n");

  for (size_t row = 0; row < heigth; row++)
  {
    printf("%lu |", row);
    for (size_t col = 0; col < width; col++)
    {
      printf("%s\u2588\u2588", COLORS[field[row][col]]);
    }
    printf("\x1b[37m|\n");
  }

  printf("   ");
  for (size_t col = 0; col < width * 2; col++)
  {
    printf("-");
  }
  printf("\n");
}

Color parseInput(char* input)
{
  for (size_t quick_and_dirty = 0; quick_and_dirty < 9; quick_and_dirty++)
  {
    if (strcmp(input, COMMANDS[quick_and_dirty]) == 0)
      return quick_and_dirty;
  }
  return NONE;
}

void storeToFile(Color** field, size_t height, size_t width)
{
  char filename[50];
  printf("Enter filename ([name].ppm): ");
  fgets(filename, 50, stdin);
  for (size_t pos = 0; filename[pos]; pos++)
  {
    if (filename[pos] == '\n')
    {
      filename[pos] = 0;
      break;
    }
  }

  FILE* file = fopen(filename, "w");
  if (!file)
  {
    printf("Unable to safe painting to the file!\n");
    return;
  }

  fprintf(file, "%s\n%zu\n%zu\n%d\n", "P3", width, height, 255);
  for (size_t row = 0; row < height; row++)
  {
    fprintf(file, "\n");
    for (size_t col = 0; col < width; col++)
    {
      Color color = field[row][col];
      fprintf(file, "%3d %3d %3d\n", RGB_COLORS[color][0], RGB_COLORS[color][1], 
                                     RGB_COLORS[color][2]);
    }
  }

  fclose(file);
}
