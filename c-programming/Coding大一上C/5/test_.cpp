
#include<stdio.h>

int N; // ȫ�ֱ�����N�ʺ�����Ļʺ����

// �жϵ�row�еĵ�column�з��õĻʺ��Ƿ��ǰ���ѷ��õĻʺ��ͻ
bool isConflict(int row, int column, int *flag)
{
    // �жϵ�ǰ���Ƿ��������ʺ�
    for(int i=0; i<row; i++)
    {
        if(flag[i] == column)
            return true;
    }
    
    // �ж����϶Խ���
    for(int i=row-1, j=column-1; i>=0 && j>=0; i--, j--)
    {
        if(flag[i] == j)
            return true;
    }
    
    // �ж����¶Խ���
    for(int i=row-1, j=column+1; i>=0 && j<N; i--, j++)
    {
        if(flag[i] == j)
            return true;
    }
    
    return false;
}

// ���ݽ��N�ʺ�����
void NQueens(int row, int *flag)
{
    if(row == N)
    {
        // ��ӡ��һ�ֿ��еķ��÷���
        for(int i=0; i<N; i++)
            printf("%d ", flag[i]);
        printf("\n");
        return;
    }
    
    for(int i=0; i<N; i++)
    {
        if(!isConflict(row, i, flag))
        {
            flag[row] = i;
            NQueens(row + 1, flag);
        }
    }
}

// ������
int main()
{
    printf("������ʺ�ĸ�����\n");
    scanf("%d", &N);
    
    int flag[N];
    NQueens(0, flag);
    
    return 0;
}
