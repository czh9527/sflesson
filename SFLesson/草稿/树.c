#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef struct BTNode
{
    char data;
    struct BTNode *rchild,*lchild;
    int ltag,rtag;
}BTNode;

void createTree(BTNode **p)
{
    char input;
    scanf("%c",&input);

    if(input =='\n')
    {
        return;
    }
    else if(input == ' ')
    {
        *p=NULL;
    }
    else
    {
        *p= (BTNode *)malloc(sizeof(BTNode));
        (*p)->data=input;
        (*p)->ltag=(*p)->rtag=0;
        createTree(&((*p)->lchild));
        createTree(&((*p)->rchild));
    }
}

void Visit(BTNode *p)
{
    printf("%c ",p->data);
}
void levelOder(BTNode *p)
{
    int rear,front;
    front = rear=0;
    BTNode *que[MAXSIZE];
    rear=(rear+1)%MAXSIZE;
    que[rear]=p;

    BTNode *n;
    while(rear!=front)
    {
        front=(front+1)%MAXSIZE;
        n= que[front];
        Visit(n);
        if(n->lchild)
        {
            rear=(rear+1)%MAXSIZE;
            que[rear]=n->lchild;
        }
        if(n->rchild)
        {
            rear=(rear+1)%MAXSIZE;
            que[rear]=n->rchild;
        }
    }
}
void preOder(BTNode *bt)
{
    int top = -1;
    BTNode *stack[MAXSIZE];
    stack[++top]=bt;
    BTNode *p;
    while(top !=-1)
    {
        p= stack[top--];
        Visit(p);
        if(p->rchild)
        {
            stack[++top]=p->rchild;
        }
        if(p->lchild)
        {
            stack[++top]=p->lchild;
        }
    }
}

void inOder(BTNode *bt)
{
    int top =-1;
    BTNode *stack[MAXSIZE];
    BTNode *p= bt;
    while(top !=-1 || p!=NULL)
    {
        while(p!=NULL)
        {
            stack[++top]=p;
            p=p->lchild;
        }
        if(top !=-1)
        {
            p= stack[top--];
            Visit(p);
            p=p->rchild;
        }
    }
}
void postOder(BTNode *bt)
{
    int top =-1;
    BTNode *stack[MAXSIZE];
    BTNode *p= bt;
    BTNode *r=NULL;
    while(top !=-1 || p!=NULL)
    {
        while(p!=NULL)
        {
            stack[++top]=p;
            p=p->lchild;
        }
        if(top !=-1)
        {
            p= stack[top];
            if(p->rchild!= NULL && p->rchild !=r )
            {
                p= p->rchild;
            }
            else
            {
                p=stack[top--];
                Visit(p);
                r= p;
                p= NULL;
            }
        }
    }
}
void inThread(BTNode *bt,BTNode **pre)
{
    if(bt!=NULL)
    {
        inThread(bt->lchild,pre);
        if(bt->lchild==NULL)
        {
            bt->ltag=1;
            bt->lchild= *pre;
        }
        if((*pre)->rchild==NULL && (*pre)!=NULL)
        {
            (*pre)->rtag=1;
            (*pre)->rchild= bt;
        }
        (*pre)=bt;
        inThread(bt->rchild,pre);
    }
}
void preThread(BTNode *bt,BTNode **pre)
{
    if(bt!=NULL)
    {
        if(bt->lchild==NULL)
        {
            bt->ltag=1;
            bt->lchild= *pre;
        }
        if((*pre)->rchild==NULL)
        {
            (*pre)->rtag=1;
            (*pre)->rchild=bt;
        }
        (*pre)=bt;
        if(bt->ltag==0)
        {
            preThread(bt->lchild,pre);
        }
        if(bt->rtag==0)
        {
            preThread(bt->rchild,pre);
        }

    }
}
void initPre(BTNode *bt,BTNode **p)
{
    BTNode *pre;
    (*p)= (BTNode *)malloc(sizeof(BTNode));
    (*p)->ltag=0;
    (*p)->lchild= bt;
    (*p)->rtag=1;
    pre=(*p);
    preThread(bt,&pre);
    pre->rchild=*p;
    pre->rtag=1;
    (*p)->rchild=pre;
}
void inOrderTNT(BTNode *t)
{
    BTNode *p = t->lchild;
    while(p!=t)
    {
        while(p->ltag==0)
        {
            p=p->lchild;
        }
        Visit(p);
        if(p->rtag==1 && p->rchild!=t)
        {
             p=p->rchild;
             Visit(p);
        }
        p=p->rchild;
       
    }
}



void preOderTNT(BTNode *t)
{
    BTNode *p = t->lchild;
    while(p!=t)
    {
        while(p->ltag==0)
        {
            Visit(p);
            p=p->lchild;
        }
        Visit(p);
        p=p->rchild;

    }
}
int main()
{
    BTNode *bt;
    BTNode *p;
    printf("«Î ‰»Î£∫");
    createTree(&bt);

    initPre(bt,&p);
    preOderTNT(p);

    // preOder(bt);
    // levelOder(bt);
    // inOder(bt);
    // postOder(bt);

    return 0;
}