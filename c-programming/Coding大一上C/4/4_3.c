#include <stdio.h>
double mulx(double x, int n);
long long fac(int n);


double sum(double x, int n) {
	if (n >= 1)
		return sum(x, n - 1) + mulx(x, n) / fac(n);
	else
		return 1;
}


double mulx(double x, int n) {
	int i;
	double z = 1.0;
	for (i = 0; i < n; i++) {
		z = z * x;
	}
	return z;
}

long long fac(int n) {
	if (n == 1)
		return 1;
	else
		return fac(n - 1) * n;
}

int main() {
	double x;
	int n;
	printf("Input x and n:");
	scanf("%lf%d", &x, &n);
	printf("The result is %lf:", sum(x, n));
	return 0;
}
