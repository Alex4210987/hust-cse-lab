

#include <stdio.h>

void input(int s[], char ch[][20], int n) {
	int i;
	for (i = 0; i < n; i++) {
		scanf("%s", ch[i]);
		scanf("%d", &s[i]);
	}
}

void reorder(int s[], char ch[][20], int n) {
	int i, k, j, t;
	char a;
	for (i = 0; i <= n - 2; i++) {
		k = i;
		for (j = i + 1; j <= n - 1; j++) {
			if (s[k] < s[j]) {
				k = j;
			}
		}
		if (k != i) {
			t = s[k];
			s[k] = s[i];
			s[i] = t;
			for (int l = 0; l < 20; l++) {
				a = ch[k][l];
				ch[k][l] = ch[i][l];
				ch[i][l] = a;
			}
		}
	}
}

void output(int s[], char ch[][20], int n) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < 20 && ch[i][j] != '\0'; j++) {
			putchar(ch[i][j]);
		}
		printf(" %d\n", s[i]);
	}
}

int search(int s[], char ch[][20], int n, int score) {
	int front = 0, back = n - 1, middle;
	while (front <= back) {
		middle = (front + back) / 2;
		if (score > s[middle])
			back = middle - 1;
		else if (score < s[middle])
			front = middle + 1;
		else {
			if (score == s[middle + 1]) {
				printf("%s %d\n", ch[middle], s[middle]);
				printf("%s %d\n", ch[middle + 1], s[middle + 1]);
				return 0;
			} else if (score == s[middle - 1]) {
				printf("%s %d\n", ch[middle - 1], s[middle - 1]);
				printf("%s %d\n", ch[middle], s[middle]);
				return 0;
			} else {
				printf("%s %d\n", ch[middle], s[middle]);
				return 0;
			}

		}
	}
	printf("not found!\n");
}

int main() {
	int s[20];
	int state, n;
	char ch[20][20];
	while (scanf("%d", &state) != EOF) {
		if (state == 1) {
			scanf("%d", &n);
			input(s, ch, n);
			printf("%d records were input!\n", n);
		} else if (state == 2) {
			reorder(s, ch, n);
			printf("Reorder finished!\n");
		} else if (state == 3) {
			output(s, ch, n);
		} else if (state == 4) {
			int score;
			scanf("%d", &score);
			search(s, ch, n, score);
		} else
			return 0;
	}
}