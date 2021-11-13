#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5
typedef struct 
{
  int data[MAXSIZE];
  int front;
  int rear;
} SqQueue;
void inputQueue(SqQueue *squeue)
{
    printf("input your data:");
    int num;
    scanf("%d",&num);
    if((squeue->rear+1)%(MAXSIZE) == squeue->front)
    {
      printf("full\n");
      return;
    }
    squeue->data[squeue->rear]=num;
    squeue->rear=(squeue->rear+1)%MAXSIZE;
    
}
void outQueue(SqQueue *squeue)
{
  if(squeue->front==squeue->rear)
    {
      printf("empty\n");
      return;
    }
    printf("delete-%d",squeue->data[squeue->front]);
  squeue->front = (squeue->front+1)%MAXSIZE;
  
}
void nodePrint(SqQueue squeue)
{
    if(squeue.rear<squeue.front)
    {
      for(int i =squeue.front;i<MAXSIZE;i++)
      {
        printf("----%d\n",squeue.data[i]);
      }
      for(int i =0;i>squeue.rear;i++)
      {
        printf("----%d\n",squeue.data[i]);
      }
      
    }
    else{
      for(int i = squeue.front;i<squeue.rear;i++)
      {
        printf("-----%d\n",squeue.data[i]);
      }
    }
}
int main(){
      

    int tmp=0;
    SqQueue squeue;
    squeue.front=squeue.rear=0;
    while (tmp!=-1)
    {
      printf("1-inputQueue\n");
      printf("2-outQueue\n");
      printf("0-print\n");
      scanf("%d",&tmp);

      switch (tmp)
      {
        case 1:
          inputQueue(&squeue);          
          break;
        case 2:
          outQueue(&squeue);
          break;
        case 0:
          nodePrint(squeue);
          break;
        default:
          break;
      }
    }
    
    
    return 0;
}