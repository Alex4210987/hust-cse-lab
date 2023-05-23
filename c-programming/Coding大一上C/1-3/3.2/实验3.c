//假设工资税金按以下方法计算：x ＜ 1000元，不收取税金；

//1000 ≤ x ＜ 2000，收取5%的税金；2000 ≤ x ＜ 3000，收取10%的税金；
//3000 ≤ x ＜ 4000，收取15%的税金；4000 ≤ x ＜ 5000，收取20%的税金；
//5000 ≤ x，收取25%的税金。（注意税金的计算按照阶梯计税法，
//比如，工资为4500，那么税金=1000*5% + 1000*10% + 1000*15% + 501*20%）。
//编写一个程序,输入工资金额，
//输出应收取税金额度，要求分别用if语句和switch语句来实现。
//#include <stdio.h>
//int x;
//
//int main() {
//	scanf("%d", &x);
//	int i = x / 1000;
//	double ans = 0;
//	if (i == 1)
//		ans = (x - 1000) * 0.05;
//	else if (i == 2)
//		ans = 50 + (x - 2000) * 0.1;
//	else if (i == 3)
//		ans = 150 + (x - 3000) * 0.15;
//	else if (i == 4)
//		ans = 300 + (x - 4000) * 0.20;
//	else
//		ans = 500 + (x - 5000) * 0.25;
//	printf("%lf", ans);
//	return 0;
//}

#include <stdio.h>
int x;

int main() {
	scanf("%d", &x);
	int i = x / 1000;
	double ans = 0;
	switch (i) {
		case 1:
			ans = (x - 1000) * 0.05;
			break;
		case 2:
			ans = 50 + (x - 2000) * 0.1;
			break;
		case 3:
			ans = 150 + (x - 3000) * 0.15;
			break;
		case 4:
			ans = 300 + (x - 4000) * 0.20;
			break;
		default:
			ans = 500 + (x - 5000) * 0.25;
			break;
	}

	printf("%lf", ans);
	return 0;
}
