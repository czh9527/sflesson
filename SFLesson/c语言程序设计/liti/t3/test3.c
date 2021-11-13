#include <stdio.h>

int main()
{
    for (int i = 0; i <= 35; ++i)
    {
        for (int j = 0; j <= 50; ++j)
        {
            for (int k = 0; k <= 100; ++k)
            {
                if (((100 - 3*i - 2*j)*2 == k)&&(i+j+k == 100))
                {
                    printf("%d %d %d\n", i,j,k);
                }
                
            }
            
        }
        
    }
    return 0;
    
}