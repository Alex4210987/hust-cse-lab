//��1�����������뷽������д��������һ��Ӣ���ַ����У�������ѡ���ַ�ʽ֮һ�����
//һΪԭ���������Ϊ�任��ĸ�Ĵ�Сд�����������Сд��a����ɴ�д��A������д��D�����Сд��d����
//�����ַ����䡣��#define��������Ƿ�任��ĸ�Ĵ�Сд��
//���磬#define CHANGE 1 ������任������֣���#define CHANGE 0��ԭ�������
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
