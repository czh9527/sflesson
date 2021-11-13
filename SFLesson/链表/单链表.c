#include <stdio.h>
#include <stdlib.h>
typedef struct LNode
{
  int data;
  struct LNode *next;
}LNode,*pLNode;

void nodePrint(pLNode L)
{
    pLNode p = L->next;
    while(p!=NULL)
    {
        printf("-----%d\n",p->data);
        p=p->next;
        
    }
}
//头插创建链表
void  HeadInsert(LNode  **L,int  a[],int  n)
{
     LNode   *p;
     LNode * s;
     *L=(LNode *)malloc(sizeof(LNode));
     (*L)->next=NULL;
     for(int i=0;i<n;++i)
     {    p=(LNode *)malloc(sizeof(LNode));
          s=*L;
          p->data=a[i];
          p->next=(*L)->next;
          (*L)->next=p;
          // (*L)->next=p;//错误的，此时s->next指针已经改变
          // p->next=s->next;
     }
}
//尾插法创建链表
void TailInsert(pLNode *L,int a[],int n)
{
  LNode *p;
  LNode *tail;
  *L = (pLNode)malloc(sizeof(LNode));
  (*L)->next=NULL;
  tail=*L;
  for(int i=0;i<n;i++)
  {
    p=(pLNode)malloc(sizeof(LNode));
    p->data=a[i];
    tail->next=p;
    p->next=NULL;
    tail=p;    
  }
}

//删除结点
void delete(pLNode *L)
{
  printf("input your delete count:");
  int deleteNum ;
  scanf("%d",&deleteNum);

  pLNode p =(*L)->next;
  pLNode pre = *L;
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
//按位置插入
void insert(pLNode *L,int n,int newNum)
{
  pLNode p =(*L)->next;
  for(int i = 1;i<n;i++)  {
    p=p->next;
  }
  pLNode s=(pLNode)malloc(sizeof(LNode));
  s->data=newNum;
  s->next=p->next;
  p->next=s;
}
//逆向
void reverse(pLNode *L)
{
  pLNode p = (*L)->next;
  pLNode q=p->next;
  while(q!=NULL)//不能用p去当循环元素，因为下面的q->next不能保证
  {
    
      p->next= q->next;//期间p始终是原来第一个元素，后面的依次往前插
      q->next=(*L)->next;
      (*L)->next=q;
      q=p->next;
  }
}
int main(){
    

    
   
    pLNode L;
      

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