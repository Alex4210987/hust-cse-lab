//本关任务：编写8个任务函数，一个scheduler调度函数和一个execute执行函数。
//仅在main函数中调用scheduler函数，scheduler函数要求用最快的方式调度执行用户指定的任务函数。
//①先设计task0, task1, task2, task3, task4, task5, task6, task7共8个任务函数，
//每个任务函数的任务就是输出该任务被调用的字符串。例如，第0个任务函数输出“task0 is called!”，
//第1个任务函数输出“task1 is called!”，以此类推。
//②scheduler函数根据键盘输入的数字字符的先后顺序，一次调度选择对应的任务函数。
//例如，输入：1350并回车，则scheduler函数一次调度选择task1, task3, taks5, task0，
//然后以函数指针数组和任务个数为参数将调度选择结果传递给execute函数并调用execute函数。
//③execute函数根据scheduler函数传递的指针数组和任务个数为参数，按照指定的先后顺序依此调用执行选定的任务函数。
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 100
char *ptr;

int scheduler() {
	char *temp;
	int count = 0;
	ptr = (char *)malloc(MAXLEN + 1);
	memset(ptr, '\0', MAXLEN);
	temp = ptr;
	char s[MAXLEN];
	memset(s, '\0', MAXLEN);
	scanf("%s", s);
	int i = 0;
	while (s[i]) {
		*(temp++) = s[i];
		count++;
		i++;
	}
	return count;
}

void execute(int num, char *p) {
	for (int j = 1; j <= num; j++) {
		int i = *(p++) - '0';
		task(i);
	}
}

void task(int n) {
	printf("task%d is called!", n);
}

int main() {
	int j = scheduler();
	execute(j, ptr);
}