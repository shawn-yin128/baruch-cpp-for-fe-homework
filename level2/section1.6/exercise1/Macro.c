/*
 * use defined macro to print variable out.
 */
#include <stdio.h>
#include "Defs.h"

int main(void) {
  int a, b;
  printf("Please enter number a and number b:\n");
  scanf("%d %d", &a, &b);
  /* print a */
  PRINT1(a);
  /* print a and b */
  PRINT2(a, b);
  return 0;
}
