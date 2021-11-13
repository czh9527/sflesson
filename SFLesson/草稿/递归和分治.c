#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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
void swap(int k[],int i,int j)
{
    int temp = k[i];
    k[i]=k[j];
    k[j]=temp;
}
void Perm(int k[],int s,int n)//s起始位置，n是最后数位置
{
    if(s==n)
    {
        for(int i = 0;i<=n;i++)
        {
            printf("%d ",k[i]);
        }
        printf("\n");
        
    }
    else
    {
        for(int j = s;j<=n;j++)
        {
            swap(k,s,j);
            Perm(k,s+1,n);
            swap(k,s,j);//避免重复，基准不变
        }
    }
}
int Board[100][100];
int title = 1;
void ChessBoard(int dr,int dc,int tr,int tc,int size)
{
    if(size==1) return;
    int t= title++;
    int s = size/2;
    //左上角
    
    if(tr<dr+s && tc<dc+s)
    {
        ChessBoard(dr,dc,tr,tc,s);
    }
    else
    {
        Board[dr+s-1][dc+s-1]=t;
        ChessBoard(dr,dc,dr+s-1,dc+s-1,s);
    }
    //右上角
    if(tr<dr+s && tc>=dc+s)
    {
        ChessBoard(dr,dc+s,tr,tc,s);
    }
    else
    {
        Board[dr+s-1][dc+s]=t;
        ChessBoard(dr,dc+s,dr+s-1,dr+s,s);
    
    }
    //左下角
    if(tr>=dr+s && tc<dc+s)
    {
        ChessBoard(dr+s,dc,tr,tc,s);
    }
    else
    {
        Board[dr+s][dc+s-1]=t;
        ChessBoard(dr+s,dc,dr+s,dc+s-1,s);
    }

    //右下角
    if(tr>=dr+s && tc>=dc+s)
    {
        ChessBoard(dr+s,dc+s,tr,tc,s);
               

    }
    else
    {
        Board[dr+s][dc+s]=t;
        ChessBoard(dr+s,dc+s,dr+s,dc+s,s);
        
    }
}
void printBoard(int n)
{
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            printf("%3d ",Board[i][j]);
        }
        printf("\n");
    }
}


void gen(int x,int y,int d,int a[100][100])
{
    for(int i= 0;i<=d-1;i++)
    {
        for(int j = 0;j<=d-1;j++)
        {
            a[x+i][y+j+d]=a[x+i][y+j]+d;
        }
    }
}
void cpy(int x1,int y1,int d,int x2,int y2,int a[100][100])
{
    for(int i = 0;i<=d-1;i++)
    {
        for(int j = 0;j<=d-1;j++)
        {
            a[x2+i][y2+j]=a[x1+i][y1+j];
        }
    }
}
void table(int k,int a[100][100])
{
    a[1][1]=1;
    int d=0;
    for(int i=0;i<k;i++)
    {
        d= pow(2,i);
        gen(1,1,d,a);
        cpy(1,1,d,1+d,1+d,a);
        cpy(1,1+d,d,1+d,1,a);
    }
}
void printTable(int k,int a[100][100])
{
   
    for(int i= 1;i<=pow(2,k);i++)
    {
        for(int j= 1;j<=pow(2,k);j++)
        {
            printf("%2d ",a[i][j]);

        }
        printf("\n");
    }
}
int main()
{
    // hanoi(3,'a','b','c');
    // int k[5]={5,3,2,1,4};
    // Perm(k,2,4);
    // ChessBoard(0,0,3,7,8);
    // printBoard(8);
    int a[100][100];
    int m= 3;
    table(m,a);
    
    printTable(m,a);
    return 0;
}