#include <stdio.h>
#include <stdlib.h>
void LCSLength(int m,int n,char *x,char *y,int c[10][10],int b[10][10])//m是x的字段数，n是y的字段数,c是ij个字段的最长个数，b是那种情况
{  int i,j;
    for(i=0;i<m;i++)  c[i][0]=0;
    for(i=0;i<n;i++)   c[0][i]=0;
    for(i=0;i<m;i++)
         for(j=0;j<n;j++)
         {   if(x[i]==y[j])
              {  c[i][j]=c[i-1][j-1]+1;
                  b[i][j]=1;
              }
              else if(c[i-1][j]>=c[i][j-1])
              {   c[i][j]=c[i-1][j];
                   b[i][j]=2;
              }
              else
              {  c[i][j]=c[i][j-1];
                  b[i][j]=3;
               }
         }
}
void LCS(int i,int j,char *x,int b[10][10])
{
     if(i==-1||j==-1)   
        return;
     if(b[i][j]==1)  
     {  
         LCS(i-1,j-1,x,b);
         printf("%c",x[i]);    
      } 
      else if(b[i][j]==2)    LCS(i-1,j,x,b);
      else LCS(i,j-1,x,b);
}

int main()
{
    char x[8]="-zhtest";
    char y[5]="-hst";
    int b[10][10];
    int c[10][10];
    LCSLength(8,5,x,y,c,b);
    LCS(7,4,x,b);

    return 0;
}