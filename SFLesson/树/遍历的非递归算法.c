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
//先序遍历非递归算法
void PreOrder(BTNode *bt)
{
      if(bt!=NULL)
      {
            BTNode *Stack[MAXSIZE];    //定义了一个栈
            int top=-1;       //初始化栈
            BTNode *p;
            Stack[++top]=bt;                //根结点入栈
            while(top!=-1)
            {
                   p=Stack[top--];         //出栈并输出栈顶结点
                   Visit(p);               //访问该结点
                   if(p->rchild!=NULL)          //若栈顶结点的右孩子存在，则右孩子入栈
                        Stack[++top]=p->rchild;
                   if(p->lchild!=NULL)          //若栈顶结点的左孩子存在，左右孩子入栈
                        Stack[++top]=p->lchild;
          }
      }
}
//中序遍历非递归算法
void InOrder(BTNode *bt)
{
      if(bt!=NULL)
      {    BTNode *Stack[MAXSIZE];    int top=-1;  //初始化栈
            BTNode *p;
            p=bt; 
            while(top!=-1 || p!=NULL)//p是判断是否到最后一个位置,top！=为了执行后面的if操作,两种都能进入循环，下面两种情况分开
            {      while(p!=NULL)             //先把所有左孩子入栈
                    {       Stack[++top]=p;
                             p=p->lchild;
                    }
                    if( top!=-1)     //此时p=NULL，且栈中还有元素
                    {
                             p=Stack[top--];//出栈元素
                             Visit(p);
                             p=p->rchild;//出栈时赋值p为右孩子进入循环,null也要进入，不然会死循环
                    }
            }
      }
}

// //中序遍历2
// void InOrder(BTNode *bt)
// {
//       if(bt !=NULL)
//       {
//            BTNode * Stack[MAXSIZE];
//            int  top=-1;
//            BTNode * p bt;
//            while(p!=NULL ||top !=-1)
//            {
//                  if(p!=NULL)
//            {
//                  stack[++top]=p;
//                  p=p->lchild;
//            }
//            else
//            {
//                  p=stack[top--];
//                  Visit(p);
//                  p=p->rchild;
//            }
//            }
           
//       }
// }
//后序遍历的非递归算法
void PostOrder(BTNode *bt)
{
        BTNode *Stack[MAXSIZE];    int top=-1;  //初始化栈
        BTNode *p,*r;
        p=bt;  r=NULL;
        while(p!=NULL || top!=-1)
       {   if(p!=NULL)                                 //走到最左边
           {   
                  Stack[++top]=p;
                 p=p->lchild;
           }
           else
           {     p=Stack[top];                 //读栈顶结点
                  if(p->rchild&&p->rchild!=r)     p=p->rchild;    //若右子树存在且未被访问过则转向右--可能是另外一个结点的根节点导致重复遍历
                  else
                  {     p=Stack[top--];      //否则出栈
                         Visit(p);     //访问该结点
                         r=p;  
                         p=NULL;//p已经在上方入完了，不能再入了
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
    PostOrder(t);
    return 0;
}
