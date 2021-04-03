/*
 * a program to count how many times each of the numbers 0-4 have been typed.
 * use switch-case
 * use default to count other characters
 */
#include <stdio.h>

int main(void) {
  int cnt_zero = 0, cnt_one = 0, cnt_two = 0, cnt_three = 0, cnt_four = 0, cnt_other = 0;
  int curr_char;
  printf("Please type the sequece:\n");
  while ((curr_char = getchar()) != EOF) {
    switch (curr_char) {
      case 48: cnt_zero++; break;
      case 49: cnt_one++; break;
      case 50: cnt_two++; break;
      case 51: cnt_three++; break;
      case 52: cnt_four++; break;
      default: cnt_other++;
    }
  }
  printf("\nNumber 0 has occured %d times.\nNumber 1 has occured %d times.\nNumber 2 has occured %d times.\nNumber 3 has occured %d times.\nNumber 4 has occured %d times.\nOther elements have occured %d times.\n", cnt_zero, cnt_one, cnt_two, cnt_three, cnt_four, cnt_other);
  return 0;
}
