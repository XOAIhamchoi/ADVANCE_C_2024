#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct queue
{
    int *items;
    int size;
    int rear, front;
}queue_t;

void initialize(queue_t* queue, int size)
{
    queue->items =(int*)malloc(sizeof(int)*size);  
    queue->size=size;
    queue->front=-1;
    queue->rear=-1;  
}
int is_empty(queue_t queue)
{
    return queue.front == -1 ? true:false;
}
int is_full(queue_t queue)
{
    return (queue.rear+1) % queue.size == queue.front ? true:false;
}
void enqueue(queue_t* queue,int value)
{
    if(is_full(*queue))
    {
        printf("queue is overload\n");
        return;
    }
    if(is_empty(*queue))
    {
        queue->front=queue->rear= 0;
        queue->items[queue->rear]=value;
    }
    else 
    {
        queue->rear=(queue->rear+1)%queue->size;
    }
    queue->items[queue->rear] = value;
}

int dequeue(queue_t* queue)
{
    if(is_empty(*queue))
    {
        printf("queue is empty\n");
        return -1;
    }
    int value=queue->items[queue->front];
    if(queue->front==queue->rear)
    {
        queue->rear=queue->front=-1;
    }
    else
    {
        queue->front = (queue->front+1)%queue->size;
    }
    return value;
}
int front(queue_t queue)
{
    if(is_empty(queue))
    {
        printf("queue is empty\n");
        return -1;
    }
    return queue.items[queue.front];
}
int rear(queue_t queue)
{
    if(is_empty(queue))
    {
        printf("queue is empty\n");
        return -1;
    }
    return queue.items[queue.rear];
}

int main(int argc, char const *argv[])
{
    queue_t queue;
    initialize(&queue, 3);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    printf("Front element: %d\n", front(queue));

    printf("Dequeue element: %d\n", dequeue(&queue));
    printf("Dequeue element: %d\n", dequeue(&queue));

    printf("Front element: %d\n", front(queue));

    enqueue(&queue, 40);
    enqueue(&queue, 50);
    printf("Dequeue element: %d\n", dequeue(&queue));
    printf("Front element: %d\n", front(queue));
    return 0;
}






