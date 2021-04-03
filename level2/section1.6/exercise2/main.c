/*
 * test the macros.
 */
#include <stdio.h>
#include "Defs.h"

int main(void) {
  int x, y, z;
  
  /* ask the user to input numbers */
  printf("Please enter three number:\n");
  /* assign the input number into variabe */
  scanf("%d %d %d", &x, &y, &z);

  /* test MAX2 */
  printf("The max between %d and %d is %d.\n", x, y, MAX2(x, y));

  /* test MAX3 */
  printf("The max between %d, %d, and %d is %d.\n", x, y, z, MAX3(x, y, z));

  return 0;
}
