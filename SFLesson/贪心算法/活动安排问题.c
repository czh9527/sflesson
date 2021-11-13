#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void GreedySelector(int n,int s[],int f[],bool A[])
{
      A[1]=true;
      int j=1;
      for(int i=2;i<=n;i++)
      {
             if(s[i]>=f[j])
             { 
                  A[i]=true;
                  j=i;
             }
             else A[i]=false;
      }
}
int main()
{
      int n= 3;
      bool A[4];
      int s[4]={0,3,2,7};
      int f[4]={0,4,8,8};
      GreedySelector(n,s,f,A);
      for(int i=1;i<n+1;i++)
      {
            printf("%d ",A[i]);
      }
      return 0;
}