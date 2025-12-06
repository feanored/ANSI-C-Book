#include <stdio.h>
#define _USE_MATH_DEFINES 1
#include <math.h>

typedef union jx {
	int a;
	char b;
	double c;
} JX;

int main() {
	JX x;

	x.a = 42;
	x.b = 0x42;
	x.c = 104348. / 33215;
	printf("a: %d \n", x.a);
	printf("b: %d \n", x.b);
	printf("c:    %.12f \n", x.c);
	printf("Pi45: %.12f \n", atan(1) * 4);
	printf("M_Pi: %.12f \n", M_PI);

	return 0;
}