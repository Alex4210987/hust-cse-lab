#include "stdio.h"

int main(void) {
	char ch;
	int num = 0, letter = 0, other = 0, i = 0;
	while (1) {
		if ((ch = getchar()) >= '0' && ch <= '9')
			num++;
		else if (ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z')
			letter++;
		else if (ch == '\n' || ch == EOF)
			break;
		else
			other++;
	}
	printf("%d %d %d", num, letter, other);
	return 0;
}