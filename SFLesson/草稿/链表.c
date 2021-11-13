#include <stdio.h>
#include <stdlib.h>

typedef struct LNode
{
  int data;
  struct LNode *next;
}LNode;

void headInsert(LNode **p,int a[],int n)
{
  *p= (LNode *)malloc(sizeof(LNode));
  (*p)->next=NULL;
  LNode *s;
  for(int i=0;i<n;i++)
  {
    s= (LNode *)malloc(sizeof(LNode));
    s->data=a[i];
    s->next= (*p)->next;
    (*p)->next=s;
  }
}
void tailInsrt(LNode *p,int a[],int n)
{
  LNode *r;
  LNode *s;
  r= p;
  for(int i= 0;i<n;i++)
  {
    s= (LNode *)malloc(sizeof(LNode));
    s->next=NULL;
    s->data=a[i];
    r->next=s;
    r= s;
  }

}
void nodePrint(LNode *p)
{
  while(p->next!=NULL)
  {
    printf("%d ",p->next->data);
    p=p->next;
  }
  printf("\n");
}
void deleteNode(LNode *p,int s)
{
  LNode *pre = p;
  while(p->next)
  {
    if(p->next->data== s)
    {
      p->next=p->next->next;
    }
    p=p->next;
    pre=pre->next;
  }
}
void reverseNode(LNode *L)
{
  LNode *p,*q;
  p=L->next;
  q=p->next;

  while (q)
  {
    /* code */
    
    p->next=q->next;
    q->next=L->next;
    L->next=q;
    q=p->next;
  }


}
int main()
{
  LNode *p;
  int a[6]={2,5,1,3,8,5};
  p= (LNode *)malloc(sizeof(LNode));
  // headInsert(&p,a,6);
  tailInsrt(p,a,6);
  nodePrint(p);
  // deleteNode(p,8);
  reverseNode(p);
  nodePrint(p);

  return 0;
}