#include <stdio.h>
#include "string.h"
#include "stdlib.h"
#define MAXLINES 5
#define MAXLEN 100
char *lines[MAXLINES];

int read() {
	int i = 0, nline;
	char t[MAXLEN];
	scanf("%d", &nline);
	fgets(t, MAXLEN, stdin);
	for (int i = 0; i < nline; i++) {
		fgets(t, MAXLEN, stdin);
		lines[i] = (char *)malloc(strlen(t) + 2);
		strcpy(lines[i], t);
		lines[i][strlen(t) + 1] = '\0';
	}
	return nline;
}

void myDelete(char *s[], int num) {
	int i, j = 0, fflag, count = 0;
	char temp[MAXLEN], result[MAXLEN];

	for (i = 1; i <= num; i++) {
		strcpy(temp, s[i - 1]);
		fflag = 0;
		while (temp[j] != 0) {
			if (!fflag) {
				while (temp[j] == ' ' || temp[j] == '\t') {
					j++;
				}
				count++;
				result[count - 1] = temp[j];
				fflag = 1;
				j++;
				continue;
			}
			if (temp[j] == ' ') {
				while (temp[j] == ' ') {
					j++;
				}
				count++;
				result[count - 1] = ' ';
				count++;
				result[count - 1] = temp[j];
				j++;
				continue;
			}
			count++;
			result[count - 1] = temp[j];
			j++;
		}
		result[count] = '\0';
		lines[i - 1] = (char *)malloc(MAXLEN + 2);
		strcpy(lines[i - 1], result);
		j = 0;
		for (int j = 1; j <= count; j++) {
			result[j - 1] = '\0';
		}
		count = 0;
	}
}

int main() {
	int nline;
	nline = read();
	myDelete (lines, nline);
	for (int i = 1; i <= nline; i++) {
		printf("%s", lines[i - 1]);
	}
	return 0;
}

