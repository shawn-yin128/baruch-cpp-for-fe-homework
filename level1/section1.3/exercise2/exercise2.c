/*
 * inout base and height, calculate the area and print out.
 */

#include <stdio.h>

int main(void) {
  double base, height, area;  /* declare three double type variables */
  printf("Please enter the base and height of triangle:\n");  
  scanf("%lf %lf", &base, &height);  /* store the input value */
  area = base*height*0.5;
  printf("triangle with %lf base and %lf height has area of %lf.\n", base, height, area);
  return 0;
}
