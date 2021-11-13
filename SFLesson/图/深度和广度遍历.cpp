
#define MAXSIZE 100
#include <stdio.h>
#include <stdlib.h>

//邻接矩阵
typedef struct Vertex
{
	char info;//顶点信息
	int no;//顶点值
}Vertex;

typedef struct MGraph {
	int edges[MAXSIZE][MAXSIZE];//边的权值
	int n, e;
	Vertex vex[MAXSIZE];//顶点信息
}MGraph;
//邻接表
typedef struct ArcNode
{
	int adjvex;       //该边所指向的结点的位置
	struct ArcNode *nextarc;    //指向下一条边的指针
	int info;     //边的相关信息，比如权值
}ArcNode;
typedef struct
{
	char data;    //顶点信息
	ArcNode  *firstarc;   //指向第一条边的指针
}VNode;

typedef struct
{
	VNode adjlist[MAXSIZE];   //邻接表
	int n, e;      //顶点数和边数
}AGraph;
void Visit(AGraph *g, int v)
{
	// printf("%c", g->adjlist[v].data);
    printf("%d",v);
}
int visit[MAXSIZE];
//用邻接矩阵方式创建无向图
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
			Gp->edges[i][j] = 0;
		}
	}
	for (k = 0; k < Gp->e; k++)
	{
		printf("请输入边（vi, vj)的上标i，下标j（空格分隔）:\n");
		scanf("%d", &i);
		scanf("%d", &j);
		Gp->edges[i][j] = 1;
		Gp->edges[j][i] = 1;
	}
}
//创建邻接表
void createAGraph(AGraph *g)
{
	int i, j, k;
	ArcNode *q;
	printf("请输入顶点数和边数（空格分隔）：\n");
	scanf("%d", &g->n);
	scanf("%d", &g->e);
	getchar();
	printf("请输入顶点信息（空格分隔）：\n");
	for (i = 0; i < g->n; i++)
	{
		scanf("%c", &g->adjlist[i].data);
		g->adjlist[i].firstarc = NULL;
		getchar();
		
	}
	
	//建立边表信息
	for (k = 0; k < g->e; k++) {
		printf("请输入边（vi, vj)的上标i，下标j（空格分隔）:\n");
		scanf("%d", &i);
		scanf("%d", &j);
		q = (ArcNode *)malloc(sizeof(ArcNode));
		q->adjvex = j;//存储弧头
		q->nextarc = g->adjlist[i].firstarc;
		g->adjlist[i].firstarc = q;
		//当该图是有向图时，下面的操作继续执行
		q = (ArcNode *)malloc(sizeof(ArcNode));
		q->adjvex = i;
		q->nextarc = g->adjlist[j].firstarc;//头插法产生逆序结构
		g->adjlist[j].firstarc = q;//firstedge一直在前面
	}

}
//深度遍历
void DFS(AGraph *G, int v)//v是顶点数值
{
	ArcNode *p;
	visit[v] = 1;
	Visit(G,v);
	p = G->adjlist[v].firstarc;
	while (p != NULL)
	{
		if (visit[p->adjvex] == 0)
		{
			DFS(G, p->adjvex);
		}
		p = p->nextarc;
	}
}
//如果图不连通
void dfs(AGraph *g)
{
	int i;
	for (i = 0; i < g->n; ++i)
	{
		if (visit[i] == 0)    DFS(g, i);
	}
}

//广度遍历
void BFS(AGraph *G, int v, int visit[MAXSIZE])
{
	int que[MAXSIZE], rear, front, j;
    rear = front = 0;
	ArcNode *p;
	visit[v] = 1;
	Visit(G,v);
	rear = (rear + 1) % MAXSIZE;
	que[rear] = v;
	while (front != rear)
	{
		front = (front + 1) % MAXSIZE;
		j = que[front];
		p = G->adjlist[j].firstarc;
		while (p != NULL)
		{
			if (visit[p->adjvex] == 0)
			{
				Visit(G,p->adjvex);
				visit[p->adjvex] = 1;
				rear = (rear + 1) % MAXSIZE;
				que[rear] = p->adjvex;
			}
			p = p->nextarc;

		}
	}
}
//未联通的也能打印
void bfs(AGraph *g)
{
     int i;
    for(i=0;i<g->n;++i)
    {     if(visit[i]==0)
               BFS(g,i,visit);
    }
}

int main()
{
	
	AGraph aGraph;
	createAGraph(&aGraph);
	for (int i = 0; i < MAXSIZE; i++)
		visit[i] = 0;


	bfs(&aGraph);

	return 0;
}
