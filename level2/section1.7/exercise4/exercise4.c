/* 
 * write a function to prit the day of a given day number.
 */
#include <stdio.h>

void DayName(int num_day);

int main(void) {
  int num_day;
  /* ask user to input day number */
  printf("Please enter a number from 1 to 7:\n");
  scanf("%d", &num_day);
  /* check number is valid */
  if (num_day > 7) {
    printf("number %d is not a valid day.\n", num_day);
  }
  /* print the corresponding day */
  else {
  DayName(num_day);
  }
  return 0;
}

void DayName(int num_day) {
  /* define an array to store string */
  char day_str[7][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
  /* print the name out */
  printf("Day %d is a %s.\n", num_day, day_str[num_day - 1]);
}
