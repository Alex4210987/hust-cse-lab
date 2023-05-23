#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXW 100
#define MAXL 15
char* ending="-END-\n";
char s[MAXL][MAXW];
char t[MAXL][MAXW];
int input();
void addAndOutput(int );
int main(){
    int i=input();
    addAndOutput(i);
    return 0;
}
int input(){
    int i=0;
    char* t=(char*)malloc(sizeof(char)*MAXW);
    while(1){
    	fgets(t,MAXW,stdin);
        if(strcmp(t,ending)==0)
			break;
        else{
            strcpy(s[i++],t);
        }
    }
    free(t); 
    return --i;
}
void addAndOutput(int n){
    int i=0;
    FILE* fp=fopen("assignment3.txt","w+");
    for(i=0;i<=n;i++){
    	fprintf(fp,"00%d %s",i+1,s[i]);
	}
	fclose(fp);
	if((fp=fopen("assignment3.txt","r"))==NULL) exit(-1); 
	for(i=0;i<=n;i++)
	{
		fgets(t[i],100,fp); 
	    printf("%s",t[i]);
    }
 	fclose(fp);
}
