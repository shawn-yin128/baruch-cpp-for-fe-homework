/*
 * write two macros max2 and max3 and max3 should use max2
 */
#ifndef MAX2
#define MAX2(x, y) ((x > y) ? x : y) /* if x is better, MAX2 will return x, otherwise y */
#endif

#ifndef MAX3
#define MAX3(x, y, z) (MAX2(MAX2(x, y), z)) /* first find the max between first two, and then compare with the last one */
#endif
