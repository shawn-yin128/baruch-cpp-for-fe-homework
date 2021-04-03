/*
 * table of Fahrenheit and Celsius from 0 to 300 degree
 */
#include <stdio.h>
/* define start, end, step to be constant so that can easily changed at begining of program */
#define START 0
#define END 300
#define STEP 20

int main(void) {
  double fah, cel; /* double is more accurate */
  int degree; /* use degree to move forward */
  printf("Fahrenheit:\tCelsius:\n");
  for (degree = START; degree <= END; degree += STEP) {
    fah = degree;
    cel = (5.0 / 9.0) * (fah - 32); 
    printf("%10.1f\t%10.1f\n", fah, cel);
  }
  return 0;
}
