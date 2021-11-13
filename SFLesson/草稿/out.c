#include <stdio.h>
#include <stdlib.h>
#include <math.h>
long int getNum(int n)//算n的阶乘
{
    long int sum=1;
    for(int i = 1;i<=n;i++)
    {
        sum *= i;
    }
    return sum;
} 

int main()
{
    double inputNum;
    printf("请输入一个实数[0,5]:");
    scanf("%lf",&inputNum);
    double sum=0;
    for(int i= 0;fabs(pow(inputNum,i)/getNum(i))>=0.00001;i++)
    {
        sum +=pow(inputNum,i)/getNum(i);
    }

    printf("\n%0.4lf\n",sum);
    return 0;
}