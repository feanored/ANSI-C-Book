#include <stdio.h>

#ifdef __APPLE__
#define INI 32
#define END 128
#else
#define INI 1
#define END 255
#endif

void line() {
  printf("\n");
}

void tab() {
  printf("\t");
}

int main() {
  unsigned char c;
  for (c = INI; c < END; c++) {
    if (c == 10 || c == 13 || c == 26)
      continue; // ignore some codes
    printf("%3u -> %c", c, c);
    if (c % 5 == 0)
      line();
    else
      tab();
  }
  line();
  c = getchar();
}
