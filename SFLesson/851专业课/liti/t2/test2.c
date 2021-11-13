#include <stdio.h>
int main()
{
    int n = 1;
    for(int i = 0; i < 5; ++i)
    {
        n++;
        n*=2;
    }
    printf("%d",n);
    return 0;
}