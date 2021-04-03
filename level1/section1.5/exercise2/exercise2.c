/*
 * write a program to print factorials of a number 
 */
#include <stdio.h>

long long int factorial(long long int n) { /* use long long type in case of big number */
  if (n == 1) {
    return 1;
  }
  return n*factorial(n-1);
}

int main(void) {
  long long int n, res;
  printf("Please enter a number:\n");
  scanf("%lld", &n);
  res = factorial(n);
  printf("The factorial of %lld is %lld.\n", n, res);
  return 0;
}
