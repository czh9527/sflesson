#include "stdio.h"
#include <Windows.h>
#include <math.h>
int main()
{

    int sum[10][10] = {0};

    for (int i = 0; i < 10; i++)
    {
        sum[i][0] = 1;
        sum[i][i] = 1;
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {

            if (i > 0 && j > 0)
                sum[i][j] = sum[i - 1][j - 1] + sum[i - 1][j];
        }
    }
    for (int i = 0; i < 10; i++)
    { 
        printf("\n");
        for (int j = 0; j < 10; j++)
        {
            printf("%5d ", sum[i][j]);
        }
    }

    system("pause");
    return 0;
}
