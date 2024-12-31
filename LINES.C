#include <stdio.h>

void main() {
  int cont, c;
  cont = 1;
  while((c = getchar()) != EOF) {
    if (c == '\n')
      cont++;
  }
  printf("Lines #: %ld\n", cont);
}
