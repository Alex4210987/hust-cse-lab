#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *strcopy(char *, const char *);

int main(void) {
	char *s1, *s2, *s3;
	printf("Input a string:\n");
	s2 = (char *)malloc(1000);
	s1 = (char *)malloc(1000);
	memset(s1, 0, 1000);
	memset(s2, 0, 1000);
	scanf("%s", s1);
	strcopy(s2, s1);
	printf("%s\n", s2);
	printf("Input a string again:\n");
	scanf("%s", s2);
	s3 = strcopy(s1, s2);
	printf("%s\n", s3);
	return 0;
}

char *strcopy(char *t, const char *s) {
	char *temp = t;
	while (*t++ = *s++) {
		continue;
	};
	t = temp;
	return t;
}