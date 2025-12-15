#include <stdio.h>
#define _USE_MATH_DEFINES 1
#include <math.h>

#define True  1
#define False 0

int main() {
  printf("\n\nHello Pitu! Amo meu tuco!\n");

  printf("Pi45: %.12f \n", atan(1) * 4);
  printf("M_Pi: %.12f \n", M_PI);

  if (True) printf("\nDef True exists!\n");
  if (!False) printf("Def False exists!\n");

  return getchar();
}
