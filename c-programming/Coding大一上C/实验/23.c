#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 100

char *Mystrcpy(char *s, char *t, int n) {
	char *temp;
	temp = s;
	while (*(temp++));
	temp--;
	for (int i = 0; i <= n - 1; i++) {
		*(temp + i) = *(t + i);
	}
	return s;
}

int main(void) {
	char *s, *t, *temp;
	int n;
	s = (char *)malloc(MAXLEN + 1);
	t = (char *)malloc(MAXLEN + 1);
	memset ( s, '\0', MAXLEN + 1 );
	memset ( t, '\0', MAXLEN + 1 );
	scanf("%s%s%d", s, t, &n);
	printf("%s", Mystrcpy(s, t, n));
	return 0;
}