#include <stdio.h>

int main(void) {
	int n, k, t_1, t_2;
	scanf("%d%d", &n, &k);
	int a[n];
	for (int i = 0; i <= n - 1; i++)
		scanf("%d", &a[i]);
	int tms = (n > (n - k)) ? (n - k) : n;
	for (int i = 1; i <= tms; i++) {
		t_1 = a[0];
		for (int j = 1; j <= n; j++) {
			t_2 = a[j];
			a[j % n] = t_1;
			t_1 = t_2;
		}

	}
	for (int i = 0; i <= n - 1; i++)
		printf("%d ", a[i]);
	return 0;
}