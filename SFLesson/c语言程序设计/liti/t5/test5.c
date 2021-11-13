#include <stdio.h>
int main()
{
    long f[30] = {1,1};
    int i;
    for ( i = 2; i < 30; i++)
    {
        f[i] = f[i-1]+f[i-2];
    }
    for ( i = 0; i < 30; i++)
    {
        if (i%3 == 0)
        {
            printf("\n");
        }
        printf("%8ld",f[i]);        //8位长整型
    }
    return 0;
    
}