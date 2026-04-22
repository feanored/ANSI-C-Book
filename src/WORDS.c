#include <stdio.h>

#define OUT 0
#define IN  1

int main() {
  long nw;
  int c, state;

  state = OUT;
  nw = 0;
  while((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      state = OUT;
    }
    else if (state == OUT) {
      if (nw++ > 0)
        putchar('\n');
      state = IN;
    }
    if (state == IN)
      putchar(c);
  }
  printf("\n words: %ld\n", nw);
}