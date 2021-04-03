/*
 * contains the main() function and gives the varible i a value.
 */
#include <stdio.h>
#include "print.h" /* write the function print in a header file */

int main(void) {
  int i;
  printf("Please enter a number:\n");
  scanf("%d", &i);
  print(i);
  return 0;
}
