

#include <stdio.h>

int main( ) {
	int i, x, k, flag = 0;
	printf("�������жϺ��������������1����������Ctrl+Z����\n");
	while (scanf("%d", &x) != EOF) {
		for (i = 2, k = x ; i < k; i++)
			if (!(x % i)) {
				flag = 1;
			}
		if (flag == 1)
			printf("%d�Ǻ���", x);
		else
			printf("%d���Ǻ���", x);
		flag = 0;
	}

	return 0;
}

//#include <stdio.h>
//
//int main( ) {
//	int i, x, k, flag = 0;
//	printf("�������жϺ��������������1����������Ctrl+Z����\n");
//	while (scanf("%d", &x) != EOF) {
//		i = 2, k = x;
//		do {
//			if (!(x % i)) {
//				flag = 1;
//			}
//			i++;
//		} while (i < k);
//		if (flag == 1)
//			printf("%d�Ǻ���", x);
//		else
//			printf("%d���Ǻ���", x);
//flag=0;
//	}
//	return 0;
//}

//#include <stdio.h>
//
//int main( ) {
//	int i, x, k, flag = 0;
//	printf("�������жϺ��������������1����������Ctrl+Z����\n");
//	while (scanf("%d", &x) != EOF) {
//		i = 2, k = x;
//		do {
//			if (!(x % i)) {
//				flag = 1;
//				break;
//			}
//			i++;
//		} while (i < k);
//		if (flag == 1)
//			printf("%d�Ǻ���", x);
//		else
//			printf("%d���Ǻ���", x);
//flag=0;
//	}
//	return 0;
//}

