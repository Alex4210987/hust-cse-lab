#include <stdio.h>


int main( ) {
	int i, x, k, flag1 = 0, flag2 = 0, flag3 = 0;
	for (int h = 400; h <= 999; h++) {
		x = h;
		for (i = 2, k = x ; i < k; i++)
			if (!(x % i)) {
				flag1 = 1;
			}
		x = x / 10;
		for (i = 2, k = x ; i < k; i++)
			if (!(x % i)) {
				flag2 = 1;
			}
		x = x / 10;
		for (i = 2, k = x ; i < k; i++)
			if (!(x % i)) {
				flag3 = 1;
			}
		if (flag1 && flag2 && flag3)
			printf("%d\n", h);
		flag1 = flag2 = flag3 = 0;
	}

	return 0;
}