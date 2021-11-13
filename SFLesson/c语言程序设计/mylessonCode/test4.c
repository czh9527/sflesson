#include "stdio.h"
#include <Windows.h>
#include <math.h>
int main()
{

    double app=0.8;
    int num =2;
    double sum= 2*app;
    int i = 1;
    while(num*2 <= 100)
    {
        num *= 2;
        sum = sum+num*app;
        i++;
        printf("%d,%f,%d\n",num,sum,i);
        
    }
    printf("%f\n",sum/i);
    system("pause");
    return 0;
}
