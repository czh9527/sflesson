#include <stdio.h>
#include <stdlib.h>
int MaxSum(int n,int *a)
{  
    int sum=0,b=0;
    for(int i=0;i<n;i++)
    {
         if(b>0)  b+=a[i];
         else b=a[i];
         if(b>sum)  sum=b;
    }
    return sum;
}

int main()
{
    int a[4]={24,11,-23,43};
    int sum =MaxSum(4,a);
    printf("%d\n",sum);
    return 0;
}
