//本关任务：编写一个程序，统计一个文本文件(英文)中字符、
//单词及句子的个数（空格和换行符不做统计），
//并按照以下格式输出结果：
//Characters: XX
//Words: XX
//Sentences: XX
//然后将结果保存到文件assignment6.txt中。
#include <stdio.h>
#include <string.h>
char filename[100];
int *getCharNum(int *total);
int isPeriod(char c);
int isBlank(char c);
int main(){
    int total[3] = {0, 0, 0};//字数、词数、句数 
	
	scanf("%s",filename); 
    FILE* fp=fopen("assignment6.txt","w");
    if(getCharNum(total)){
        fprintf(fp,"Characters:%d\nWords:%d\nSentences:%d",total[0],total[1],total[2]);
        fclose(fp);
    }else{
        printf("exit -1");
    }
    return 0;
}
int *getCharNum(int *total){
    FILE *fp;  // 指向文件的指针
    int i;  // 当前读到缓冲区的第i个字符
    char c;  // 读取到的字符
    int isLastBlank = 0;  // 上个字符是否是空格
    
    int charNum = 0;  // 字符数
    int wordNum = 0; // 单词数
    int senNum = 0; // 句子数   
    if( (fp=fopen(filename, "r")) == NULL ){
    	printf("exit -1\n");
        return NULL;
    }
	while((c=fgetc(fp))!=EOF){
		if((!isPeriod(c))&&(!isBlank(c))){
			charNum++;
			isLastBlank=0;
		} 
		else if(isPeriod(c)){
			senNum++;
			charNum++;
		} 
		else {
			if(!isLastBlank) wordNum++;
			isLastBlank = 1;
		} 
	}
	total[0]= charNum;
	total[1]= wordNum+1;
	total[2]= senNum;
    return total;
}
int isPeriod(char c){
	if((c=='.')||(c=='!')||(c=='?')) return 1;
	else return 0;
}
int isBlank(char c){
	if((c==' ')||(c=='\n')||(c=='\t')) return 1;
	else return 0;
}
