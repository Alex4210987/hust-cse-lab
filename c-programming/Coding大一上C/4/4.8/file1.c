#include "file.h"
void func1(void);
int x, y;
char ch;

int main(void) {
	x = 10;
	y = 20;
	ch = getchar();
	printf("in file1 x=%d,y=%d,ch is %c\n", x, y, ch);
	func1();
	return 0;
}
