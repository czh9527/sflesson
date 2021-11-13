
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//循环赛日程
void Table(int k,int a[][100])//有2的k次方个选手
{
       int n=1;
       for(int i=1;i<=k;i++)    n*=2;//有n位选手
       for(int i=1;i<=n;i++)    a[1][i]=i;
       int m=1;//m代表步长
       for(int s=1;s<=k;s++)
       {
             n/=2;
             for(int t=1;t<=n;t++)//循环给n位选手确定日程
                 for(int  i=m+1; i<=2*m;i++)
                     for(int j=m+1;j<=2*m;j++)//二维数组
                     {  
                          a[i][j+(t-1)*m*2]=a[i-m][j+(t-1)*m*2-m];//
                          a[i][j+(t-1)*m*2-m]=a[i-m][j+(t-1)*m*2];
                     }
             m*=2;//结束后步长扩大
       }
}
void gen(int x,int y ,int d,int a[][100])
{
    for(int i=0;i<=d-1;i++)
    {
        for(int j=0;j<=d-1;j++)
        {
            a[x+i][y+j+d]=a[x+i][y+j]+d;
        }
    }
}
void cpy(int x,int y,int d,int z,int f,int a[][100])
{
    for(int i = 0;i<=d-1;i++)
    {
        for(int j =0;j<=d-1;j++)
        {
            a[z+i][f+j]=a[x+i][y+j];
        }
    }
}
void mTable(int a[][100],int k)
{
    a[1][1]=1;
    int d= 0;
    for(int i= 0;i<k;i++)
    {
        d= pow(2,i);
        gen(1,1,d,a);
        cpy(1,1+d,d,1+d,1,a);
        cpy(1,1,d,1+d,1+d,a);
    }

}

void printData(int a[][100],int k)
{
    for(int i= 1;i<pow(2,k)+1;i++)
    {
        for(int j = 1;j<pow(2,k)+1;j++)
        {
            printf("%3d ",a[i][j]);

        }
        printf("\n");
    }
}
int  main()
{
    int a[100][100];
    // Table(3,a);
    int m =4;
    mTable(a,m);
    printData(a,m);
    return 0;
}

