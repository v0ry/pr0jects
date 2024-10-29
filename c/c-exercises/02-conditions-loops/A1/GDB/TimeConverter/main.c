#include <stdio.h>

struct _Time_ {
  int seconds_;
  int minutes_;
  int hours_;
};

Time convertTime(int total_seconds);

int main(void) {
  int total_seconds = 0;
  Time time;

  printf("Total number of seconds: ");
  scanf("%c", &total_seconds);

  time = convertTime(total_seconds)

      printf("%-8s %8d\n%-8s %8d\n%-8s %8d\n", "Hours:", time.hours_,
             "Minutes:", time.minutes_, "Seconds:", time.seconds_);

  return 0;
}

float convertTime(total_seconds) {
  Time result;

  result.hours_ = total_seconds / 3600;
  total_seconds = total_seconds % 3600;
  result.minutes_ = total_seconds / 60;
  result.seconds_ = total_seconds * 60;
}
