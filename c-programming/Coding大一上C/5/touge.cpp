#include <stdio.h>

int main(void) {
	unsigned short k;
	scanf("%d", &k);
	k = ((k >> 8) & 0x00ff) | ((k << 8) & 0xff00);
	printf("%d", k);
	return 0;
}