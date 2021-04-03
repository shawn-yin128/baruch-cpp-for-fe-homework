/*
 * write a function to swap two variables' value.
 */
#include <stdio.h>

void swap(int* x, int* y);

int main(void) {
  int x, y;
  
  /* ask the user to input values */
  printf("Please enter two numbers:\n");
  scanf("%d %d", &x, &y);
  
  /* values before swap */
  printf("Before swap, x is %d, y is %d.\n", x, y);

  /* swap */
  swap(&x, &y);

  /* values after swap */
  printf("After swap, x is %d, y is %d.\n", x, y);

  return 0;
}

void swap(int* x, int* y) {
  /* create a var to store value */
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}
