#include <stdio.h>
char welcome[] = ("-------------------------\n"
                  "   Press q or Q to Quit  \n"
                  "     This is an Array    \n"
                  "-------------------------\n");

char *welcome_2 = ("-------------------------\n"
                   "   Press q or Q to Quit  \n"
                   "     This is a Pointer   \n"
                   "-------------------------\n");
int main() {
  //  printf("%s", welcome);
  // What is the difference between * and & with pointers?

  // printf("%s\n", welcome_2);
  /* NOTE: This Would print the out the memmory address of the welcome2
  printf("%p\n", &welcome_2); */

  // Should I use char varchar = 0; or is char varchar; enough?
  while (1) {
    int input = 0;
    printf("Insert character: ");
    /* NOTE: Whitespace im Format String wird ignoriert, (Wenn Whitespace
    erwartet wird)
    *   How to cast the user input to a char?
    *   Why Does it Work?
    *   We cast the value of the variable directly to a char using (char)input
    */
    scanf(" %c", (char *)&input);

    // Clear Buffer!
    while (getchar() != '\n' && getchar() != EOF) {
    }

    if ((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z')) {

      // NOTE: The important takeaway here is: USE format String %d, if you want
      // output to be in number format. And use %c if you want it as a char!
      printf("Number:                   %d\n", input);
      printf("ASCII Character:          %c\n", input);

    } else {
      printf("[ERROR] not a valid Character [A-Z or a-z]\n");
    }

    // By placing the if statement here, we don't have to write it twice!
    if (input == 'q' || input == 'Q') {
      printf("GOODBYE\n");
      return 0;
    }

    printf("--------------------------------\n");

    printf("Insert int: ");
    scanf("%d", (int *)&input);

    // Clear Buffer!
    if ((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z')) {
    }
    if (input >= 31 && input <= 127) {
      printf("Number:               %d\n", input);
      printf("ASCII Character:      %c\n", input);
    } else {
      printf("[ERROR] not a visible ASCII-Character\n");
    }
    printf("--------------------------------\n");
    printf("--------------------------------\n");
  }
}
