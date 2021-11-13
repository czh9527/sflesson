#include "stdio.h"
#include <Windows.h>
#include <math.h>
int main()
{

    int a=0,b=1,c;
    for(int i=3;i<=30;i++)
    {
        c = a+b;
        if(i%3==0)
        {
            printf("%d,%d,%d\n",a,b,c);
        }
        a=b;
        b=c;
        
        
    }
   
    system("pause");
    return 0;
}
