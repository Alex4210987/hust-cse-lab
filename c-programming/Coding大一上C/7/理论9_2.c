//����������������ѧ���Ľṹ��������Ϊ��
//�����������
//��1����������n��������n��Ԫ�صĽṹ����s��������г�ʼ����
//ͬʱ����ṹָ��p��ʹ��ָ��s�����һ��Ԫ�أ�
//��2������ָ��p���������������Ԫ�صĸ���Աֵ֮��
//��3����ָ��p�������������������Ԫ�صĸ���Աֵ֮��
#include<stdio.h>
#include<stdlib.h>
typedef struct typeStudent {
    int num;        // ѧ�� 
    char name[12];  // ���� 
    int score;   // �ɼ� 
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

