//�������񣺱�дһ������ͳ��һ���ı��ļ�(Ӣ��)���ַ���
//���ʼ����ӵĸ������ո�ͻ��з�����ͳ�ƣ���
//���������¸�ʽ��������
//Characters: XX
//Words: XX
//Sentences: XX
//Ȼ�󽫽�����浽�ļ�assignment6.txt�С�
#include <stdio.h>
#include <string.h>
char filename[100];
int *getCharNum(int *total);
int isPeriod(char c);
int isBlank(char c);
int main(){
    int total[3] = {0, 0, 0};//���������������� 
	
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
    FILE *fp;  // ָ���ļ���ָ��
    int i;  // ��ǰ�����������ĵ�i���ַ�
    char c;  // ��ȡ�����ַ�
    int isLastBlank = 0;  // �ϸ��ַ��Ƿ��ǿո�
    
    int charNum = 0;  // �ַ���
    int wordNum = 0; // ������
    int senNum = 0; // ������   
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
