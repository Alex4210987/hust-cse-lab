//本关任务：设有描述学生的结构类型声明为：
//请编程完成任务：
//（1）输入整数n，定义有n个元素的结构数组s并对其进行初始化。
//同时定义结构指针p并使其指向s的最后一个元素；
//（2）不用指针p，依次输出各数组元素的各成员之值。
//（3）用指针p，依次逆序输出各数组元素的各成员之值。
#include<stdio.h>
#include<stdlib.h>
typedef struct typeStudent {
    int num;        // 学号 
    char name[12];  // 姓名 
    int score;   // 成绩 
}student;
int main(){
	int n;
	scanf("%d",&n);
	student s[n];
	student *p=&s[n-1];
	int i;
	for(i=0;i<=n-1;i++){
		scanf("%d",&s[i].num);
		scanf("%s",s[i].name);
		scanf("%d",&s[i].score);
	}
	for(i=0;i<=n-1;i++){
		printf("%d ",s[i].num);
		printf("%s ",s[i].name);
		printf("%d\n",s[i].score);
	}
	while(n){
		printf("%d ",p->num);
		printf("%s ",p->name);
		printf("%d\n",p->score);
		n--;
		p--;
	}
}

