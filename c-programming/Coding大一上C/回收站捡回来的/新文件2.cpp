#include <stdio.h>

int main(void) {
	char a;
	int b;
	scanf("%c", &a);
	if (a <= '9' && a >= '0') {
		putchar(a);
	} else if (a - 'a' <= 5) {
		b = (int)a - 'a' + 10;
		printf("%d", b);
	} else if (a - 'A' <= 5) {
		b = (int)a - 'A' + 10;
		printf("%d", b);
	}
	return 0;
}