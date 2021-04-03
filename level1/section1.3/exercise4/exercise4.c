/*
 * check married or not using ?:.
 */

#include <stdio.h>

int main(void) {
  int marry_status;
  printf("Enter marry times:\n");
  scanf("%d", &marry_status); 
  (marry_status > 0) ? printf("Married\n"):printf("Not Married\n"); /* if marry times > 0, print married */
  return 0;
}
