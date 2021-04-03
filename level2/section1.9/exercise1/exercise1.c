/*
 * read the character from keyboard and show on the screen and end when meet ^A.
 */
#include <stdio.h>
#define LENGTH 100

void print_on_screen(char str[], int cnt);

int main(void) {
  int char_input;
  int cnt = 0;
  char str[LENGTH];
  /* ask user to input */
  printf("Please enter characters, use ENTER to display characters and use CTRL+A to stop:\n");
  while ((char_input = getchar()) != 1) { /* 1 is CTRL A */
    if (char_input == 10 && cnt > 0) { /* use 10 = ENTER to check whether to print the line or not */
      print_on_screen(str, cnt);
      cnt = 0; /* reset cnt */
      continue;
    }
    str[cnt] = char_input;
    cnt++;
  }
  return 0;
}

void print_on_screen(char str[], int cnt) {
  int i;
  for (i = 0; i <= cnt-1; i++) {
    putchar(str[i]);
  }
  putchar('\n');
}
