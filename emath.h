#if !defined(EMATH_H)
#define EMATH_H // to protect against multiple includes

#if defined(__cplusplus)
extern "C"
#endif

// Typedefs for function variables
typedef int voltage;
typedef int current;
typedef int power;

// Function prototypes

// Note that we do not include the standalone shield.
int ohmslaw(int i, int v, int r);
int confohmslaw(int i, int v, int r);
volatge getvoltage(int i, int r);
current getcurrent(int v, int r);
power power(int i, int v);
power dissipated(int v1, int i1, int v2, int i2);
voltage rms_voltage(voltage peak_hi, voltage peak_lo);
current rms_current(current peak_hi, current peak_lo);

#endif
