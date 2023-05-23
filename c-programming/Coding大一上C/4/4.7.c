//（1）用条件编译方法来编写程序。输入一行英文字符序列，可以任选两种方式之一输出：
//一为原文输出；二为变换字母的大小写后输出。例如小写‘a’变成大写‘A’，大写‘D’变成小写‘d’，
//其他字符不变。用#define命令控制是否变换字母的大小写。
//例如，#define CHANGE 1 则输出变换后的文字，若#define CHANGE 0则原文输出。
#include <stdio.h>
#define MAX 100
#define CHANGE_1
//#define CHANGE_0
char string[MAX];

int main(void) {
	gets(string);
#ifdef CHANGE_0
	for (int i = 0; i <= MAX - 1; i++)
		printf("%c", string[i]);
#endif
#ifdef CHANGE_1
	for (int i = 0; i <= MAX - 1; i++) {
		if (string[i] <= 'z' && string[i] >= 'a')
			printf("%c", string[i] + 'A' - 'a');
		else if (string[i] <= 'Z' && string[i] >= 'A')
			printf("%c", string[i] + 'a' - 'A');
		else
			printf("%c", string[i]);
	}
#endif
	return 0;
}
