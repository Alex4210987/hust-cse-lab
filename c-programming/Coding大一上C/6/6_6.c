#include "stdio.h"
char *strcpy(char *, char *);

void main(void) {
	char a[20], b[60] = "there is a boat on the lake.";
	printf("%s\n", strcpy(a, b));
}

char *strcpy(char *s, char *t) {
	char *temp = s;
	while (*s++ = *t++);
	return (temp);
}
