#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10
//邻接矩阵
typedef struct 
{
    int no;
    char info;
}Vertex;

typedef struct
{
    int edges[MAXSIZE][MAXSIZE];
    int n,e;
    Vertex vex[MAXSIZE];
}MGraph;

//邻接表

typedef struct ArcNode
{
    int adjvex;
    struct ArcNode *nextarc;
    int info;  
}ArcNode;

typedef struct 
{
    int data;
    ArcNode *firstarc;
}VNode;

typedef struct 
{
    VNode adjlist[MAXSIZE];
    int n,e;
}AGraph;




