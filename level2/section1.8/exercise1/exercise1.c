/*
 * create a struct and print the contents
 */
#include <stdio.h>
#define LENGTH 20

typedef struct Article {
  int number; /* number of article */
  int quantity; /* quanlity of article */
  char description[LENGTH + 1]; /* +1 is for \0 */
} Article;

void Print(Article art);

int main(void) {
  Article art = {5, 10, "A collection of paper"}; /*declare article and assign values */
  Print(art);
  return 0;
}

void Print(Article art) {
  printf("Article number is: %d.\n", art.number);
  printf("Article quantity is: %d.\n", art.quantity);
  printf("Article description is: %s.\n", art.description);
}
