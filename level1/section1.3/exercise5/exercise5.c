/*
 * write a program to clearify the difference between --i and i--
 */

#include <stdio.h>

int main(void) {
  int a, b, i = 10, j = 10;
  a = i--;
  b = --j;
  printf("i is 10 and a = i--, after operation, a is %d, i is %d.\n", a, i);
  printf("j is 10 and b = --j, after operation, b is %d, j is %d.\n", b, j);
  return 0;
}
