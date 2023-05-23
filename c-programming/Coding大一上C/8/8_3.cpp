//#include<stdio.h>
//#include<stdlib.h>
//int main(int argc, char* argv[])
//{
//	char ch;
//	FILE *fp;
//	if(argc!=2){
//		printf("Arguments error!\n");
//		exit(-1);
//	}
//	if((fp=fopen(argv[1],"r"))==NULL){       /* fp ָ�� filename */
//		printf("Can't open %s file!\n",argv[1]);
//		exit(-1);
//	}
//
//	while((ch=fgetc(fp))!=EOF)          /* ��filename�ж��ַ� */
//	   putchar(ch);                  /* ����ʾ����д�ַ� */
//	fclose(fp);                      /* �ر�filename */
// return 0;	
//}
#include<stdio.h>
#include<stdlib.h>
int main(int argc , char* argv[])
{
	char ch;
	FILE *fp;
	if(argc!=2)
    {
		printf("Arguments error!\n");
		exit(-1);
	}
	if((freopen(argv[1],"r",stdin))==NULL)
    {       /* fp ָ�� filename */
		printf("Can't open %s file!\n",argv[1]);
		exit(-1);
	}

	while((ch=getchar())!=EOF)          /* ��filename�ж��ַ� */
	   putchar(ch);                  /* ����ʾ����д�ַ� */
    return 0;	
}


