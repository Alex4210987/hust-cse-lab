#include <stdio.h>
int m;
int matrix[100][4];

void put(int a[2], int b[2], int c[2], int d[2]) {
	if (b[1] - a[1] < 1 && d[0] - b[0] < 1)
		return;
	else {
		for (int i = 0; i <= (b[1] - a[1]); i++) {
			printf("%d ", matrix[a[0]][a[1] + i]);
		}
		for (int i = 1; i <= (c[0] - a[0]); i++) {
			printf("%d ", matrix[a[0] + i][b[1]]);
		}
		for (int i = 1; i <= (b[1] - a[1]); i++) {
			printf("%d ", matrix[c[0]][b[1] - i]);
		}
		for (int i = 1; i <= (c[0] - a[0] - 1); i++) {
			printf("%d ", matrix[c[0] - i][a[1]]);
		}
		a[0]++;
		a[1]++;
		b[0]++;
		b[1]--;
		c[0]--;
		c[1]++;
		d[0]--;
		d[1]--;
		put(a, b, c, d);
	}
}

int main() {
	scanf("%d", &m);
	for (int i = 0; i <= m - 1; i++)
		for (int j = 0; j <= 3; j++)
			scanf("%d", &matrix[i][j]);
	if (m == 1) {
		for (int j = 0; j <= 2; j++)
			printf("%d ", matrix[m - 1][j]);
		printf("%d", matrix[m][3]);
	} else if (m == 2) {
		for (int j = 0; j <= 3; j++)
			printf("%d ", matrix[m - 2][j]);
		for (int j = 0; j <= 2; j++)
			printf("%d ", matrix[m - 1][3 - j]);
		printf("%d", matrix[m - 1][0]);
	} else if (m == 3) {
		printf("%d ", matrix[0][0]);
		printf("%d ", matrix[0][1]);
		printf("%d ", matrix[0][2]);
		printf("%d ", matrix[0][3]);
		printf("%d ", matrix[1][3]);
		printf("%d ", matrix[2][3]);
		printf("%d ", matrix[2][2]);
		printf("%d ", matrix[2][2]);
		printf("%d ", matrix[2][0]);
		printf("%d ", matrix[1][0]);
		printf("%d ", matrix[1][1]);
		printf("%d", matrix[1][2]);

	} else if (m == 4) {
		printf("%d ", matrix[0][0]);
		printf("%d ", matrix[0][1]);
		printf("%d ", matrix[0][2]);
		printf("%d ", matrix[0][3]);
		printf("%d ", matrix[1][3]);
		printf("%d ", matrix[2][3]);
		printf("%d ", matrix[3][3]);
		printf("%d ", matrix[3][2]);
		printf("%d ", matrix[3][1]);
		printf("%d ", matrix[3][0]);
		printf("%d ", matrix[2][0]);
		printf("%d ", matrix[1][0]);
		printf("%d ", matrix[1][1]);
		printf("%d ", matrix[1][2]);
		printf("%d ", matrix[2][2]);
		printf("%d", matrix[2][1]);

	} else {
		int a[2] = {0, 0}, b[2] = {0, 3}, c[2] = {m - 1, 0}, d[2] = {m - 1, 3};
		put(a, b, c, d );
	}
	return 0;
}
