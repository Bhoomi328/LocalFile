#include <stdio.h>
#include <stdlib.h>
#define N 10
typedef struct queue
{
    int q[N];
    int f;
    int b;
}queue;

void  QueueInit(queue* ptr);
void IsEmpty(queue* ptr);
void EnQueue(int val,queue* ptr);
void DeQueue(queue* ptr);
void IsFull(queue* ptr);
void PrintQueue(queue* ptr);
void peek(queue* ptr);
int main()
{
    int val;
    struct queue queue;
    struct queue* ptr = &queue;
    QueueInit(ptr);
    //IsEmpty(ptr);
    EnQueue(1,ptr);
    EnQueue(2,ptr);
    EnQueue(3,ptr);
    EnQueue(4,ptr);
    EnQueue(5,ptr);
    EnQueue(6,ptr);
    PrintQueue(ptr);
    peek(ptr);
    printf("\n");
    DeQueue(ptr);
    DeQueue(ptr);
    DeQueue(ptr);
    //IsFull(ptr);
    PrintQueue(ptr);
    peek(ptr);
    return 0;
}
void  QueueInit(queue* ptr)
{
   ptr->f = -1;
   ptr->b = -1;
}
void IsEmpty(queue* ptr)
{
    if(ptr->f == -1)
    {
        printf("the queue is empty");
        printf("\n");
    }
    else
    {
       printf("the queue is not empty");
       printf("\n");
    }
}
void EnQueue(int val,queue* ptr)
{
   if(ptr->b == N-1)
   {
      printf("not possible:");
      return ;
   }
    ptr->f = 0;
    ptr->b++;
    ptr->q[ptr->b] = val;
}
void DeQueue(queue* ptr)
{
    if(ptr->f == -1)
    {
        printf("empty queue");
        return;
    }
     ptr->f++;
     if(ptr->f == ptr->b)
     {
         ptr->f = -1;
         ptr->b = -1;
     }
}
void IsFull(queue* ptr)
{
  if(ptr->b == N-1)
  {
      printf("queue is full");
  }
  else
  {
     printf("queue is not full");
  }
}
void peek(queue* ptr)
{
   if(ptr->f == -1)
   {
       printf("queue is empty");
   }
    printf("the peek value is:%d ",ptr->q[ptr->f]);
}
void PrintQueue(queue* ptr)
{
    if(ptr->f == -1)
    {
        printf("queue is null");
    }
     int temp = ptr->f;
      printf("front-->");
     while(temp <= ptr->b)
    {
        printf("%d ",ptr->q[temp]);
        temp++;
    }
    printf("<--back   ");
}





