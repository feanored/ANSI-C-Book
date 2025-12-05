#include <stdio.h>

typedef union jx {
	int a;
	char b;
	double c;
} JX;

int main() {
	JX x;

	x.a = 42;
	x.b = 0x42;
	x.c = 355.0 / 113;
	printf("a: %d \n", x.a);
	printf("b: %d \n", x.b);
	printf("c: %.15f \n", x.c);

	return 0;
}