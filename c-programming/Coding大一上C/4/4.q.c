#include <stdio.h>
long long sum_fac(int n);

int main(void) {
	int k;
	for (k = 1; k <= 20; k++) {
		long long sum = 0;
		for (int j = 1; j <= k; j++)
			sum += sum_fac(j);
		printf("k=%lld\tthe sum is %lld\n", k, sum);
	}
	return 0;
}

long long sum_fac(int n) {
	long long s = 0;
	long long i, fac = 1;
	for (i = 1; i <= n; i++)
		fac *= i;
	s += fac;
	fac = 1;
	return s;
}
