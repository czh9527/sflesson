#include <stdio.h>
#include<math.h>
void fun(int num)
{
    char str[8]={'\0'};
    
    
    for(int i = 0;i<4;i++)
    {
       int temp =pow(10,3-i);
       str[2*i]=num/temp+'0';
       str[2*i+1]=' ';
       num=num-(num/temp)*temp;//初始化下一次的num

    }
    str[7]='\0';
    printf("\n%s\n",str);

}
int main(){

   
    fun(2021);

    

    return 0;
}