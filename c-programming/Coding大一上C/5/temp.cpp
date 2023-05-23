#include <stdio.h>
#include <math.h>

//540 1548 2563 3676 16555      959 2751 5005  8582 9975
int main(void) {
	int i;
	int count = 0, flag = 0;
	while (count <= 10) {
		scanf("%d", &i);
		if (i > 10000)
			continue;
		int digit = log(i) / log(10) + 1;
		if (i % 7 == 0) {
			for (int j = 1; j <= digit; j++) {
				int t = ((int)(i / pow(10, j))) * pow(10, j);
				int g = (i - t) / pow(10, j - 1);
				if (g == 5) {
					printf("%d ", i);
					flag = 1;
					break;
				}
			}
		}
		count++;
	}
	if (flag == 0)
		printf("0");
	return 0;
}