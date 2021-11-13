#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef struct MGraph
{
    int data[MAXSIZE];
    int edges[MAXSIZE][MAXSIZE];
    int n,e;
}MGraph;

typedef struct ArcNode
{
    int Adj;
    struct ArcNode *nextNode;
    int w;
}ANode;
typedef struct VNode
{
    char data;
    struct ArcNode *firstNode;
}VNode;

typedef struct AGraph{
    int n,e;
    VNode AdjList[MAXSIZE]; 
}AGraph;
int visit[MAXSIZE];
void Visit(int data);
void DFS(AGraph *g,int v)
{
    visit[v]=1;
    Visit(v);
    ArcNode *p= g->AdjList[v].firstNode;
    while(p)
    {
        if(visit[p->Adj]==0)
        {
            DFS(g,p->Adj);
        }
        p=p->nextNode;
    }
}
void dfs(AGraph *g)
{
    for(int i = 0;i<g->n;i++)
    {
        if(visit[i]==0)
        {
            DFS(g,i);
        }
    }
}
void BFS(AGraph *g,int v)
{
    int rear,front;
    int que[MAXSIZE];
    ArcNode *p;
    visit[v]=1;
    Visit(v);
    rear=(rear+1)%MAXSIZE;
    que[rear]=v;
    while(rear!=front)
    {
        front = (front+1)%MAXSIZE;
        p=g->AdjList[que[front]].firstNode;
        while(p)
        {
            if(visit[p->Adj]==0)
            {
                Visit(p->Adj);
                visit[p->Adj]=1;
                rear=(rear+1)%MAXSIZE;
                que[rear]=p->Adj;
            }
            p=p->nextNode;
        }
    }

}

//最小代价生成树

int sum=0;
void prim(MGraph *g,int v0)
{
    int lowcost[MAXSIZE],vset[MAXSIZE];
    for(int i=0;i<g->n;i++)
    {
        lowcost[i]=g->edges[v0][i];
        vset[i]=0;
    }
    sum= 0;
    int v= v0;
    vset[v]=1;
    for(int i=0;i<g->n-1;i++)
    {
        min= MAXSIZE;
        for(j=0;j<g->n;j++)
        {
            if(vset[j]==0 && lowcost[j]<min)
            {
                min= lowcost[j];
                k= j;
            }
        }
        for(j= 0;j<g->n;j++)
        {
            if(g->edges[i][j]+lowcost[i]<lowcost[j])
            {
                lowcost[j]=g->edges[i][j]+lowcost[i];
            }
        }

    }
}
