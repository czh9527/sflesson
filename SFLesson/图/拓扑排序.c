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
    int count;              //count����ͳ�ƶ��㵱ǰ�����
    ArcNode *firstarc;
}VNode;


typedef struct AGraph
{
    /* data */
    int n,e;
    VNode adjlist[100];
}AGraph;
#define MAXSIZE 100

//��������


int TopSort(AGraph *G)
{
      int i,j,n=0;
      int stack[MAXSIZE],top=-1;   //���岢��ʼ��ջ
      ArcNode *p;
      for(i=0;i<G->n;++i)        //ѭ����ͼ�����Ϊ0�Ķ�����ջ
           if(G->adjlist[i].count==0)
                   stack[++top]=i;
      while(top!=-1)
      {    
          i=stack[top--];         //�����ջ
            ++n;                       //������+1
            printf("%d",i);        //�����ǰ����
            p=G->adjlist[i].firstarc;
            while(p!=NULL) //ѭ���������ɴ˶��������ı���ָ��Ķ�����ȶ���1�����������������ȱ�Ϊ0�Ķ�����ջ
           {   
                j=p->adjvex;
                --(G->adjlist[j].count);
                if(G->adjlist[j].count==0)    //ʣ��==0����ջ
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
		q->nextNode = g->adjlist[i].firstarc;
		g->adjlist[i].firstarc = q;
		//����ͼ������ͼʱ������Ĳ�������ִ��
		q = (ArcNode *)malloc(sizeof(ArcNode));
		q->adjvex = i;
		q->nextNode = g->adjlist[j].firstarc;//ͷ�巨��������ṹ
        g->adjlist[j].count++;//��ֵ���
		g->adjlist[j].firstarc = q;//firstedgeһֱ��ǰ��
	}

}

int main()
{
    AGraph g;
    createAGraph(&g);
    TopSort(&g);

   
    return 0;
}