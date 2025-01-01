#include <stdio.h>

int main() {
  int cont, c;
  cont = 1;
  while((c = getchar()) != EOF) {
    if (c == '\n')
      cont++;
  }
  printf("Lines #: %d\n", cont);
}
