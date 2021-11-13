#include <stdio.h>
#include <stdlib.h>
int Board[100][100];
int tile=1;

void ChessBoard(int tr,int tc,int dr,int dc,int size)  //tr为棋盘左上角方格的行号；tc为棋盘左上角方格的列号
{                 //dr为特殊方格所在的行号；dc为特殊方格所在的列号；size=2k，棋盘规格为2k2k
       
       int s=0;
       if(size==1) return;
       int t=tile++;     //L型骨牌号
       s=size/2;   //分割棋盘
       //覆盖左上角子棋盘
       if(dr<tr+s && dc<tc+s)   //如果特殊方格在此棋盘中
             ChessBoard(tr,tc,dr,dc,s);
       else     //此棋盘中无特殊方格，则用t号L型骨牌覆盖右下角
       {   
            Board[tr+s-1][tc+s-1]=t;
            ChessBoard(tr,tc,tr+s-1,tc+s-1,s);         //覆盖其余方格
       }
       //覆盖右上角子棋盘
       if(dr<tr+s&&dc>=tc+s)          //如果特殊方格在此棋盘中
            ChessBoard(tr,tc+s,dr,dc,s);
       else       //此棋盘中无特殊方格，则用t号L型骨牌覆盖左下角
       {    Board[tr+s-1][tc+s]=t;
             ChessBoard(tr,tc+s,tr+s-1,tc+s,s);    //覆盖其它方格
       }
     //覆盖左下角子棋盘
     if(dr>=tr+s&&dc<tc+s)   //特殊方格在此棋盘中
         ChessBoard(tr+s,tc,dr,dc,s);
     else       //用t号L型骨牌覆盖右上角
     {   Board[tr+s][tc+s-1]=t;
          ChessBoard(tr+s,tc,tr+s,tc+s-1,s);
     }   
     //覆盖右下角子棋盘
     if(dr>=tr+s && dc>=tc+s)     //特殊方格在此棋盘中
         ChessBoard(tr+s,tc+s,tr,tc,s);
      else   //用t号骨牌覆盖左上角
      {   Board[tr+s][tc+s]=t;
           ChessBoard(tr+s,tc+s,tr+s,tc+s,s);
      }
}

void printBoard(int n)
{
     int i,j;
     for(i=0;i<n;i++)
     {
          for(j=0;j<n;j++)
          {
               printf("%2d ",Board[i][j]);
          }
          printf("\n");
     }
}

int main()
{
     ChessBoard(0,0,1,1,4);
     printBoard(4);
     return 0;
}