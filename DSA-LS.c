#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

Queue* createQueue();
Queue* InitialQueue(Queue* queue);
void enqueue(Queue* queue, int value);
int dequeue(Queue* queue);
int peek(Queue* queue);
void isEmpty(Queue* queue);
void freeQueue(Queue* queue);
void printQueue(Queue* queue);

int main() {
    Queue* queue = createQueue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    printQueue(queue);
    int res =  peek(queue);
    printf("peek value is = %d",res);
    printf("\n");
    dequeue(queue);
    dequeue(queue);
    printQueue(queue);
    freeQueue(queue);
    return 0;
}
Queue* InitialQueue(Queue* queue)
{
   queue->front = -1;
   queue->rear = -1;
}


Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

void enqueue(Queue* queue, int value)
 {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    if (queue->rear == NULL)
    {
        queue->front = newNode;
        queue->rear = newNode;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue(Queue* queue)
 {
   if(queue->front == -1)
   {
       printf("queue is empty");
   }
    Node* temp = queue->front;
    int value = temp->value;
    queue->front = queue->front->next;

    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }

    free(temp);
    return value;
}

/*int peek(Queue* queue)
{
   if(queue->front == -1)
   {
       printf("empty");
   }
    return queue->front->value;
}*/

void isEmpty(Queue* queue)
{
   if(queue->front == -1)
   {
       printf("empty");
   }
   else
   {
       printf("not empty");
   }
}
void printQueue(Queue* queue)
{
   if(queue->front == NULL)
   {
       printf("queue is empty");
   }
    Node* temp = queue->front;
    printf("Queue elements: ");

    while (temp != NULL) {
        printf("-->%d ", temp->value);
        temp = temp->next;
    }
}

void freeQueue(Queue* queue)
{
    free(queue);
}





