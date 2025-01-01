#include <stdio.h>

int main() {
  //printf("%d", EOF); // Ex. 1-7 => EOF == -1
  int c;
  while ((c = getchar()) != EOF) {
    putchar(c);
    //printf("\n%d\n", c != EOF); // Ex. 1-6 (se = no bloco)
  }
}
