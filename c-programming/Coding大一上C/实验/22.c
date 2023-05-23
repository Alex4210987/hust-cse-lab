//本关任务：从键盘输入n个整数并放到数组x中,编写一个函数,
//使用最少的辅助存储单元将数组x中的n个元素颠倒顺序，仍然
//存放在原数组中。并且在main函数中输出颠倒顺序后数组x中的各个元素。
#include <stdio.h>
#include <stdlib.h>
int *p;

void replace(int n) {
	int t;
	for (int j = 0; j <= (n / 2 - 1); j++) {
		t = *(p + j);
		*(p + j) = *(p + n - 1 - j);
		*(p + n - 1 - j) = t;
	}
}

int main() {
	int n;
	scanf("%d", &n);
	p = (int *)malloc(n * (sizeof(int)));
	for (int i = 0; i <= n - 1; i++)
		scanf("%d", p + i);
	replace(n);
	for (int i = 0; i <= n - 1; i++)
		printf("%d ", *(p + i));
}