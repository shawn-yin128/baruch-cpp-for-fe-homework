/*
 * write a program to multiplie a number by a factor 2 to the power n.
 */

#include <stdio.h>

int main(void) {
  int a, n, res;
  printf("Please enter a number:\n");
  scanf("%d", &a);
  printf("Please enter the power:\n");
  scanf("%d", &n);
  res = a << n;
  printf("%d times 2 to the power of %d is %d.\n", a, n, res);
  return 0;
}
