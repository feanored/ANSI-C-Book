#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
  // Limites de short
  printf("Short (signed): %d to %d\n", SHRT_MIN, SHRT_MAX);
  printf("Short (unsigned): 0 to %u\n\n", USHRT_MAX);

  // Limites de int
  printf("Int (signed): %d to %d\n", INT_MIN, INT_MAX);
  printf("Int (unsigned): 0 to %u\n\n", UINT_MAX);

  // Limites de long
  printf("Long(signed): %ld to %ld\n", LONG_MIN, LONG_MAX);
  printf("Long(unsigned): 0 to %lu\n\n", ULONG_MAX);

  // Limites de float
  printf("Float precision: %d\n", FLT_DIG);
  printf("Float epsilon:   %g\n", FLT_EPSILON);
  printf("Float min:       %g\n", FLT_MIN);
  printf("Float max:       %g\n\n", FLT_MAX);

  // Limites de double
  printf("Double precision: %d\n", DBL_DIG);
  printf("Double epsilon:   %g\n", DBL_EPSILON);
  printf("Double min:       %g\n", DBL_MIN);
  printf("Double max:       %g\n", DBL_MAX);
}