#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *p[40], t[100];
int i = 0;
int flag = 0, flag_ = 0;

void input() {
	scanf("%d", &i);
	for (int d = 1; d <= i; d++) {
		fgets(t, 100, stdin);
		p[i] = (char *)malloc(strlen(t) + 1);
		strcpy(p[i], t);
	}
}

void delete_() {
	for (int j = 0; j < i; j++) {
		flag = 0;
		for (int k = 0; k < strlen(p[j]); k++) {
			if (flag == 0 && (*(p[j] + k) == '0' || *(p[j] + k) == '\t'))
				continue;
			if (*(p[j] + k) == ' ' && flag_ == 1) {
				continue;
			}
			if (*(p[j] + k) == ' ' && flag_ == 0) {
				flag_++;
			}
			if (*(p[j] + k) != ' ' && flag_ == 1) {
				flag_ = 0;
			}
			flag++;
			putchar(*(p[j] + k));
		}
		printf("\n");
	}
}

int main() {
	input();
	delete_();
	return 0;
}