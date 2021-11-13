#include"stdio.h"
#include<Windows.h>
void trans(int (*s)[3], int x, int y);        //定义转置函数
int main()
{
    int a[3][3], *p, i, j;
    printf("请输入: ");
    for (int i =0;i<3; i++)
    {
        for(int j =0;j<3;j++)
        {
            int input= 0;
            scanf("%d",&input);
            a[i][j]=input;
        }
    };    //输入矩阵元素
    printf("转置前:");
    for (i=0; i<3; i++) 
    {
        printf("\n");                                     //输出矩阵
        for (j=0; j<3; j++)
        printf("%d ", *(*(a+i)+j));
    }  
        
    trans(a, 3, 3); 
    printf("\n转置后:");                                                         //调用转置函数
    for (i=0; i<3; i++)                                        //输出矩阵
    {
        printf("\n");                                     //输出矩阵
        for (j=0; j<3; j++)
        printf("%d ", *(*(a+i)+j));
    } 
    system("pause");
return 0;
}
//转置函数
void trans(int (*s)[3], int x, int y)
{
    int i, j, t;
    for (i=0; i<x; i++)
        for (j=0; j<y; j++)
        {
            if(i<j)
            {
                t=*(*(s+i)+j);
                 *(*(s+i)+j)=*(*(s+j)+i);
                 *(*(s+j)+i)=t;
            }
        }
}

