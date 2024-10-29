#include <stdio.h>

int main() {
  int votes_windows;
  int votes_linux;

  printf("Votes for Windows: ");
  scanf("%d", &votes_windows);

  printf("Votes for Linux: ");
  scanf("%d", &votes_linux);

  // Compare the votes and announce the winner
  if (votes_windows == votes_linux) {
    printf("It's a tie between Windows and Linux!\n");
  } else if (votes_windows > votes_linux) {
    printf("Windows wins!\n");
  } else {
    printf("Linux wins!\n");
  }

  return 0;
}
