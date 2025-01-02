#include <stdio.h>

int main() {
  unsigned char c;
  for (c=1; c<255; c++) {
    // ignore null code
    if (c == 26) continue;
    printf("%3u -> %c", c, c);
    if (c == 10 || c == 13) continue;
    if (c % 5 == 0)
      printf("\n");
    else
      printf("\t");
  }
  printf("\n");
}
