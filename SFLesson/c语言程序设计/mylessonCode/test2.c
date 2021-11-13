#include"stdio.h"
#include<Windows.h>
#include<math.h>
int main()
{
    int num = 1;
    for(int i =1;i<6;i++)
    {
        num=(++num)*2;
    }
    printf("%d\n",num);
    system("pause");
return 0;
}


