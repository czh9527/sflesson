#include <stdio.h>
int main()
{
    int y[10][10]={0},i,j;
    for ( i = 0; i < 10; i++)
    {
        y[i][0] = 1;
        y[i][i] = 1;
    }
    
    for ( i = 2; i < 10; i++)          //开始计算杨辉三角
    {
        for ( j = 1; j <= i-1; j++)
        {
            y[i][j] = y[i-1][j] + y[i-1][j-1];
        }
          
    }
    for ( i = 0; i < 10; i++)         //打印杨辉三角
    {
        for ( j = 0; j < 10; j++)
        {
            printf("%5d",y[i][j]);
        }
        printf("\n");
    }
    
}