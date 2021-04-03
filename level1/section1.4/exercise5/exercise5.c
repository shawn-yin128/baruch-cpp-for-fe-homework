/*
 * table of celsius and fahrenheit from celsius 0 to 19
 */

#include <stdio.h>
#define START 0
#define END 19

int main(void) {
  double cel, fah;
  int degree;
  printf("Celsius:\tFahrenheit:\n");
  for (degree = START; degree <= END; degree++) {
    cel = degree;
    fah = (9.0 / 5.0) * cel + 32;
    printf("%10.1f\t%10.1f\n", cel, fah);
  }
  return 0;
}
