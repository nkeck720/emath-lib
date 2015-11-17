#include <stdio.h>
#include <math.h>
#include "emath.h"

/*
 * This is a library of C functions to caluculate electonic formulas such as
 * Ohm's Law and reactance.
 *
 * These functions return -1 in the case of an error or incorrect calculation. Any other value is considered
 * correct.
 */

#if defined(__cplusplus)
extern "C"  // Use C linkage
#endif

void main(void) {
  printf("This is not a standalone program.\n");
  printf("Include this lib into your C program to use it.\n");
  return(0);
}

/*
 * ohmslaw - solves ohm's law for a NULL value
 */

int ohmslaw(int i, int v, int r) {
  int retval;
  if(i == NULL && v == NULL || i == NULL && r == NULL || v == NULL && r == NULL) {
    // Can't solve for multiple values
    return(-1);
  }
  if(i == NULL) {
    retval = v / r;
    return(retval);
  }
  if(v == NULL) {
    retval = i / r;
    return(retval);
  }
  if(r == NULL) {
    retval = i / v;
    return(retval);
  }
  else {
    // No value to solve for
    return(-1);
  }
}

/*
 * confohmslaw - confirms to see if an Ohm's Law calculation was correct
 */

int confohmslaw(int i, int v, int r) {
  int retval;
  int temp;
  temp = v / r;
  if(i == temp) {
    retval = 0;
  }
  else {
    retval = -1;
  }
  return(retval);
}

