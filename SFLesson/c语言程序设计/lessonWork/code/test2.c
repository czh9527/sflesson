#include <stdio.h>
#define NUM 6
#include <string.h>
void fun(int x, int pp[], int *n)
{
    int newPP[NUM]={0};
    int temp = 0;
    int j =0;
     printf("能整除x的数有:");
    for(int i =0;i<NUM;i++)
    {
       
        if(pp[i]%x==0)
        {
            printf("%d,",pp[i]);
            j++;
        }  
        
    }
    *n=j;
    for(int i =0;i<NUM;i++)
    {
        for(j =i+1;j<NUM;j++)
        {
            if(pp[i]>pp[j])
            {
                temp=pp[i];
                pp[i]=pp[j];
                pp[j]=temp;
            }
        }
    }
    


}
int main(){

    int pp[NUM]={3,67,45,69,34,65};

    int x = 3;
    int * n =&x;
    fun(x,pp,n);

    printf("\n有%d个数\n",*n);
    printf("排序后为:");

    for(int i =0;i<NUM;i++)
    {
        printf("%d,",pp[i]);

    }

    return 0;
}