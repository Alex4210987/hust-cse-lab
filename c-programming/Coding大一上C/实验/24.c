#include <stdio.h>
#include <stdlib.h>
#define RC 5
int **matrix;
int isMatrix(int **p) {

	if (p[0][0] + p[1][1] + p[2][2] + p[3][3] + p[4][4] == 5) {
		int j = 0;
		for (int i = 0; i <= 4; i++) {
			for (int k = 0; k <= 4; k++)
				j += p[i][k];
		}
		if (j == 5)
			return 1;
		else
			return 0;
	} else
		return 0;
}

int main() {
	matrix = (int **)malloc(RC * RC * sizeof(int));

	for (int i = 0; i <= 4; i++) {
		matrix[i] = (int *)malloc(RC * sizeof(int));
		for (int k = 0; k <= 4; k++)
			scanf("%d", &matrix[i][k]);
	}
	int j = isMatrix(matrix);
	printf("%d", j);
	return 0;
}