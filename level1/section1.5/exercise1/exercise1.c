/*
 * write a c program that calls a funtion minus which receives two arguments and return the difference. print out the difference.
 */
#include <stdio.h>

double minus(double num1, double num2) {
  double res;
  res = num1 - num2;
  return res;
}

int main(void) {
  double num1, num2, res;
  printf("Please enter two numbers:\n");
  scanf("%lf %lf", &num1, &num2);
  res = minus(num1, num2);
  printf("The difference between %lf and %lf is %lf.\n", num1, num2, res);
  return 0;
}
