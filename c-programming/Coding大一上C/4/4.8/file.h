#include <stdio.h>
extern int x, y;
extern char ch;
extern void func1(void);

void func1(void) {
	x++;
	y++;
	ch++;
	printf("in file2 x=%d,y=%d,ch is %c\n", x, y, ch);
}