
#include <windows.h>
#include <stdio.h>
typedef struct Str
{
  char *ch;
  int length;
}Str;

int KMP(Str str,Str  substr,int  next[])
{
     int i=1,j=1;      //串从数组下标1位置开始存储
     while(i<=str.length&&j<=substr.length)
     {
            if(j==0||str.ch[i]==substr.ch[j])//第一个不匹配,next[1]=0=j，此时走i=2 ,j=1
            {
                   ++i;
                   ++j;
             }
             else    j=next[j];
     }
     if(j>substr.length)  return  i-substr.length;         //此时j已经多++了一次
     else  return 0;
}

//next数组计算
void getnext(Str substr,int next[])
{
       
    int i=1,j=0;//i看作后缀，j看作前缀
    next[1]=0;
    while(i<substr.length)//赋值是++后的i所以是<
    { 
          if(j==0||substr.ch[i]==substr.ch[j])//前缀和后缀相等时,就比较下一个,j==0是确定next[2]=1的固定值
          {      ++i;++j;
                  next[i]=j;
          }
          else  j=next[j];//回溯上一个前缀,再重新比对,前缀是固定的，后缀是相对的
    }
}


int main()
{
  Str str;
  str.ch="0abcdfg";
  str.length=6;
  Str subStr;
  subStr.ch="0bcd";
  subStr.length=2;

  int next[3];
  getnext(subStr,next);

  int num = KMP(str,subStr,next);
  printf("index =%d\n",num);

}