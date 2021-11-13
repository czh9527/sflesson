//创建中序线索二叉树
#include <stdio.h>
#include <windows.h>
typedef struct TBTNode
{
      char data;
      int ltag,rtag;
      struct TBTNode *lchild ,*rchild;
}TBTNode;


//中序线索二叉树
void InThread(TBTNode *p,TBTNode **pre)
{
      if(p!=NULL)
        {
              InThread(p->lchild, pre);     //递归，左子树线索化
              if(p->lchild==NULL)//这个时候出来的pre已经是前一个了
              {
                     p->lchild=*pre;         //建立当前结点的前驱线索
                     p->ltag=1;
              }
              if(*pre!=NULL&&(*pre)->rchild==NULL)
              {
                     (*pre)->rchild=p;         //建立前驱结点的后继线索
                     (*pre)->rtag=1;
              }
              (*pre)=p;               //pre指向当前的p，作为p将要指向下一个结点的前驱结点指示指针
              InThread(p->rchild,pre);     //此时的p赋值为p->rchild，pre和p分别指向的结点形成了一个前驱后继对，为下一次线索的链接做准备，递归，右子树线索化
        }
}
////前序线索二叉树
void PreThread(TBTNode *p,TBTNode **pre)
{
     if(p!=NULL)
     {
            if(p->lchild==NULL)
            {
                  p->lchild=*pre;
                  p->ltag=1;
             }
             if(*pre!=NULL&&(*pre)->rchild==NULL)
             {
                   (*pre)->rchild=p;
                   (*pre)->rtag=1;
             }
             *pre=p;
             if(p->ltag==0)    PreThread(p->lchild,pre);          //这里在递归入口处有限制条件，只有在左，右指针不是线索的情况下才继续递归
             if(p->rtag==0)   PreThread(p->rchild,pre);
     }
}
//后序线索二叉树
void PostThread(TBTNode *p,TBTNode **pre)
{
      if(p!=NULL)
      {
           PostThread(p->lchild,pre);          //递归左子树线索化
           PostThread(p->rchild,pre);          //递归右子树线索化
           if(p->lchild==NULL)
           {
                 p->lchild=*pre;           //建立当前结点的前驱线索
                 p->ltag=1;
           }
           if(*pre!=NULL&&(*pre)->rchild==NULL)           //建立前驱结点的后继线索
           {
                (*pre)->rchild=p;
                (*pre)->rtag=1;
           }
           *pre=p;
      }
}

//前序创建二叉树
void creatTBT(TBTNode **bt)
{
      char c;
      scanf("%c",&c);
      if(c=='\n')
      {
            return;
      }
      if(c==' ')
      {
            *bt=NULL;
      }
      else
      {
            *bt = (TBTNode*)malloc(sizeof(TBTNode));
            (*bt)->data=c;
            (*bt)->ltag=(*bt)->rtag=0;
            creatTBT(&(*bt)->lchild);
            creatTBT(&(*bt)->rchild);   
      }
}

//处理pre
void initPre(TBTNode **p,TBTNode *t)
{
      *p= (TBTNode *)malloc(sizeof(TBTNode));
      TBTNode *pre;
      (*p)->ltag=0;
      
      (*p)->rtag=1;
      (*p)->rchild=(*p);

      if(!t)
      {
        (*p)->lchild=*p;
      }
      else{
            (*p)->lchild=t;
            pre=(*p);
            InThread(t,&pre);
      

            pre->rchild=(*p);
            pre->rtag=1;
            (*p)->rchild=pre;
      }
}
//打印
void Visit(char c)
{
      printf("%c",c);
}
//中序遍历线索二叉树
void printTree(TBTNode *t)
{
    TBTNode *p;
    p=t->lchild;
    while(p!=t)
    {
        while(p->ltag==0)//循环到最左边的结点
        {
            p=p->lchild;
        }
        Visit(p->data);
        if(p->rtag==1 && p->rchild != t)//再访问右结点
        {
            p=p->rchild;
            Visit(p->data);
        }
        p=p->rchild;
    }
}
//前序遍历线索树
void PreOrder(TBTNode *t)
{
    TBTNode *p= t->lchild;
    while(p!=t)
    {
        while(p->ltag==0)
        {
            Visit(p);
            p=p->lchild;
        }
        Visit(p);
        p= p->rchild;
    }
}

//后续遍历线索树

int main()
{
      TBTNode *t,*p;
      creatTBT(&t);
      initPre(&p,t);
      printTree(p);
      return 0;
}

