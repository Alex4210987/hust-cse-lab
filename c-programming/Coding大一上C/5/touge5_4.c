#include <stdio.h>
int a[1000], b, c[1000];
int m_1, n_1, m_2, n_2;

int main(void) {
	scanf("%d", &b);
	for (int i = 0; i <= b - 1; i++) {
		scanf("%d", &a[i]);
	}
	scanf("%d%d%d%d", &m_1, &n_1, &m_2, &n_2);
	for (int i = 0; i < m_1; i++) {
		printf("%d ", a[i]);
	}
	for (int i = m_1; i <= m_1 + (n_2 - m_2); i++) {
		printf("%d ", a[i - m_1 + m_2]);
	}
	for (int i = n_1 + 1; i < m_2; i++) {
		printf("%d ", a[i]);
	}
	for (int i = m_2; i <= m_2 + (n_1 - m_1); i++) {
		printf("%d ", a[i - m_2 + m_1]);
	}
	if (n_2 != (b - 1)) {
		for (int i = n_2 + 1; i < b - 1; i++) {
			printf("%d ", a[i]);
		}
		printf("%d", a[b - 1]);
	}

	return 0;
}