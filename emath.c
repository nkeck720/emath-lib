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

int main(void) {
  // This function is an anti-standalone shield, comment out if needed.
  printf("This is not a standalone program.\n");
  printf("Include this library into your C program to use it.\n");
  return(-1);
}

/*
 * These typedefs are here for quick changing of variable types
 */

typedef float voltage;
typedef float current;
typedef float power;
typedef float resistance;

/* 
 * ohmslaw - solves ohm's law for a NULL value
 */

float ohmslaw(float i, float v, float r) {
  float retval;
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

float confohmslaw(float i, float v, float r) {
  float retval;
  float temp;
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

voltage getvoltage(current i, resistance r) {
  voltage retval;
  retval=ohmslaw(i, NULL, r);
  return(retval);
}

/*
 * getcurrent - calculates current based upon voltage and resistance
 */

current getcurrent(voltage v, resistance r) {
  current retval;
  retval=ohmslaw(NULL, v, r);
  return(retval);
}

/*
 * power - calculates power in watts based on current and voltage
 */

power power(current i, voltage v) {
  power retval;
  retval=v * i; // I have heard this called apparent power, or VA (volt-amps). Is this an AC-only thing?
  return(retval);
}

/*
 * dissipated - calculates dissipated energy (watts) with a given input vlots, amps and output current/volts.
 */

power dissipated(voltage v1, current i1, voltage v2, current i2) {
  power retval, inpower, outpower;
  inpower = power(i1, v1);
  outpower = power(i2, v2);
  retval = inpower - outpower;
  return(retval);
}

/*
 * rms_voltage - calculates RMS voltages in AC circuits
 */

voltage rms_voltage(voltage peak_hi, voltage peak_lo) {
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
