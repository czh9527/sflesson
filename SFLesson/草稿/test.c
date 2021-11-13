#include<stdio.h>
#include <stdlib.h>

void set(int (*a)[10])
{
    


}

int main()
{
    int a[10][10];
    a[1][1]=22;
    set(a);
    printf("%d\n",a[1][1]);
    return 0;
}
