#include <stdio.h>
#include <windows.h>
#define MAXSIZE 10
typedef struct BTNode{
    char data;
    struct BTNode *lchild;
    struct BTNode *rchild; 
}BTNode;
void Visit(BTNode *q)
{
      printf("%c",q->data);
}
//层次遍历
void Level(BTNode *p)
{
     int front,rear;
     BTNode *que[MAXSIZE];        //定义一个循环队列，用来记录将要访问的层次上的结点
     front=rear=0;             //队列初始化
     BTNode *q;
     if(p!=NULL)
     {
            rear=(rear+1)%MAXSIZE;
            que[rear]=p;           //根结点入队
            while(front!=rear)              //当队列不为空时进行循环
            {
                  front=(front+1)%MAXSIZE;
                  q=que[front];                  //队头结点出队
                  Visit(q);                      //访问队头结点
                  if(q->lchild!=NULL)              //如果左子树不空，左子树的根结点入队
                  {     rear=(rear+1)%MAXSIZE;
                        que[rear]=q->lchild;
                  }
                  if(q->rchild!=NULL)              //如果右子树不空，右子树的根结点入队
                  {     rear=(rear+1)%MAXSIZE;
                        que[rear]=q->rchild;
                  }
           }
     }
}
//只适合前序创建
void createBT(BTNode **bt)
{
    char c;
    scanf("%c",&c);
    if(c=='\n')
    {
        return;
    }
    if(' '==c)
    {
        *bt=NULL;
    }
    else
    {
          
         *bt = (BTNode *)malloc(sizeof(BTNode));
        (*bt)->data=c;
        createBT(&((*bt)->lchild));
        createBT(&((*bt)->rchild));
         
        
               
    }

}


int main()
{
    BTNode *p,*t= NULL;
    createBT(&t);
    Level(t);
    return 0;
}


