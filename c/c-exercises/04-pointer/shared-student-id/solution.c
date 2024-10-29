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

void addStudentToLecture(int* lecture_array[NR_STUDENTS], int students[NR_STUDENTS],
                         int selected_student_id)
{
  int found_free_place = 0;
  int already_inside = 0;
  for(int i = 0; i < NR_STUDENTS; i++)
  {
    if(lecture_array[i] == 0)
    {
      // set the reference (the address) of the studentID as pointer into the lecture_array
      lecture_array[i] = &students[selected_student_id];
      found_free_place = 1;
      break; // we can break if we found a free place
    }
    // if the studentID is already inside
    else if(*lecture_array[i] == students[selected_student_id])
    {
      already_inside = 1;
      break;
    }
  }
  if(already_inside == 1)
    printf("Student already in this lecture\n");
  else if(found_free_place == 0)
    printf("lecture full\n");
}

void changeStudentID(int* students, int selected_id)
{
  int new_student_id = 0;
  printf("Enter new student ID of Student Nr %d: ", selected_id);
  scanf("%d", &new_student_id);

  // this is possible because students is an array, which is a "pointer"
  students[selected_id] = new_student_id;
}

int main(void)
{
  int* esp_students[NR_STUDENTS] = {0};
  int* analysis_students[NR_STUDENTS] = {0};
  int students[] = {999999999, 4444444, 7777777, 65455654, 11111111, 23232323};

  while(1)
  {
    int selected_option = printMenuAndGetSelection();
    if(selected_option == 0) // Quit
      break;

    if(selected_option == 1) // print
      printStudents(students,esp_students,analysis_students);

    if(selected_option == 2) // add student
    {
      int selected_student_id = getStudendId();
      int lecture_id = getLectureId();
      if(lecture_id == 1) // ESP
        addStudentToLecture(esp_students, students, selected_student_id);
      else // Analysis
        addStudentToLecture(analysis_students, students, selected_student_id);
    }

    if(selected_option == 3) // change original student
    {
      int selected_student_id = getStudendId();
      changeStudentID(students, selected_student_id);
    }
  }

  return 0;
}
