#include <stdio.h>
#include <stdlib.h>

#define NR_STUDENTS 6
#define SEPERATOR_LENGTH 105

void printSeparator()
{
  printf("\n");
  for(int i = 0; i < SEPERATOR_LENGTH; i++)
    printf("-");

  printf("\n");
}
void printStudents(int* students, int* esp_students[NR_STUDENTS],
                   int* analysis_students[NR_STUDENTS])
{
  printf("All Students: ");
  for(int i = 0; i < NR_STUDENTS; i++)
  {
    printf("%d: %d     ", i, students[i]);
  }
  printSeparator();
  printf("ESP Students: ");
  for(int i = 0; i  < NR_STUDENTS; i++)
  {
    if(esp_students[i] != NULL)
      printf(" %d     ", *esp_students[i]);
  }
  printSeparator();
  printf("Analysis Students: ");
  for(int i = 0; i  < NR_STUDENTS; i++)
  {
    if(analysis_students[i] != NULL)
      printf(" %d     ", *analysis_students[i]);
  }
  printSeparator();
}


int printMenuAndGetSelection()
{
  printf("----- MAIN MENU -----\n");
  printf(":: 0 Quit\n");
  printf(":: 1 Print StudentIDs\n");
  printf(":: 2 Add StudentID to lecture\n");
  printf(":: 3 change StudentID\n");
  printf("> ");
  int selected_option = 0;
  scanf("%d", &selected_option);
  getchar();
  return selected_option;
}

int getStudendId()
{
  int student_id = 0;
  printf("Select the Student by the ID (not the studentID itself): ");
  scanf("%d", &student_id);
  getchar();

  if(student_id < 0 || student_id > NR_STUDENTS - 1)
    return -1;

  return student_id;
}

int getLectureId()
{
  int lecture_id = 0;
  printf("Select Lecture: ESP == 1, Analysis == 2: ");
  scanf("%d", &lecture_id);
  getchar();

  if(lecture_id != 1 && lecture_id != 2)
    return -1;

  return lecture_id;
}

int main(void)
{
  int* esp_students[NR_STUDENTS] = {0};
  int* analysis_students[NR_STUDENTS] = {0};
  int students[] = {999999999, 4444444, 7777777, 65455654, 11111111, 23232323};

  // TODO: write program logic here
  // first you need to call printMenuAndGetSelection() to get the menu
  // depending on the option returned you have to modify the arrays above,
  // use the other provided function and write additional functionality

  return 0;
}
