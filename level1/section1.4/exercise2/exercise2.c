/*
 * input a sentence from keyboard (use ctrl+d to stop), and count the number of characters, newlines, and words.
 */
#include <stdio.h>

int main(void) {
  int curr_char = 0; /* represent the current character we read */
  int cnt_char = 0; /* number of characters */
  int cnt_word = 0; /* number of words */
  int cnt_endl = 0; /* number of new lines */
  int last_char = 0; /* represent if it is the last character of a word 0 for false, 1 for true */
  int last_endl = 0; /* represent if it is the prev of new line, 0 for false, 1 for treu */

  printf("Please enter a sentence and type ctrl+d when want to stop:\n");

  /* write the while loop part */

  do { 
    if (curr_char == 32) { /* 32 is space */
      if (last_char) {
        cnt_word++;
      }
      last_char = 0;
    }
    else if (curr_char == 10) { /* 10 is new line */
      if (last_char) {
        cnt_word++;
      }
      last_char = 0;
      last_endl = 1;
    }
    else if (curr_char != 0){ /* because the first time, curr char is null */
      cnt_char++;
      if (last_endl) {
        cnt_endl++;
        last_endl = 0;
      }
      last_char = 1;
    }
  } while ((curr_char = getchar()) != EOF);

  if (last_char) {
    cnt_word++;
  }
  if (cnt_word) {
    cnt_endl++; /* beacause the last newline will not be counted if without this */
  }

  /* print the count out */
  printf("\nThe count of characters is %d, the count of word is %d, and the count of newline is %d.\n", cnt_char, cnt_word, cnt_endl);
  return 0;
}
