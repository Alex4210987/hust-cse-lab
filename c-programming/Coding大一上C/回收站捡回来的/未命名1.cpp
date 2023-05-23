 #include <stdio.h>
 #include<stdlib.h>
 typedef struct typeList{
 	char data;
 	struct typeList* next;
 }* Node;
 char ans[100];
 Node head,p,tail=NULL;
 int createList(char* s){
 	head=(Node)malloc(sizeof(struct typeList));
 	p=tail=head;
 	int i=0;
 	while(*s){
 		tail=(Node)malloc(sizeof(struct typeList));
 		p=p->next=tail;
 		tail->data=*s++;
 		i++;
 	}
 	p=(Node)malloc(sizeof(struct typeList));
 	tail=tail->next=p;
 	tail->data='\0';
 	tail->next=NULL;
 	return i;
 }
 void delete_s(Node s,char c){
     Node bfr,aft;
     bfr=aft=s;
     int i=0;
     while(bfr->data){
         aft=aft->next;
         while(aft->data==c&&aft->next->data){
         	aft=aft->next;
 		}
 		bfr->next=aft;
 		bfr=aft;
 		if(bfr->data!='\n') 
 			ans[i++]=bfr->data;
     }
     ans[i]='\0';
 }
 int main()
 {
     char string[100],c;
	 int i=0;
	 while((c=getchar())!='\n'){
	 	string[i++]=c;
	 } 
     createList(string);
     getchar();
     delete_s(head,getchar());
     printf("%s",ans);
     return 0;
 }
