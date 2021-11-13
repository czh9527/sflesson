#include <stdio.h>
#include <stdlib.h>
void Sort(int w[],int *t,int n)
{

}
void Loading(int x[],int w[],int c,int n)
{
      int *t=(int *)malloc(sizeof(int)*(n+1));
      Sort(w,t,n);//将W重量排序初始化，t中存排序后的位置
      for(int i=1;i<=n;i++)  x[i]=0;//初始化
      for(int i=1;i<=n&&w[t[i]]<=c;i++)
      {  
          x[t[i]]=1;
          c-=w[t[i]];
      }
}
int main()
{
    int c= 80;
    int w[5]={0,12,57,48,20};
    int x[5];
    Loading(x,w,c,4);
    return 0;
}
