#include <stdio.h>
#include <stdlib.h>

char *strncpy(char *s, const char *t, int n) {
	char *tmp = s;
	while (n--) {
		if ((*tmp = *t) != 0)
			t++;
		tmp++;
	}
	return s;
}

int main() {
	char *s, *t;
	int n;
	s = (char *)malloc(1000);
	t = (char *)malloc(1000);
	scanf("%s%s%d", s, t, &n);
	printf("%s", (strncpy(s, t, n)));
}