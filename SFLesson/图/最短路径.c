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


//�Ͻ�˹�����㷨
void Dijkstra(MGraph g,int v,int dist[],int path[])//dist��ʾ����������ľ��룬pathָ��һ������
{  
     int set[MAXSIZE];//
    int min,i,j,u;
    //��ʼ��
    for(i=0;i<g.n;++i)
    {   
          dist[i]=g.edges[v][i];//dist�洢�������·��
          set[i]=0;//������飬�Ƿ�����
          if(g.edges[v][i]<MAXSIZE)
                 path[i]=v;
          else path[i]=-1;
    }
    set[v]=1;
    path[0]=-1;
    for(i=0;i<g.n-1;++i)
    {   min=MAXSIZE;
         for(j=0;j<g.n;++j)  //��ʣ�ඥ����ѡ������
         {  
               if(set[j]==0&&dist[j]<min)
              {   u=j;
                   min=dist[j];
              }
         }
         set[u]=1;
         for(j=0;j<g.n;++j)  //�Ը�ѡ���Ķ���Ϊ�м�����
         {   if(set[j]==0&&dist[u]+g.edges[u][j]<dist[j])
              {    dist[j]=dist[u]+g.edges[u][j];
                    path[j]=u;
              }
         }
    }
}
//���������㷨
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
         for(k=0;k<g->n;++k)          //����ѭ����ɶ���kΪ�м������еĶ���ԣ�i,j�����м����޸�
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
	printf("�����붥�����ͱ������ո�ָ�����\n");
	scanf("%d", &Gp->n);
	scanf("%d", &Gp->e);
     getchar();
	printf("�����붥����Ϣ���ո�ָ�����\n");

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
		printf("������ߣ�vi, vj, w)���ϱ�i���±�j ,Ȩֵw���ո�ָ���:\n");
		scanf("%d", &i);
		scanf("%d", &j);
          scanf("%d", &w);
		Gp->edges[i][j] = w; 
		Gp->edges[j][i] = w;
	}
}
void printList(MGraph g,int dist[],int path[])
{
     printf("\n\n���룺\n");
     for(int i=0;i<g.n;i++)
     {
          printf("%d ",dist[i]);
     }
     printf("\nǰһ���㣺\n");
     for(int i=0;i<g.n;i++)
     {
          printf("%d ",path[i]);
     }
}
void printFList(MGraph g,int Fdist[][MAXSIZE],int Fpath[][MAXSIZE])
{
     printf("\n\n���룺\n");
     for(int i=0;i<g.n;i++)
     {
          for(int j=0;j<g.n;j++)
          {
               printf("%d ",Fdist[i][j]);
          }
          printf("\n");
     }
     printf("\nǰһ���㣺\n");
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






