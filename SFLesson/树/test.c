#include <stdio.h>
#include <stdlib.h>

typedef struct TBTNode
{
    char data;
    int ltag,rtag;
    struct TBTNode *lchild,*rchild;
}TBTNode,*pTBTNode;
pTBTNode pre;
//前序遍历创建
void createTBT(pTBTNode * t)
{
    // printf("input your:");
    char c;
    scanf("%c",&c);
    if('\n'==c)
    {
        return;
    }
    if(' '==c)
    {
        *t=NULL;
    }
    else
    {
        (*t)= (pTBTNode)malloc(sizeof(TBTNode));
        (*t)->data=c;
        (*t)->ltag=(*t)->rtag=0;
        createTBT(&(*t)->lchild);
        createTBT(&(*t)->rchild);

    }
}
//中序遍历线索化
void inthreaing(pTBTNode t)
{

    if(t)
    {
        inthreaing(t->lchild);
        if(!t->lchild)
        {
            t->ltag=1;
            t->lchild=pre;
        }
        if(!pre->rchild)
        {
            pre->rtag=1;
            pre->rchild=t;
        }
        pre = t;
        inthreaing(t->rchild);
    }
}
//线索化初始化-p为空第一
void inOrderthreaing(pTBTNode *p,pTBTNode t)
{
    *p=(pTBTNode) malloc(sizeof(TBTNode));
    (*p)->ltag=0;
    (*p)->rtag=1;
    (*p)->lchild=*p;
    if(!t)
    {
        (*p)->lchild=(*p);
    }
    else
    {
        (*p)->lchild=t;
        pre=*p;
        inthreaing(t);
        pre->rchild=*p;
        pre->rtag=1;
        (*p)->rchild=pre;
    }
}
void Visit(char data)
{
    printf("%c",data);
}

//中序遍历
void inorder(pTBTNode t)
{
    if(t)
    {
        pTBTNode p;
        p=t->lchild;
        while(p!=t)
        {
            while (p->ltag==0)
            {
                p=p->lchild;
            }
            Visit(p->data);
            while(p->rtag==1 && p->rchild !=t)
            {
                p=p->rchild;
                Visit(p->data);
            }
            p=p->rchild;
            
        }
    }
}
int main()
{
    TBTNode *p,*t=NULL ;
    createTBT(&t);
    inOrderthreaing(&p,t);
    inorder(p);
    return 0;
}