#include "stdio.h"
#include <Windows.h>
#include <math.h>
int main()
{

    for (int i = 0; i <= 33; i++)
    {
        for (int j = 0; j <= 50; j++)
        {
            for (int k = 0; k <= 100; k++)
            {
                if(i+j+k==100 && i*3+2*j+k/2==100 && k%2==0)
                {
                    printf("%d,%d,%d\n",i,j,k);
                }
            }
        }
    }
    system("pause");
    return 0;
}
