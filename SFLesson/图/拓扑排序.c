#include <stdio.h>
#include <stdlib.h>

typedef struct ArcNode
{
    /* data */
    int adjvex;
    struct ArcNode *nextNode;
    int info;
}ArcNode;

typedef struct
{
    char data;
    int count;              //count用来统计顶点当前的入度
    ArcNode *firstarc;
}VNode;


typedef struct AGraph
{
    /* data */
    int n,e;
    VNode adjlist[100];
}AGraph;
#define MAXSIZE 100

//拓扑排序


int TopSort(AGraph *G)
{
      int i,j,n=0;
      int stack[MAXSIZE],top=-1;   //定义并初始化栈
      ArcNode *p;
      for(i=0;i<G->n;++i)        //循环将图中入度为0的顶点入栈
           if(G->adjlist[i].count==0)
                   stack[++top]=i;
      while(top!=-1)
      {    
          i=stack[top--];         //顶点出栈
            ++n;                       //计数器+1
            printf("%d",i);        //输出当前顶点
            p=G->adjlist[i].firstarc;
            while(p!=NULL) //循环将所有由此顶点引出的边所指向的顶点入度都减1，并将这个过程中入度变为0的顶点入栈
           {   
                j=p->adjvex;
                --(G->adjlist[j].count);
                if(G->adjlist[j].count==0)    //剩下==0的入栈
                    stack[++top]=j;
                p=p->nextNode;
           }
      }
      if(n==G->n)  return 1;
      else  return 0;
}


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
		q->nextNode = g->adjlist[i].firstarc;
		g->adjlist[i].firstarc = q;
		//当该图是有向图时，下面的操作继续执行
		q = (ArcNode *)malloc(sizeof(ArcNode));
		q->adjvex = i;
		q->nextNode = g->adjlist[j].firstarc;//头插法产生逆序结构
        g->adjlist[j].count++;//赋值入度
		g->adjlist[j].firstarc = q;//firstedge一直在前面
	}

}

int main()
{
    AGraph g;
    createAGraph(&g);
    TopSort(&g);

   
    return 0;
}