#include <stdio.h>
typedef struct Str
{
    char *ch;
    int length;
}Str;
//普通匹配
int match(Str str,Str substr)
{
    int i,j;
    i=j=1;
    int k=i;
    while(i<str.length && j<substr.length)
    {
        if(str.ch[i]==substr.ch[j])
        {
            i++;
            j++;
        }
        else
        {
            i= ++k;
            j=1;
        }
        
    }
    if(j==substr.length)
    {
        return k;
    }
}


void setNext(int next[],Str subStr)
{
    int i=1;
    int j=0;
    next[1]=0;
    while (i<subStr.length)
    {
        /* code */
        if(j==0 || subStr.ch[i]==subStr.ch[j])
        {
            i++;
            j++;
            next[i]=j;
        }
        else
        {
            j= next[j];
        }
    }
    
}
int kmpMatch(Str str,Str subStr,int next[])
{
    int i,j;
    i=j=1;
    while(i<=str.length && j<= subStr.length)
    {
        if(j==0 || str.ch[i]==subStr.ch[j])
        {
            i++;
            j++;
        }
        else
        {
            j= next[j];
        }
    }
    if(j>subStr.length)
    {
        return i-subStr.length;
    }
}
int main()
{
    Str str;
    str.ch ="0abdnnfg";
    str.length=7;
    Str substr;
    substr.ch="0fg";
    substr.length=2;

    int next[3];
    setNext(next,substr);
    int num = kmpMatch(str,substr,next);
    printf("index =%d\n",num);

    return 0;
}

