#include <stdio.h>

#define UPPER 200       /* upper limit of temperature */
#define LOWER -275      /* lower limit of temperature */
#define STEP  25        /* step size */

void main_c() {
  double fahr, celsius, kelvin;

  celsius = LOWER+2;
  printf(".F\t.C\tK\n");
  while (celsius <= UPPER) {
    fahr = (9. / 5. * celsius) + 32;
    kelvin = celsius + 273;
    printf("%5.1f\t%5.1f\t%5.1f\n", fahr, celsius, kelvin);
    if (kelvin == 0) celsius = LOWER;
    celsius = celsius + STEP;
  }
  getchar();
}

void main_d() {
  double fahr, celsius, kelvin;

  celsius = UPPER;
  printf(".F\t.C\tK\n");
  while (celsius >= LOWER) {
    if (celsius == LOWER) celsius = -273;
    fahr = (9. / 5. * celsius) + 32;
    kelvin = celsius + 273;
    printf("%5.1f\t%5.1f\t%5.1f\n", fahr, celsius, kelvin);
    celsius = celsius - STEP;
  }
  getchar();
}

int main() {
  main_c();
}
