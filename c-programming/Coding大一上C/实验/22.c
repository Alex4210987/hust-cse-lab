//�������񣺴Ӽ�������n���������ŵ�����x��,��дһ������,
//ʹ�����ٵĸ����洢��Ԫ������x�е�n��Ԫ�صߵ�˳����Ȼ
//�����ԭ�����С�������main����������ߵ�˳�������x�еĸ���Ԫ�ء�
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