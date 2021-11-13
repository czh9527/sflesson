#include<stdio.h>
#include <windows.h>

typedef struct Str
{
  char *ch;
  int length;
}Str;


int reIndex(Str str,Str substr)
{
  int i = 1,j =1,k=i;
  while(i<=str.length&&j<=substr.length)
  {
    if(str.ch[i]==substr.ch[j])
    {
      printf("i=%d,j=%d\n",i,j);
      ++i;
      ++j;
    }
    else{
      j=1;
      i=++k;
    }
  }
  if(j>substr.length)//跳出上述循环时j多+1
  {
    return k;
  }
  else
  {
    return 0;
  }
}



int main()
{
  Str str;
  str.ch="0abcdfg";
  str.length=6;
  Str subStr;
  subStr.ch="0bcd";
  subStr.length=3;

  int num = reIndex(str,subStr);
  printf("index =%d\n",num);

}

