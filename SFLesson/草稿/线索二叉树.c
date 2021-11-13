#include <stdio.h>
#include <stdlib.h>
typedef struct TBTNode
{
    char data;
    int ltag,rtag;
    struct TBTNode *lchild,*rchild;
}TBTNode;
//
void inThread(TBTNode *p,TBTNode **pre)
{
    if(p!=NULL)
    {
        inThread(p->lchild,pre);
        if(p->lchild==NULL)
        {
            p->lchild=pre;
            p->ltag=1;
        }
        if((*pre)->rchild==NULL)
        {
            (*pre)->rchild=p;
            (*pre)->rtag=1;
        }
        pre=p;
        inThread(p->rchild,pre);
    }
}
void PreThread(TBTNode *p,TBTNode **pre)
{
    if(p!=NULL)
    {
        if(p->lchild==NULL)
        {
            p->lchild=pre;
            p->ltag=1;
        }
        if((*pre)->rchild==NULL)
        {
            (*pre)->rchild=p;
            (*pre)->rtag=1;
        }
        pre = p;
        if(p->ltag==0) 
        {
            PreThread()
        }
    }
}
