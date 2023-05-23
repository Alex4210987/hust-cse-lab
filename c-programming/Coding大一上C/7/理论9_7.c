#include<stdio.h>
#include<stdlib.h>
#include <string.h> 
#define MAX 100
struct Web {
    char abbr[MAX];//ËõÂÔ
	char website[MAX];//ÍøÖ· 
	char name[MAX];//È«Ãû 
};
struct Web web[MAX];
void swap(int a,int b){
	struct Web t;
	t=web[a];
	web[a]=web[b];
	web[b]=t;
}
void sortByabbr(int n){
	int i,j;
	for(i=0;i<=n-2;i++){
		for(j=0;j<=n-2;j++){
			if(strcmp(web[j].website,web[j+1].website)>0) swap(j,j+1);
		}
	}
	return ;
}
int search(char* t,int n){
	int i;
	for(i=0;i<=n-1;i++)
		if(strcmp(web[i].website,t)==0) return i;
	return -1;
}
int main(){
	int n,i;
	scanf("%d",&n);
	for(i=0;i<=n-1;i++){
		scanf("%s%s%s",web[i].abbr,web[i].website,web[i].name);
	}
	char* target=(char*)malloc(sizeof(char)*MAX);
	scanf("%s",target);
	sortByabbr(n);
	for(i=0;i<=n-1;i++){
		printf("%s %s %s\n",web[i].abbr,web[i].website,web[i].name);
	}
	int ans=search(target,n);
	printf("%s",web[ans].abbr);
	return 0;
}


