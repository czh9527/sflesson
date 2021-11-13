#include <stdio.h>
void Adjust(int A[],int n){
    int i =0,j=n-1,temp;
    while(i<j)
    {
        while(A[i]%2 !=0 && i<j) i++;
        while(A[j]%2==0&&i<j)j--;
        if(i<j)
        {
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
            i++;j--;
        }
    }
    for(int i =0;i<5;i++)
    {
        printf("%d ",A[i]);
    }
}
int main()
{
    int A[5]={8,3,2,9,5};
    Adjust(A,5);

    
}