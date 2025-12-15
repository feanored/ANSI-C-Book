#include <stdio.h>

typedef union dd {
  int a;
  char b;
  double c;
} DD;

typedef struct data {
  int current;
  union {
    int a;
    char b;
    double c;
  } val;
} DATA;

int main() {
  DD u;
  u.a = 42;
  u.b = 0x42;
  u.c = 355.0/113;
  printf("u.a = %d\n",u.a);
  printf("u.b = %c\n",u.b);
  printf("u.c = %f\n",u.c);

  DATA d;
  printf("\nd: %zu bytes\n", sizeof d);
  for(int i=0; i<3; i++) {
     d.current = i;
     switch(d.current) {
     case 0:
       d.val.a = 42;
       printf("d.a = %d\n",d.val.a);
       break;
     case 1:
       d.val.b = 0x42;
       printf("d.b = %c\n",d.val.b);
       break;
     case 2:
       d.val.c = 355.0 / 113;
       printf("d.c = %f\n",d.val.c);
       break;
     }
  }

  return 0;
}
