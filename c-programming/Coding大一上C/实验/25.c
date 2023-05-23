#include <stdio.h>
int p[100], n, t;

int main() {
	scanf("%d", &n);

	for (int i = 0; i <= n - 1; i++) {
		scanf("%d", &t);
		*(p + i) = t;
	}
	for (int i = 0; i <= n - 1; i++) {
		for (int j = i + 1; j <= n - 1; j++) {
			if (*(p + j) < * (p + i) ) {
				t = *(p + j);
				*(p + j) = *(p + i);
				*(p + i) = t;
			}
		}
		printf("%d ", *(p + i));
	}
}