/*
 * print out frequency of number 3 in words
 */
#include <stdio.h>

int main(void) {
  int cnt_zero = 0, cnt_one = 0, cnt_two = 0, cnt_three = 0, cnt_four = 0, cnt_other = 0;
  int curr_char, i;
  printf("Please enter a sentence:\n");
  while ((curr_char = getchar()) != EOF) {
    switch(curr_char) {
      case 48: cnt_zero++; break;
      case 49: cnt_one++; break;
      case 50: cnt_two++; break;
      case 51: cnt_three++; break;
      case 52: cnt_four++; break;
      default: cnt_other++;
    }
  }
  printf("\n");
  switch (cnt_three) {
    case 0: printf("The number three appears zero times.\n"); break;
    case 1: printf("The number three appears one times.\n"); break;
    case 2: printf("The number three appears two times.\n"); break;
    default: printf("The number three appears more than two times.\n");
  }
  return 0;
}
