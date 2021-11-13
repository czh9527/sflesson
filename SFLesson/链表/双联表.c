#include <stdio.h>
#include <stdlib.h>
typedef struct DNode
{
  int data;
  struct DNode *prior,*next;
}DNode,*pDNode;

void nodePrint(pDNode L)
{
    pDNode p = L->next;
    while(p!=NULL)
    {
        printf("-----%d\n",p->data);
        p=p->next;
        
    }
}
void  HeadInsert(DNode  **L,int  a[],int  n)
{
     DNode   *p;
     *L=(DNode *)malloc(sizeof(DNode));
     (*L)->next=NULL;
     for(int i=0;i<n;++i)
     {    p=(DNode *)malloc(sizeof(DNode));
          
          p->data=a[i];
          p->next=(*L)->next;

if((*L)->next!=NULL)
          (*L)->next->prior=p;

          (*L)->next=p;

          p->prior=(*L);
          // (*L)->next=p;//错误的，此时s->next指针已经改变
          // p->next=s->next;
     }
}
void TailInsert(pDNode *L,int a[],int n)
{
  DNode *p;
  DNode *tail;
  *L = (pDNode)malloc(sizeof(DNode));
  (*L)->next=NULL;
  tail=*L;
  for(int i=0;i<n;i++)
  {
    p=(pDNode)malloc(sizeof(DNode));
    p->data=a[i];
    tail->next=p;
    p->next=NULL;
    tail=p;    
  }
}
void delete(pDNode *L)
{
  printf("input your delete count:");
  int deleteNum ;
  scanf("%d",&deleteNum);

  pDNode p =(*L)->next;
  pDNode pre = *L;
  while(p!=NULL)
  {
    if(p->data==deleteNum)
    {
      pre->next=p->next;
      p->next=NULL;
      free(p);
      return;
    }
    pre=pre->next;
    p=p->next;
  }
}
void insert(pDNode *L,int n,int newNum)
{
  pDNode p =(*L)->next;
  for(int i = 1;i<n;i++)  {
    p=p->next;
  }
  pDNode s=(pDNode)malloc(sizeof(DNode));
  s->data=newNum;
  s->next=p->next;
  p->next=s;
}
void reverse(pDNode *L)
{
  pDNode p = (*L)->next;
  pDNode q=p->next;
  while(q!=NULL)
  {
    
      p->next= q->next;
      q->next=(*L)->next;
      (*L)->next=q;
      q=p->next;
  }
}
int main(){
    

    
   
    pDNode L;
      

    int tmp=0;
    while (tmp!=-1)
    {
      printf("1-headinsert\n");
      printf("2-tailinsert\n");
      printf("3-delete\n");
      printf("4-insert-num\n");
      printf("5-reverse\n");

      printf("0-print\n");
      scanf("%d",&tmp);
int a[5]={11,22,33,44,55};
      switch (tmp)
      {
        case 1:
          
          HeadInsert(&L,a,5);
          break;
        case 2:
          TailInsert(&L,a,5);
          break;
        case 3:
          delete(&L);
          break;
        case 4:
          insert(&L,3,666);
          break;
        case 5:
          reverse(&L);
          break;
        case 0:
          nodePrint(L);
          break;
        default:
          break;
      }
    }
    
    
    return 0;
}