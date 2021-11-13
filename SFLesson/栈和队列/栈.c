#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5
typedef struct 
{
  int data[MAXSIZE];
  int top;
} SQStack;
void inputStack(SQStack *stack)
{
    printf("input your data:");
    int num;
    scanf("%d",&num);
    if(stack->top<MAXSIZE-1)
        stack->data[++(stack->top)]=num;
    else
        printf("over maxsize\n");

    
}
void outStack(SQStack *stack)
{
    
    printf("%d",stack->data[stack->top--]);
}
void nodePrint(SQStack stack)
{
    SQStack s= stack;
    printf ("8*%d\n",stack.data[0]);
    for(int i =stack.top;i>=0;i--)
    {
        printf("-------%d\n",stack.data[i]);
    }
}
int main(){
      

    int tmp=0;
    SQStack stack;
    stack.top=-1;
    while (tmp!=-1)
    {
      printf("1-inputStack\n");
      printf("2-outStack\n");
      printf("0-print\n");
      scanf("%d",&tmp);

      switch (tmp)
      {
        case 1:
          inputStack(&stack);          
          break;
        case 2:
          outStack(&stack);
          break;
        case 0:
          nodePrint(stack);
          break;
        default:
          break;
      }
    }
    
    
    return 0;
}