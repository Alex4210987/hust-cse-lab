//�������񣺱�д8����������һ��scheduler���Ⱥ�����һ��executeִ�к�����
//����main�����е���scheduler������scheduler����Ҫ�������ķ�ʽ����ִ���û�ָ������������
//�������task0, task1, task2, task3, task4, task5, task6, task7��8����������
//ÿ�������������������������񱻵��õ��ַ��������磬��0�������������task0 is called!����
//��1�������������task1 is called!�����Դ����ơ�
//��scheduler�������ݼ�������������ַ����Ⱥ�˳��һ�ε���ѡ���Ӧ����������
//���磬���룺1350���س�����scheduler����һ�ε���ѡ��task1, task3, taks5, task0��
//Ȼ���Ժ���ָ��������������Ϊ����������ѡ�������ݸ�execute����������execute������
//��execute��������scheduler�������ݵ�ָ��������������Ϊ����������ָ�����Ⱥ�˳�����˵���ִ��ѡ������������
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