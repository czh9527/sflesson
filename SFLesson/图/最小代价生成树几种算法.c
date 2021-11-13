#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef struct Vertex
{
    int no;
    char info;
}Vertex;
typedef struct MGraph
{
    int n,e;
    int edges[100][100];
    Vertex vex[100];
}MGraph;
int sum=0;
//普里姆算法
void Prim(MGraph g,int v0)
{
     int lowcost[MAXSIZE],vset[MAXSIZE],v;//lostcost表示最小边的权值，vset表示有没有并入到树中
     int i,j,k,min;
     v=v0;
     for(i=0;i<g.n;++i)//每个顶点
     {
         lowcost[i]=g.edges[v0][i];//该点到其他点的权值
         vset[i]=0;//数组监控有未并入到树中
     }
     vset[v0]=1;                  //将v0并入树中
     sum=0;      //sum清零用来累计树的权值
     for(i=0;i<g.n-1;++i)//除去v0剩下的处理
     {     
            min=MAXSIZE;
            for(j=0;j<g.n;++j)       //循环，选出侯选边中的最小者
                if(vset[j]==0&&lowcost[j]<min)              //选出当前生成树中最短边中最短的一条
                {   
                    min=lowcost[j];
                    k=j;
                }
            vset[k]=1;
            v=k;
            sum+=min;
            for(j=0;j<g.n;++j)   //以刚并入的顶点v为媒介更新侯选边
            if(vset[j]==0&&g.edges[v][j]<lowcost[j])
                lowcost[j]=g.edges[v][j];
    }
}
//克鲁斯卡尔
typedef struct
{   int a,b;          //a和b为一条边所连的两个顶点
    int w;     //边的权值
}Road;//一种表示边和顶点的结构体
Road road[MAXSIZE];//假设road数组中已存放了信息
int v[MAXSIZE];          //定义并查集数组
int GetRoad(int a)     //在并查集中查找根结点
{  while(a!=v[a])   a=v[a];
    return a;
}
void swap(int a,int b)
{
    int temp = a;
    a= b;
    b= temp;
}
void sort(int n)
{
    int i,j,k,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=n-1;j>i;j++)
        {
            if(road[j].w<road[j-1].w)
            {
                swap(road[j].a,road[j-1].a);
                swap(road[j].b,road[j-1].b);

                swap(road[j].w,road[j-1].w);

            }
        }
    }
}
void Kruskal(MGraph g)
{  
     int  i;
     int N,E,a,b;
     N=g.n;
     E=g.e;
     sum=0;
     for(i=0;i<N;++i)  v[i]=i;    //对并查集初始化
     sort(E);  //对road数组中的E条边按其权值从小到大排序
     for(i=0;i<E;++i)
     {  a=GetRoad(road[i].a);
         b=GetRoad(road[i].b);
         if(a!=b)
         {    v[a]=b;   //并入一个集合
               sum+=road[i].w;
         }
     }
}
//创建邻接矩阵
void createMGraph(MGraph *Gp)
{
	int i, j, k;
	printf("请输入顶点数和边数（空格分隔）：\n");
	scanf("%d", &Gp->n);
	scanf("%d", &Gp->e);
    getchar();
	printf("请输入顶点信息（空格分隔）：\n");

	for (i = 0; i < Gp->n; i++)
	{
		scanf("%d", &Gp->vex[i].no);
        getchar();
	}
	for (i = 0; i < Gp->n; i++)
	{
		for (j = 0; j < Gp->n; j++)
		{
			Gp->edges[i][j] = 10000;
		}
	}
    int w =0;
	for (k = 0; k < Gp->e; k++)
	{
		printf("请输入边（vi, vj, w)的上标i，下标j ,权值w（空格分隔）:\n");
		scanf("%d", &i);
		scanf("%d", &j);
        scanf("%d", &w);
		Gp->edges[i][j] = w; 
		Gp->edges[j][i] = w;
        road[k].a=i;
        road[k].b=j;
        road[k].w=w;
	}
}
int main()
{
    MGraph g;
    createMGraph(&g);
    for(int i = 0;i<g.n;i++)
    {
        for(int j =0;j<g.n;j++)
        {
            printf("%d ",g.edges[i][j]);
        }
        printf("\n");
    }
    
    // Prim(g,0);
    Kruskal(g);
    printf("最小花费=%d\n",sum);
    return 0;
}