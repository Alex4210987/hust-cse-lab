//EXP/exp801/source.txt
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 1000
#define MAX 50
int count=0,ans=0;
void replace(char* target, char*des,char * sen);
int test(char c){
	if(c>='A'&&c<='Z') return 0;
	else if(c>='a'&&c<='z') return 0;
	else return 1;
}
int main(void)
{
    FILE* fp;
    fp = fopen("F:\\source.txt", "r+");
	if (fp == NULL) {
        printf("Can't open file.");
        exit(0);
    }
	char* s,*wt,*wd;
	s=(char*)malloc(sizeof(char)*(SIZE+1)); 
	wt=(char*)malloc(sizeof(char)*(SIZE+1)); 
	wd=(char*)malloc(sizeof(char)*(SIZE+1)); 
	fgets(s,SIZE,fp);
	fclose(fp);
	scanf("%s",wt);
	scanf("%s",wd);
	replace(wt,wd,s);
	return 0;
}
void replace(char* target, char*des,char * sen){
	char words[MAX][MAX],words1[MAX][MAX];
	char* p,*a;
	int t=1,i=0;//1 means in the mid of a word 
	p=sen;
	memset(words1[count],'\0',MAX);
	memset(words[count],'\0',MAX);
	while(*p){
		if(test(*p)&&t){
			i=0;
			if(!strcmp(words1[count],target)){
				ans++;
			}
			count++;
			memset(words1[count],'\0',MAX);
			t=0;
		}
		else if(test(*p)){
			p++;
			continue;
		}
		else{
			words1[count][i++]=*p;
			if(t==0) t=1;
		}
		p++;
	}
	printf("%d\n",ans);
	count=0;
	t=1,i=0;//1 means in the mid of a word 
	p=sen;
	while(*p){
		if(!(a=p+1)) {
			a=p;
			continue;
		}
		if(test(*p)&&t){
			i=0;
			if(!strcmp(words[count],target)){
				strcpy(words[count],des);
			}
		printf("%s",words[count]);
		printf("%c",*p);
		count++;
			memset(words[count],'\0',MAX);
			t=0;
		}
		else if(test(*p)){
			printf("%c",*p);
			p++;
			continue;
		}
		else{
			words[count][i++]=*p;
			if(t==0) t=1;
		}
		
		p++;
	}
	int k=count;
	printf("%c",*a);
}
//Do you have enough happiness to make you sweet,
// enough trials to make you strong, enough sorrow 
//to keep you human, enough hope to make you happy? 
//Always put yourself in others' shoes. If you feel 
//that it hurts you, it probably hurts the other person, too.  
