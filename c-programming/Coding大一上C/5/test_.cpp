
#include<stdio.h>

int N; // 全局变量，N皇后问题的皇后个数

// 判断第row行的第column列放置的皇后是否和前面已放置的皇后冲突
bool isConflict(int row, int column, int *flag)
{
    // 判断当前列是否有其他皇后
    for(int i=0; i<row; i++)
    {
        if(flag[i] == column)
            return true;
    }
    
    // 判断正上对角线
    for(int i=row-1, j=column-1; i>=0 && j>=0; i--, j--)
    {
        if(flag[i] == j)
            return true;
    }
    
    // 判断正下对角线
    for(int i=row-1, j=column+1; i>=0 && j<N; i--, j++)
    {
        if(flag[i] == j)
            return true;
    }
    
    return false;
}

// 回溯解决N皇后问题
void NQueens(int row, int *flag)
{
    if(row == N)
    {
        // 打印出一种可行的放置方案
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

// 主函数
int main()
{
    printf("请输入皇后的个数：\n");
    scanf("%d", &N);
    
    int flag[N];
    NQueens(0, flag);
    
    return 0;
}
