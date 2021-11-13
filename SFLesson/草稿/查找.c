#include <stdio.h>
#include <stdlib.h>

typedef struct BTNode
{
    /* data */
    int data;
    struct BTNode *lchild,*rchild;
}BTNode;
void Binsert(BTNode **bt,int key)
{
    BTNode *p;
    if((*bt)==NULL)
    {   
        *bt = (BTNode *)malloc(sizeof(BTNode));
        (*bt)->data=key;
        (*bt)->lchild=(*bt)->rchild=NULL;
    }
    else
    {
        if((*bt)->data<key)
        {
            Binsert(&(*bt)->rchild,key);
        }
        else
        {
            Binsert(&(*bt)->lchild,key);
        }
    }
}
void BSTInsert(BTNode **bt,int k[],int n)
{
    int i=0;
    for(i= 0;i<n;i++)
    {
        Binsert(bt,k[i]);
    }
}

void printNode(BTNode *p)
{
    if(p)
    {
        printNode(p->lchild);
        printf("%d ",p->data);
        printNode(p->rchild);
    }
}
BTNode * BSearchNode(BTNode *p,int key)
{
    if(p->data==key)
    {
        return p;
    }
    else if(p->data<key)
    {
        return BSearchNode(p->rchild,key);
    }
    else
    {
        return BSearchNode(p->lchild,key);
    }
}
void Delete(BTNode **bt)
{
    BTNode *p,*s;
    if((*bt)->lchild==NULL)
    {
        p= (*bt);
        (*bt)=(*bt)->rchild;
        free(p);
    }
    else if((*bt)->rchild==NULL)
    {
        p = (*bt);
        (*bt)=(*bt)->lchild;
        free(p);
    }
    else
    {
        p = (*bt);
        s= (*bt)->lchild;
        while(s->rchild)
        {
            p = s;
            s= s->rchild;
        }
        (*bt)->data=s->data;
        if(p!=(*bt))
        {
            p->rchild=s->lchild;
        }
        else
        {
            p->lchild= s->lchild;
        }
        free(s);
    }
}
void DeleteBSTNode(BTNode **bt,int key)
{
    if(bt==NULL)
    {
        return;
    }
    else
    {
        if(key == (*bt)->data)
        {
            Delete(bt);
        }
        else if(key>(*bt)->data)
        {
            DeleteBSTNode(&(*bt)->rchild,key);
        }
        else
        {
            DeleteBSTNode(&(*bt)->lchild,key);
        }
    }
}
int main()
{
   BTNode *p=NULL;
   int k[10]={22,12,56,34,78,53,25,32,17,45};
   BSTInsert(&p,k,10);
   DeleteBSTNode(&p,32);
   printNode(p);
//    BTNode *s = BSearchNode(p,53);
//    printf("\n%d\n",s->data);
    return 0;
}