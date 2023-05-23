#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 4

/*对指针数组s指向的size个字符串进行升序排序*/
void strsort(char **s, int size) {
	char *temp ;
	int i, j;

	for (i = 1; i < size; i++) {
		for (j = 1; j <= size - i; j++) {
			char *str1, *str2;
			str1 = *s;
			str2 = *(++s);
			if ( strcmp( str1, str2) > 0 ) {
				temp = str1;
				str1 = str2 ;
				str2 = temp;
			}
			*s = str2;
			*(--s) = str1;
			s++;
		}
		for (j = 1; j <= size - i; j++) {
			s--;
		}
	}
}

int main() {
	int i;
	char *s[N], t[50];

	for ( i = 0 ; i < N ; i++) {
		gets(t);
		s[i] = (char *)malloc(strlen(t) + 1);
		strcpy( s[i], t );
	}
	strsort( s, N );

	for (i = 0; i < N; i++)	{
		puts(s[i]);
		free(s[i]);
	}
	return 0;
}
