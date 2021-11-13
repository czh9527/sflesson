#include <stdio.h>
//将x通过y移动到z
void hanoi(int n,char x,char y,char z)
{
    if(n==1)
    {
        printf("%c--->%c\n",x,z);
    }
    else
    {
        hanoi(n-1,x,z,y);//将n-1方块从x通过z移动到y
        printf("%c--->%c\n",x,z);//将第n个方块从x移动到z

        hanoi(n-1,y,x,z);//将n-1个方块从y移动到z

    }
}

int main()
{
    hanoi(3,'x','y','z');
    return 0;
}