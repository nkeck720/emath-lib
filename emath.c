#include <stdio.h>
#include <math.h>
#include "emath.h"

/*
 * This is a library of C functions to caluculate electonic formulas such as
 * Ohm's Law and power.
 *
 * These functions return -1 in the case of an error or incorrect calculation. Any other value is considered
 * correct.
 */

#if defined(__cplusplus)
extern "C"  // Use C linkage in C++ programs
#endif

void main(void) {
  // This function is an anti-standalone shield, comment out if needed.
  printf("This is not a standalone program.\n");
  printf("Include this library into your C program to use it.\n");
  return(0);
}

/*
 * These typedefs are here for quick changing of variable types
 */

typedef int voltage;
typedef int current;
typedef int power;
typedef int resistance;

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

/*
 * getvoltage - calculates voltage based upon a given current and resistance
 */

voltage getvoltage(int i, int r) {
  int retval;
  retval=ohmslaw(i, NULL, r);
  return(retval);
}

/*
 * getcurrent - calculates current based upon voltage and resistance
 */

current getcurrent(int v, int r) {
  int retval;
  retval=ohmslaw(NULL, v, r);
  return(retval);
}

/*
 * power - calculates power in watts based on current and voltage
 */

power power(int i, int v) {
  int retval;
  retval=v * i; // I have heard this called apparent power, or VA (volt-amps). Is this an AC-only thing?
  return(retval);
}

/*
 * dissipated - calculates dissipated energy (watts) with a given input vlots, amps and an output.
 */

power dissipated(int v1, int i1, int v2, int i2) {
  int retval, inpower, outpower;
  inpower = power(i1, v1);
  outpower = power(i2, v2);
  retval = inpower - outpower;
  return(retval);
}

/*
 * rms_voltage - calculates RMS voltages in AC circuits
 */

voltage rms_voltage(voltage peak_hi, voltage peak_lo) {
  // I think this is how you calculate RMS, but this may need to be changed.
  // This function was made when I did not have internet access to look this up.
  voltage retval;
  retval = sqrt(peak_hi + peak_lo / 2);
  retval = retval * retval;
  return(retval);
}

/*
 * rms_current - calculates RMS current values in AC circuits
 */


current rms_current(current peak_hi, current peak_lo) {
  current retval;
  retval = sqrt(peak_hi + peak_lo / 2);
  retval = retval * retval;
  return(retval);
}
