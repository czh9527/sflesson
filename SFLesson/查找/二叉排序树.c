#include <stdio.h>
#include <stdlib.h>

typedef struct BTNode
{
    int data;
    struct BTNode *lchild, *rchild;
}BTNode,*pBTNode;
//查找关键字的算法
BTNode*BSTSearch(BTNode *bt,int key)
{
       if(bt==NULL)
            return NULL;    //来到空指针域查找失败
       else
       {
               if(bt->data==key)     return bt; //等于根结点中的关键字则查找成功
               else if(key<bt->data)   //小于根结点中的关键字则到左子树中查找
                       return BSTSearch(bt->lchild,key);
               else  return  BSTSearch(bt->rchild,key);         //大于根结点的关键字则到右子树查找
       }
}
// 插入关键字的算法
int BSTInsert(BTNode **bt,int key)
{
      if(*bt==NULL)     //当前指针为空指针说明找到了插入位置，创建新结点进行插入
      {
            *bt=(BTNode*)malloc(sizeof(BTNode));    //创建新结点
            (*bt)->lchild=(*bt)->rchild=NULL;
            (*bt)->data=key;           //将待插关键字存入新结点内，插入成功，返回1
            return 1;
      }
      else
     { 
             if(key==(*bt)->data)     return 0;   //关键字已经存在与树中，插入失败
             else if(key<(*bt)->data)     return BSTInsert(&(*bt)->lchild,key);
             else  return BSTInsert(&(*bt)->rchild,key);
     }
}
// 二叉排序树的构造
// 假设关键字已存入数组key[]中
void CreateBST(BTNode **bt,int key[],int n)
{
     int i;
     *bt=NULL;
     for(i=0;i<n;++i)
        BSTInsert(bt,key[i]);
}
//二叉排序树的删除
int DeleteBST(pBTNode *T,int key)
{
    if(!(*T))
    {
        return 0;
    }
    else
    {
        if(key == (*T)->data)
        {
            return Delete(T);
        }
        else if(key<(*T)->data)
        {
            return DeleteBST(&(*T)->lchild,key);
        }
        else{
            return DeleteBST(&(*T)->rchild,key);
        }
    }
}
int Delete(pBTNode *p)
{
    pBTNode q,s;
    if((*p)->rchild == NULL)
    {
        q=*p;
        *p=(*p)->lchild;
        free(q);
    }
    else if((*p)->lchild ==NULL)
    {
        q=*p;
        *p=(*p)->rchild;
        free(q);
    }
    else
    {
        q=*p;
        s= (*p)->lchild;
        while(s->rchild)
        {
            q=s;
            s=s->rchild;
        }
        (*p)->data=s->data;
        if(q!=*p)
        {
            q->rchild=s->lchild;
        }
        else{
            q->lchild=s->lchild;
        }
        free(s);
    }
    return 1;
}
//先序遍历
void prePrintf(BTNode *p)
{
    if(p!=NULL)
    {
        prePrintf(p->lchild);
        printf("%d ",p->data);
        prePrintf(p->rchild);
        
    }
}
//平衡二叉排序树

int main()
{
    BTNode *p=NULL;
    int k[10]={45,32,15,7,29,66,77,23,12,45};
    CreateBST(&p,k,10);
    DeleteBST(&p,29);
    BSTInsert(&p,88);
    prePrintf(p);
    return 0;
}
