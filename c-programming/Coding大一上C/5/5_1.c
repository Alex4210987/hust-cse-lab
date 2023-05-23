#include <stdio.h>

void strcate(char [], char []);
void strdelc(char [], char );

char a[100] = "Language", b[100] = "Programming";

int main(void) {
	printf("%s %s\n", b, a);
	strcate(b, a);
	printf("%s %s\n", b, a);
	strdelc(b, 'a');
	printf("%s\n", b);
	return 0;
}

void strcate(char t[], char s[]) {
	int i = -1,  j = 0;
	while ( t[++i]) ;
	while ((t[i++] = s[j++] ) != '\0') ;
}

void strdelc(char s[], char c) {
	int j, k;
	for ( j = 0, k = 0 ; s[j] != '\0' ; j++)
		if (s[j] != c)
			s[k++] = s[j] ;
	s[k++] = 0 ;
}