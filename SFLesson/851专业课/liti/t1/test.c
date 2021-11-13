#include <stdio.h>
#include <math.h>
int main()
{
    int a, b, c;
    for (int i = 100; i < 1000; ++i)
    {
        a = i/100;                   //取百位的数字
        b = (i/10)%10;               //取十位上的数字
        c = i%10;                    //取个位上的数字
        int A =pow(a,3);
        int B =pow(b,3);
        int C =pow(c,3);
        if (A + B + C == i)          //a*a*a+b*b*b+c*c*c
        {
            printf("%d\n",i);
        }
        
    }
    return 0;
    
}