//本关任务：从键盘输入若干行字符（最后一行字符串为：-END-），
//将每一行加行号后保存到Project\source\C1003\assignment3.txt文件中，
//然后再将该文件的内容输出。
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXW 100
#define MAXL 15
#define ADDRESS F:\source.txt
char* ending="-END-";
char**s;
int input(char** );
void addAndOutput(char** ,int );
int main(){
    s=(char**)malloc(sizeof(char*)*MAXL);
    int i=input(s);
    addAndOutput(s,i);
    return 0;
}
int input(char** s){
    int i=0;
    char* t=(char*)malloc(sizeof(char)*MAXW);
    while(1){
    	fgets(t,MAXW,stdin);
        if(strcmp(t,ending)==0)
			break;
        else{
            s[i]=(char*)malloc(sizeof(char)*MAXW);
            strcpy(s[i++],t);
        }
    }
    return --i;
}
void addAndOutput(char**s ,int i){
    int t=0;
    FILE* fp=fopen("ADDRESS","w+");
    for(t=0;t<i;t++){
    	fprintf(fp,"00%d %s\n",i,s[i]);
	}
}
