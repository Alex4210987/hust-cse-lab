#include <stdio.h>
int n, p;
int remain[25];

int main() {
	scanf("%d", n);
	while (n--) {
		scanf("%d", p);
		for (int i = 1; i <= 20; i++) {
			if (remain[i] >= p) {
				for (int j = 1; j <= p; j++) {
					printf("%d%c", (i - 1) * 5, 'A' - 1 + 5 - remain[i] + j);
				}
				remain[i] -= p;
				p = 0;
				break;
			}
		}
		for (int i = 1; i <= 20 && p; i++) {
			if (remain[i] != 0) {
				if (p > remain[i]) {
					for (int j = 1; j <= remain[i]; j++) {
						printf("%d%c", (i - 1) * 5, 'A' - 1 + 5 - remain[i] + j);
					}
					p -= remain[i];
					remain[i] = 0;
				} else {
					for (int j = 1; j <= p; j++) {
						printf("%d%c", (i - 1) * 5, 'A' - 1 + 5 - remain[i] + j);
					}
					remain[i] -= p;
					p = 0;
				}
			}
		}
		putchar('\n');
	}
	return 0;
}
