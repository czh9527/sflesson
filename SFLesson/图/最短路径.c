#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef struct 
{
     /* data */
     int no;
     char info;
}Vertex;

typedef struct MGraph
{
     /* data */
     int n,e;
     int edges[MAXSIZE][MAXSIZE];
     Vertex vex[MAXSIZE];
}MGraph;


//迪杰斯特拉算法
void Dijkstra(MGraph g,int v,int dist[],int path[])//dist表示到其他顶点的距离，path指上一个顶点
{  
     int set[MAXSIZE];//
    int min,i,j,u;
    //初始化
    for(i=0;i<g.n;++i)
    {   
          dist[i]=g.edges[v][i];//dist存储到各点的路径
          set[i]=0;//标记数组，是否纳入
          if(g.edges[v][i]<MAXSIZE)
                 path[i]=v;
          else path[i]=-1;
    }
    set[v]=1;
    path[0]=-1;
    for(i=0;i<g.n-1;++i)
    {   min=MAXSIZE;
         for(j=0;j<g.n;++j)  //从剩余顶点中选出顶点
         {  
               if(set[j]==0&&dist[j]<min)
              {   u=j;
                   min=dist[j];
              }
         }
         set[u]=1;
         for(j=0;j<g.n;++j)  //以刚选出的顶点为中间点更新
         {   if(set[j]==0&&dist[u]+g.edges[u][j]<dist[j])
              {    dist[j]=dist[u]+g.edges[u][j];
                    path[j]=u;
              }
         }
    }
}
//弗洛伊德算法
void Floyd(MGraph *g,int Path[][MAXSIZE],int A[][MAXSIZE])
{
         int i,j,k;
         for(i=0;i<g->n;++i)
         {
                 for(j=0;j<g->n;++j)
                 {
                       A[i][j]=g->edges[i][j];
                       Path[i][j]=-1;
                 }
         }
         for(k=0;k<g->n;++k)          //三层循环完成对以k为中间点对所有的顶点对（i,j）进行检测和修改
               for(i=0;i<g->n;++i)
                    for(j=0;j<g->n;++j)
                            if(A[i][j]>A[i][k]+A[k][j] && i!=j)
                            {  
                              A[i][j]=A[i][k]+A[k][j];
                              Path[i][j]=k;
                            }
}

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
	}
}
void printList(MGraph g,int dist[],int path[])
{
     printf("\n\n距离：\n");
     for(int i=0;i<g.n;i++)
     {
          printf("%d ",dist[i]);
     }
     printf("\n前一个点：\n");
     for(int i=0;i<g.n;i++)
     {
          printf("%d ",path[i]);
     }
}
void printFList(MGraph g,int Fdist[][MAXSIZE],int Fpath[][MAXSIZE])
{
     printf("\n\n距离：\n");
     for(int i=0;i<g.n;i++)
     {
          for(int j=0;j<g.n;j++)
          {
               printf("%d ",Fdist[i][j]);
          }
          printf("\n");
     }
     printf("\n前一个点：\n");
     for(int i=0;i<g.n;i++)
     {
          for(int j=0;j<g.n;j++)
          {
               printf("%d ",Fpath[i][j]);
          }
          printf("\n");
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
     int dist[100];
     int path[100];
//     Dijkstra(g,0,dist,path);
//     printList(g,dist,path);
     int Fpath[100][100];
     int Fdist[100][100];
     Floyd(&g,Fpath,Fdist);
     printFList(g,Fdist,Fpath);
    
    return 0;
}






