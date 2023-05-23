#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLEN 100

int atoh(char *nstr) {
	int r = 0, digit = 1;
	int j = 0;
	while (*++nstr) {
		j++;
	};
	nstr--;
	j--;
	while (j) {
		if (*nstr >= '0' && *nstr <= '9')
			r += digit * (*nstr - '0');
		else if (*nstr >= 'A' && *nstr <= 'F')
			r += digit * (*nstr - 'A' + 10);
		else if (*nstr >= 'a' && *nstr <= 'f')
			r += digit * (*nstr - 'a' + 10);
		digit *= 16;
		nstr--;
		j--;
	}
	return r;
}

int main(void) {
	int n;
	scanf("%d", &n);
	char **str;
	str = (char **)malloc(n + 1);
	for (int i = 1; i <= n; i++) {
		str[i - 1] = (char *)malloc(MAXLEN + 1);
		memset(str[i - 1], '\0', MAXLEN + 1);
		scanf("%s", str[i - 1]);
		int j = atoh(str[i - 1]);
		if (i != n)
			printf("%d\n", j);
		printf("%d", j);
		j = 0;
	}
	return 0;
}