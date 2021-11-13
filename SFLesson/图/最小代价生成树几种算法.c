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
//����ķ�㷨
void Prim(MGraph g,int v0)
{
     int lowcost[MAXSIZE],vset[MAXSIZE],v;//lostcost��ʾ��С�ߵ�Ȩֵ��vset��ʾ��û�в��뵽����
     int i,j,k,min;
     v=v0;
     for(i=0;i<g.n;++i)//ÿ������
     {
         lowcost[i]=g.edges[v0][i];//�õ㵽�������Ȩֵ
         vset[i]=0;//��������δ���뵽����
     }
     vset[v0]=1;                  //��v0��������
     sum=0;      //sum���������ۼ�����Ȩֵ
     for(i=0;i<g.n-1;++i)//��ȥv0ʣ�µĴ���
     {     
            min=MAXSIZE;
            for(j=0;j<g.n;++j)       //ѭ����ѡ����ѡ���е���С��
                if(vset[j]==0&&lowcost[j]<min)              //ѡ����ǰ����������̱�����̵�һ��
                {   
                    min=lowcost[j];
                    k=j;
                }
            vset[k]=1;
            v=k;
            sum+=min;
            for(j=0;j<g.n;++j)   //�Ըղ���Ķ���vΪý����º�ѡ��
            if(vset[j]==0&&g.edges[v][j]<lowcost[j])
                lowcost[j]=g.edges[v][j];
    }
}
//��³˹����
typedef struct
{   int a,b;          //a��bΪһ������������������
    int w;     //�ߵ�Ȩֵ
}Road;//һ�ֱ�ʾ�ߺͶ���Ľṹ��
Road road[MAXSIZE];//����road�������Ѵ������Ϣ
int v[MAXSIZE];          //���岢�鼯����
int GetRoad(int a)     //�ڲ��鼯�в��Ҹ����
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
     for(i=0;i<N;++i)  v[i]=i;    //�Բ��鼯��ʼ��
     sort(E);  //��road�����е�E���߰���Ȩֵ��С��������
     for(i=0;i<E;++i)
     {  a=GetRoad(road[i].a);
         b=GetRoad(road[i].b);
         if(a!=b)
         {    v[a]=b;   //����һ������
               sum+=road[i].w;
         }
     }
}
//�����ڽӾ���
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
    printf("��С����=%d\n",sum);
    return 0;
}