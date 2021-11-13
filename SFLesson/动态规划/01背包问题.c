// #include <stdio.h>
// #include <stdlib.h>
// void Knapsack(int V[],int W[],int c,int n,int dp[10][10])//n指物品数量，c指背包重量，v是那个物品的价值，w是那个物品的重量，dp是最大价值
// {      
//     int i,j;
//     for(i=0;i<=n;i++)
//     {
//         dp[i][0]=0;
//     }
//     for(i=1;i<=c;i++)
//     {
//         dp[0][i]=0;
//     }
//     for(i=1;i<=n;i++)
//     {
//         for(j=1;j<=c;j++)
//         {
//             if(j<W[i])
//             {
//                 dp[i][j]=dp[i-1][j];
//             }
//             else
//             {
//                 dp[i][j]=dp[i-1][j]>dp[i-1][j-W[i]]+V[i]?dp[i-1][j]:dp[i-1][j-W[i]]+V[i];
//             }
//         }
//     }
// }
// //物品拿还是不拿
// void Traceback(int dp[10][10],int w[],int c,int n,int *x)
// {   for(int i=1;i<=n;i++)
//     {
//         if(dp[i][c]==dp[i-1][c])  
//             x[i]=0;
//         else{
//                 x[i]=1;
//                 c-=w[i];
//             }
//     }

  
// }
// void printFlag(int *x,int n,int *V)
// {
//     int sum=0;
//     for(int i =1;i<n+1;i++)
//     {
//         printf("%d ",x[i]);
//         if(x[i]==1)
//             sum+=V[i];
//     }
//     printf("\nmaxValue=%d ",sum);
// }
// int main()
// {
//     int V[4]={1,3,5,7};
//     int W[4]={2,4,6,9};
//     int c= 10;
//     int n= 4;
//     int dp[10][10];
//     Knapsack(V,W,c,n,dp);

//         for (int i = 0; i <= n; i++){
//         for (int j = 0; j <= c; j++){
//             printf("%d\t ", dp[i][j]);
//             if (j == c){
//                 printf("\n");
//             }
//         }
//     }
//     // int x[10];

    
//     // Traceback(dp,W,c,n,x);
//     // printFlag(x,n,V);


//     return 0;
// }


#include<stdio.h>
#include<stdlib.h>
int V[200][200];//前i个物品装入容量为j的背包中获得的最大价值
int Max(int a, int b)
{
    if (a >= b)
        return a;
    else return b;
}

int KnapSack(int n, int w[], int v[], int x[], int C)
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


    // int i, j;
    // for (i = 0; i <= n; i++)
    //     V[i][0] = 0;
    // for (j = 0; j <= C; j++)
    //     V[0][j] = 0;
    // for (i = 0; i < n; i++){
    //     for (j = 0; j < C+1; j++){
    //         if (j<w[i])
    //             V[i][j] = V[i - 1][j];
    //         else
    //             V[i][j] = Max(V[i - 1][j], V[i - 1][j - w[i]] + v[i]);
    //     }
    // }
    j = C;
    for (i = n - 1; i >= 0; i--)
    {
        if (V[i][j]>V[i - 1][j])
        {
            x[i] = 1;
            j = j - w[i];
        }
        else
            x[i] = 0;
    }
    printf("选中的物品是:\n");
    for (i = 0; i<n; i++)
        printf("%d ", x[i]);
    printf("\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < C+1; j++){
            printf("%d\t ", V[i][j]);
            if (j == C){
                printf("\n");
            }
        }
    }
    return V[n - 1][C];

}

int main()
{
    int s;//获得的最大价值
    int w[4] = {1,3,5,7};//物品的重量
    int v[4] = {2,4,6,9};//物品的价值
    int x[4];//物品的选取状态
    int n = 4;
    int C=10;//背包最大容量

    s = KnapSack(n, w, v, x, C);

    printf("最大物品价值为:\n");
    printf("%d\n", s);
    system("pause");
    return 0;

}