/*实验4-6跟踪调试第(2)题程序：利用R计算圆的面积s*/
#include "assert.h"
#include <stdio.h>
#define  R

int integer_fraction(float x) {
	int i = x;
	return i;
}

int main(void) {
	float  r, s;
	int s_integer = 0;
	printf ("Input a number: ");
	scanf("%f", &r);
#ifdef  R
	s = 3.14151 * r * r;
	printf("Area of round is: %f\n", s);
	s_integer = integer_fraction(s);
//	assert((s - s_integer) < 0.5);
	if ((s - s_integer) < 0.5)
		printf("The integer fraction of area is %d\n", s_integer);
	else
		printf("The integer fraction of area is %d\n", s_integer + 1);
#endif
	return 0;
}
