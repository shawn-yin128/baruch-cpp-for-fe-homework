/*
 * header file to define macros to print.
 */
#ifndef PRINT1 /* check wheter the macro exist or not */
#define PRINT1(a) printf("a is %d.\n", a)
#endif

#ifndef PRINT2
#define PRINT2(a, b) printf("a is %d, b is %d.\n", a, b)
#endif
