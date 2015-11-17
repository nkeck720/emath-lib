#if !defined(EMATH_H)
#define EMATH_H // to protect against multiple includes

#if defined(__cplusplus)
extern "C"
#endif

// Function prototypes

// Note that we do not include the standalone shield.
int ohmslaw(int i, int v, int r);
int confohmslaw(int i, int v, int r);
int getvoltage(int i, int r);
int getcurrent(int v, int r);
int power(int i, int v);
int dissipated(int v1, int i1, int v2, int i2);

#endif
