#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
//集装箱问题
int n=6;//集装箱数
int x[7]={0,0,0,0,0,0,0};//是否装入船1
int bestx[7]={0,0,0,0,0,0,0};//最优x
int w[7]={0,25,30,10,15,20,35};//集装箱重量
int c1=80;
int c2= 80;
int cw=0;//当前载重量
int bestw=0;//当前最优解
int r= 135;//剩余集装箱重量

void backtrack(int i)
{
    if(i>n)
    {
        if(cw>bestw)
        {
            for(int i=1;i<=n;i++)
            {
                bestx[i]=x[i];
            }
            bestw=cw;
        }
        return;
    }

    r-=w[i];
    if(cw+w[i]<=c1)
    {
        x[i]=1;
        cw+=w[i];
        backtrack(i+1);//递归找下一层
        cw-=w[i];//回溯
    }
    if(cw+r>bestw)
    {
        x[i]=0;
        backtrack(i+1);
    }
    r+=w[i];

}

void print()
{
    int m1,m2;
    m1=m2=0;
    for(int i=1;i<=n;i++)
    {
        if(bestx[i]==1)
        {
            printf("%d(the 1)\n",w[i]);
            m1+=w[i];
        }
        else
        {
            printf("%d(the 2)\n",w[i]);
            m2+=w[i];
        }
    }
    printf("c1-sum=%d\n",m1);
    printf("c2-sum=%d",m2);
}
//n皇后问题
int check(int ch,int cl)
{
    for(int fh=0;fh<ch;fh++)
    {
        int f1=Queens[fh];
        if(c1==f1)
        {
            return 0;
        }
        if(abs(ch-fh)==abs(c1-f1)) 
        {
            return 0;
        }
    }
}
int Queens[8]=0;
int count=0;
void EightQueen(int current_line)
{
    if(current_line == 8)
    {
        return;
    }
    int list;
    for(list=0;list<8;list++)
    {
        Queens[current_line]=list;
        if(check(current_line,list))
        {
            if(current_line == 7)
            {
                count++;
                print();
            }
            EightQueen(current_line+1);
        }
    }
}
//旅行售货员
const int max= 0x3f3f3f;
const int NoEdge = -1;
int citynum;
int edgenum;
int currentcost;
int bestcost;
int Graph[100][100];
int x[100];
int bestx[100];

void Input()
{
    int pos1,pos2,len;
    printf("请输入城市数和边数:");
    scanf("%d",&citynum);
    scanf("%d",&edgenum);
    memset(Graph,NoEdge,sizeof(Graph));

    printf("请输入两座城市之间的距离：\n");
    for(int i=1;i<=edgenum;i++)
    {
        scanf("%d",&pos1);
        scanf("%d",&pos2);
        scanf("%d",&len);
        Graph[pos1][pos2]=Graph[pos2][pos1]=len;
    }
}

void Initilize()
{
    currentcost= 0;
    bestcost= max;
    for(int i=1;i<=citynum;i++)
    {
        x[i]=i;
    }
}

void swap(int *a,int *b)
{
    int temp = *a;
    *a= *b;
    *b= temp;
}

void BackTrack(int i)
{
    if(i== citynum)
    {
        if(Graph[x[i-1]][x[i]]!= NoEdge && Graph[x[i]][x[1]] != NoEdge && (currentcost+Graph[x[i-1]][x[1]]<bestcost|| bestcost == max))
        {
            bestcost = currentcost +Graph[x[i-1]][x[i]]+Graph[x[i]x[1]];
            for(int j=1 ;j<citynum;j++)
            {
                bestx[j]=x[j];
            }
        }
        else
        {
            for(int j=i;j<=citynum ;j++)
            {
                if(Graph[x[i-1]][x[j]] != NoEdge && (currentcost+Graph[x[i-1]][x[j]] < bestcost || bestcost == max))
                {
                    swap(x[i],x[j]);
                    currentcost+=Graph[x[i-1]][x[i]];
                    BackTrack(i+1);
                    currentcost -= Graph[x[i-1]][x[i]];
                    swap(x[i],x[j]);
                }
            }
        }
    }
}
void output()
{
    printf("最短路程为:%d\n")<<bestcost;
    printf("路线为:\n");
    for(int i=1;i<=citynum ;i++)
    {
        printf("%d",bestx[i]);
    }
}
int main()
{
    // backtrack(0);
    // print();


    return 0;
}