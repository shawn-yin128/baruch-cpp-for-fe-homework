/*
 * write a function printnumber() to print each digit of a number.
 */
#include <stdio.h>

int negative_processor(int n);
void printnumber(int n);

int main(void) {
  int n;
  printf("Please enter a number:\n");
  scanf("%d", &n);
  if (n < 0) {
    n = negative_processor(n);
  }
  printnumber(n);
  printf("\n");
  return 0;
}

int negative_processor(int n) {
  int pos_n;
  putchar('-');
  pos_n = 0 - n;
  return pos_n;
}

void printnumber(int n) {
 if (n / 10 == 0) {
   putchar(n + 48);
 }
 else {
   printnumber((n / 10));
   putchar((n % 10) + 48);
 }
}
