//测试输入：
//3 5        // m和n
//1 2 6 7 7
//3 5 8 8 6
//4 9 9 5 4
//预期输出：
//1 2 3 4 5 6 7 8 9 9 8 7 6 5 4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int m, n;
void replace_1(char **s) {
	char odd = 1;

	for (int i = 1; i <= m - 1; i++, odd++) {
		for (int j = 1; j <= i; j++) {
			if (odd % 2 == 1)
				printf("%c ", *(s[i - j] + j - 1));
			else
				printf("%c ", *(s[j - 1] + i - j));
		}
	}

	for (int i = m; i <= n; i++, odd++ ) {
		for (int j = 1; j <= m; j++) {
			if (odd % 2 == 1)
				printf("%c ", *(s[m - j] + j + i - m - 1));
			else
				printf("%c ", *(s[j - 1] + i - j));
		}
	}

	for (int i = n + 1; i <= n + m - 1; i++, odd++) {
		for (int j = 1; j <= m + n - i; j++) {
			if (i == n + m - 1 && j == m + n - 1) {
				if (odd % 2 == 1)
					printf("%c", *(s[m - j] + i + j - m - 1));
				else
					printf("%c", *(s[j - n + i - 1] + n - j));
			} else {
				if (odd % 2 == 1)
					printf("%c ", *(s[m - j] + i + j - m - 1));
				else
					printf("%c ", *(s[j - n + i - 1] + n - j));
			}

		}
	}
}
void replace_2(char **s) {
	char odd = 1;

	for (int i = 1; i <= n - 1; i++, odd++) {

		for (int j = 1; j <= i; j++) {
			if (odd % 2 == 1)
				printf("%c ", *(s[i - j] + j - 1));
			else
				printf("%c ", *(s[j - 1] + i - j));
		}
	}

	for (int i = n; i <= m; i++, odd++ ) {

		for (int j = 1; j <= m; j++) {
			if (odd % 2 == 1)
				printf("%c ", *(s[i - j] + j - 1));
			else
				printf("%c ", *(s[j - n + i - 1] + n - j));
		}
	}

	for (int i = m + 1; i <= n + m - 1; i++, odd++) {

		for (int j = 1; j <= i - n; j++) {
			if (i == n + m - 1 && j == m + n - 1) {
				if (odd % 2 == 1)
					printf("%c", *(s[m - j]) + j - m + i - 1);
				else
					printf("%c", *(s[j - n + i - 1] + n - j));
			} else {
				if (odd % 2 == 1)
					printf("%c ", *(s[m - j]) + j - m + i - 1);
				else
					printf("%c ", *(s[j - n + i - 1] + n - j));
			}

		}
	}
}
int main() {
	char **str;
	char temp;
	int t = 0, count = 0;
	scanf("%d%d", &m, &n);
	str = (char **)malloc(m + 1);
	int array[m + 1][n + 1];
	for (int i = 1; i <= m; i++) {
		str[i - 1] = (char *)malloc(n + 1);

		for (int j = 1; j <= n; j++) {
			scanf("%d", &array[i][j]);
			*(str[i - 1] + j - 1) = array[i][j] + '0';
		}
	}
	if (n >= m)
		replace_1(str);
	else
		replace_2(str);
	return 0;
}