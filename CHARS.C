#include <stdio.h>

void v1() {
  long cont;
  for (cont=0; getchar() != EOF; cont++);
  printf("Chars #: %ld\n", cont);
}

void v2() {
  int c;
  long cont;
  cont = 0;
  while((c = getchar()) != EOF) {
    if (c != '\n' && c != '\t')
      cont++;
  }
  printf("Chars #: %ld\n", cont);
}

void main() { v2(); }
