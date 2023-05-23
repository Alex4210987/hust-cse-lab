#include <stdio.h>
int n, p, count = 0;
int remain[25];

int main() {
	for (int i = 1; i <= 20; i++) {
		remain[i] = 5;
	}
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &p);
		for (int i = 1; i <= 21; i++) {
			if (remain[i] >= p) {
				for (int j = 1; j <= p; j++) {
					count++;
					if (count == p) {
						char c = 'A' - 1 + 5 - remain[i] + j;
						c = (c == 'E') ? 'F' : c;
						printf("%d%c", i, c);
						count = 0;
					} else {
						char c = 'A' - 1 + 5 - remain[i] + j;
						c = (c == 'E') ? 'F' : c;
						printf("%d%c ", i, c);
					}
				}
				remain[i] -= p;
				p = 0;
				break;
			}
		}
		for (int i = 1; i <= 20 && p; i++) {
			count = 0;
			if (remain[i] != 0) {
				if (p > remain[i]) {
					for (int j = 1; j <= remain[i]; j++) {
						count++;
						if (count == p) {
							char c = 'A' - 1 + 5 - remain[i] + j;
							c = (c == 'E') ? 'F' : c;
							printf("%d%c", i, c);
							count = 0;
						} else {
							char c = 'A' - 1 + 5 - remain[i] + j;
							c = (c == 'E') ? 'F' : c;
							printf("%d%c ", i, c);
						}
					}
					p -= remain[i];
					remain[i] = 0;
				} else {
					for (int j = 1; j <= p; j++) {
						count++;
						if (count == p) {
							char c = 'A' - 1 + 5 - remain[i] + j;
							c = (c == 'E') ? 'F' : c;
							printf("%d%c", i, c);
							count = 0;
						} else {
							char c = 'A' - 1 + 5 - remain[i] + j;
							c = (c == 'E') ? 'F' : c;
							printf("%d%c ", i, c);
						}
					}
					remain[i] -= p;
					p = 0;
				}
			}
		}
		if (n != 0)
			putchar('\n');
	}
	return 0;
}