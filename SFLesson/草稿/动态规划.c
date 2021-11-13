
#include<stdio.h>
#include<stdlib.h>
// int V[200][200];//前i个物品装入容量为j的背包中获得的最大价值
int Max(int a, int b)
{
    if (a >= b)
        return a;
    else return b;
}

void  KnapSack(int n, int w[], int v[], int x[], int C,int V[100][100])
{

    int i,j;
    for(i=0;i<n;i++)
    {
        V[i][0]=0;
    }
    for(i=0;i<=C;i++)
    {
        V[0][i]=0;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<=C;j++)
        {
            if(j<w[i])
            {
                V[i][j]=V[i-1][j];
            }
            else
            {
                V[i][j]=V[i-1][j]>V[i-1][j-w[i]]+v[i]?V[i-1][j]:V[i-1][j-w[i]]+v[i];
            }
        }
    }



}
//物品拿还是不拿
void Traceback(int dp[100][100],int w[],int c,int n,int *x)
{   
    
    for(int i=n-1;i>0;i--)
    {
        if(dp[i][c]==dp[i-1][c])  
            x[i]=0;
        else{
                x[i]=1;
                c-=w[i];
            }
    }
    
}
void printFlag(int x[],int n,int *V)
{
    int sum=0;
    for(int i =1;i<n;i++)
    {
        printf("%d ",x[i]);
        if(x[i]==1)
            sum+=V[i];
    }
    printf("\nmaxValue=%d ",sum);
}
int main()
{
    int s;//获得的最大价值
    int w[5] = {0,1,3,5,7};//物品的重量
    int v[5] = {0,2,4,6,9};//物品的价值
    int x[10];//物品的选取状态
    int n = 5;
    int C=13;//背包最大容量
    int V[100][100];
    KnapSack(n, w, v, x, C,V);
        printf("\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= C; j++){
            printf("%d\t ", V[i][j]);
            if (j == C){
                printf("\n");
            }
        }
    }
 
 
    // int x[10];

    
    Traceback(V,w,C,n,x);
    printFlag(x,n,v);
    return 0;

}