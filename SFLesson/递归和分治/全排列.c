//全排列
#include <stdio.h>
void swap(int *i,int *j)
{
    int temp = *i;
    *i=*j;
    *j=temp;
}
void Perm(int R[],int k,int m)  //k是从数组那个元素开始，m指数组最后一位下标
{
      if(k==m)     //只剩下一个元素
      {
            for(int i=0;i<=m;i++)   printf("%d",R[i]);
            printf("\n");
            return;
      }
      else
      {    for(int i=k;i<=m;i++)
            {  
                swap(&R[k],&R[i]);
                Perm(R,k+1,m);
                swap(&R[k],&R[i]);
            } 
      }
}

int main()
{
    int k[5]={5,3,2,1,4};
    Perm(k,3,4);
}
