#include <stdio.h>
int abs(int a)
{  return a>0?a:-a;
}
int Queens[8]={0};//8个皇后应该放哪儿的数组
int counts=0;
int Check(int ch,int cl)
{//遍历该行之前的所有行
    for(int fh=0;fh<ch;fh++)
    {//挨个取出前面行中皇后所在位置的列坐标
          int fl=Queens[fh];
          //如果在同一列，该位置不能放
          if(cl==fl)    return 0;
          //前面的坐标：（index,data）  当前行的坐标（ch,cl）
          if(abs(ch-fh)==abs(cl-fl))   return 0; //同一斜线  
    }
 return 1;   //如果以上情况都不是，该位置就可以放
}
//输出语句
void Print()
{   for(int line=0;line<8;line++)
     {   int list;
          for(list=0;list<Queens[line];list++)
                     printf("0");
          printf("#");
          for(list=Queens[line]+1;list<8;list++)
                     printf("0");
          printf("\n");
      }
      printf("=============\n");
}
void EightQueen(int current_line)
{    if(current_line==8)   return;
      int list;
      for(list=0;list<8;list++)  //判断每一列是否可行
      {
             Queens[current_line]=list;
             if(Check(current_line,list))
             { 
                    if(current_line==7)//行
                    {     
                        counts++;
                        Print(); //打印摆放方法
                     }
                     EightQueen(current_line+1);
             }
       }
}


int main()
{     
      EightQueen(0);
      printf("摆放的方式有%d种",counts);
      return 0;
}
