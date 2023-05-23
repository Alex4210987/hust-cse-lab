#include<stdio.h>
#include<stdlib.h>
typedef struct typeList{
	char data;
	struct typeList* next;
}* list;
list head, p, tail;
int createList();
int main(){
	int n,i;
	char a[n+1];
	n=createList();
	p=head->next;
	while(p->next){
		printf("%c",p->data);
		p=p->next;
	}
	printf("\n");
	p=head->next;
	for(i=0;i<=n-1;i++){
		a[i]=p->data;
		p=p->next;
	}
	a[n]='\0';
	printf("%d\n%s",n,a);
}
int createList(){
	head=(list)malloc(sizeof(struct typeList));
	p=tail=head;
	char c;
	int i=0;
	while((c=getchar())!='\n'){
		tail=(list)malloc(sizeof(struct typeList));
		p=p->next=tail;
		tail->data=c;
		i++;
	}
	p=(list)malloc(sizeof(struct typeList));
	tail=tail->next=p;
	tail->data='\0';
	tail->next=NULL;
	return i;
}
