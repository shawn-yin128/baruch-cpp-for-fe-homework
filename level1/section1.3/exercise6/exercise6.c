/*
 * shift a number two places to the right using >>.
 */

#include <stdio.h>

int main(void) {
  int num, shift_num;
  printf("Please enter a number:\n");
  scanf("%d", &num);
  shift_num = num >> 2; /* shift 2 place to right */
  (num != shift_num) ? printf("shift is performed, the result is %d.\n", shift_num):printf("not shifted");
  return 0;
}
