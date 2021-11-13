
#define MAXSIZE 100
#include <stdio.h>
#include <stdlib.h>

//�ڽӾ���
typedef struct Vertex
{
	char info;//������Ϣ
	int no;//����ֵ
}Vertex;

typedef struct MGraph {
	int edges[MAXSIZE][MAXSIZE];//�ߵ�Ȩֵ
	int n, e;
	Vertex vex[MAXSIZE];//������Ϣ
}MGraph;
//�ڽӱ�
typedef struct ArcNode
{
	int adjvex;       //�ñ���ָ��Ľ���λ��
	struct ArcNode *nextarc;    //ָ����һ���ߵ�ָ��
	int info;     //�ߵ������Ϣ������Ȩֵ
}ArcNode;
typedef struct
{
	char data;    //������Ϣ
	ArcNode  *firstarc;   //ָ���һ���ߵ�ָ��
}VNode;

typedef struct
{
	VNode adjlist[MAXSIZE];   //�ڽӱ�
	int n, e;      //�������ͱ���
}AGraph;
void Visit(AGraph *g, int v)
{
	// printf("%c", g->adjlist[v].data);
    printf("%d",v);
}
int visit[MAXSIZE];
//���ڽӾ���ʽ��������ͼ
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
			Gp->edges[i][j] = 0;
		}
	}
	for (k = 0; k < Gp->e; k++)
	{
		printf("������ߣ�vi, vj)���ϱ�i���±�j���ո�ָ���:\n");
		scanf("%d", &i);
		scanf("%d", &j);
		Gp->edges[i][j] = 1;
		Gp->edges[j][i] = 1;
	}
}
//�����ڽӱ�
void createAGraph(AGraph *g)
{
	int i, j, k;
	ArcNode *q;
	printf("�����붥�����ͱ������ո�ָ�����\n");
	scanf("%d", &g->n);
	scanf("%d", &g->e);
	getchar();
	printf("�����붥����Ϣ���ո�ָ�����\n");
	for (i = 0; i < g->n; i++)
	{
		scanf("%c", &g->adjlist[i].data);
		g->adjlist[i].firstarc = NULL;
		getchar();
		
	}
	
	//�����߱���Ϣ
	for (k = 0; k < g->e; k++) {
		printf("������ߣ�vi, vj)���ϱ�i���±�j���ո�ָ���:\n");
		scanf("%d", &i);
		scanf("%d", &j);
		q = (ArcNode *)malloc(sizeof(ArcNode));
		q->adjvex = j;//�洢��ͷ
		q->nextarc = g->adjlist[i].firstarc;
		g->adjlist[i].firstarc = q;
		//����ͼ������ͼʱ������Ĳ�������ִ��
		q = (ArcNode *)malloc(sizeof(ArcNode));
		q->adjvex = i;
		q->nextarc = g->adjlist[j].firstarc;//ͷ�巨��������ṹ
		g->adjlist[j].firstarc = q;//firstedgeһֱ��ǰ��
	}

}
//��ȱ���
void DFS(AGraph *G, int v)//v�Ƕ�����ֵ
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
//���ͼ����ͨ
void dfs(AGraph *g)
{
	int i;
	for (i = 0; i < g->n; ++i)
	{
		if (visit[i] == 0)    DFS(g, i);
	}
}

//��ȱ���
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
//δ��ͨ��Ҳ�ܴ�ӡ
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
