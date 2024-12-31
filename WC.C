#include <stdio.h>

#define OUT 0
#define IN  1

void main() {
  long nl, nw, nc;
  int c, state;

  nw = nl = nc = 0;
  state = OUT;
  while((c = getchar()) != EOF) {
    nc++;
    if (c == '\n')
      nl++;
    if (c == ' ' || c == '\t' || c == '\n')
      state = OUT;
    else if (state == OUT) {
      state = IN;
      nw++;
    }
  }
  printf(" chars: %ld\n lines: %ld\n words: %ld\n", nc, nl, nw);
}
