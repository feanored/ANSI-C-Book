#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SPACE 32

char getOp(){
  char op;
  printf("What type to test?\n");
  printf("Uns. [s]hort | Uns. [i]nt | Uns. [l]ong\n");
  printf("[S]hort | [I]nt | [L]ong\n? ");
  op = 0;
  while (op != 's' && op != 'i' && op != 'l' &&
         op != 'S' && op != 'I' && op != 'L' &&
         op != SPACE)
    (void) scanf("%c", &op);
  while (getchar() != '\n'); // clears buffer
  return op;
}

int main() {
  int op, ch;

  unsigned short s;
  unsigned int i;
  unsigned long l;
  short S;
  int I;
  long L;

  l = i = s = 0;
  L = I = S = 0;

  op = getOp();
  ch = 0;
  while(op != SPACE) {
    switch(op) {
      case 's':
        if (++s % 5000 == 0)
          printf("unsigned short: %u\n", s);
        if (s % 100000 == 0)
          ch = getchar();
        break;
      case 'i':
        if (++i % 500000000 == 0)
          printf("unsigned int: %u\n", i);
        if (i % 10000000000 == 0)
          ch = getchar();
        break;
      case 'l':
        if (++l % 500000000 == 0)
          printf("unsigned long: %lu\n", l);
        if (l % 10000000000 == 0)
          ch = getchar();
        break;
      case 'S':
        if (++S % 5000 == 0)
          printf("short: %d\n", S);
        if (S % 100000 == 0)
          ch = getchar();
        break;
      case 'I':
        if (++I % 500000000 == 0)
          printf("int: %d\n", I);
        if (I % 10000000000 == 0)
          ch = getchar();
        break;
      case 'L':
        if (++L % 500000000 == 0)
          printf("long: %ld\n", L);
        if (L % 10000000000 == 0)
          ch = getchar();
        break;
    }
    if (ch == SPACE) {
      op = getOp(); // prompts for a new test
      ch = 0;
    }
  }
}
