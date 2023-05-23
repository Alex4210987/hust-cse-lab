#include <stdio.h>
#define M 10
#define N 3

int a[M + 1], b[M + 1];

int main(void) {

	int i, j, k, count, h = 0;
	for (i = 1; i <= M; i++)
		a[i] = i;
	for (count = 0; count < M; count++) {
		while (h < N) {
			if ( ++j > i - 1)
				j = 1 ;
			if (b[j] == 0)
				h++;

		}
		printf("%6d", a[j]);
		b[j] = 1;
		h = 0;
	}
	return 0;
}