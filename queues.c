#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int size;
    int *front;
    int *rear;
    int *arptr;
}Queue;

void create(Queue *ptr)
{
    printf("Enter the size of the queue: ");
    scanf("%d",&ptr->size);
    ptr->front = NULL;
    ptr->arptr = (int *) malloc(ptr->size * sizeof(int));
    ptr->rear = ptr->arptr;
}

// enqueue, dequeue, peek, isEmpty, isFull, display

void enqueue(Queue *ptr, int value)
{
    if (ptr->rear == ptr->arptr + ptr->size)
    {
        printf("The queue is full, element could not be enqueued\n");
        return;
    }
    if (ptr->rear == ptr->arptr)
    {
        *(ptr->arptr) = value;
        ptr->front = ptr->arptr;
        ptr->rear = ptr->rear + 1;
        return;
    }
    int *p = ptr->rear;
    *p = value;
    p++;
    ptr->rear = p;
}

void display(Queue *ptr)
{
    int *t;
    t = ptr->front;
    if(t == NULL)
    {
        printf("Nothing in the queue, nothing to print out \n");
    }
    while(t != ptr->rear)
    {
        printf("%d-->",*t);
        t = t + 1;
    }
}

void dequeue(Queue *ptr)
{
    if(ptr->front == NULL)
    {
        printf("Queue is empty, nothing to dequeue\n");
        return;
    }
    if(ptr->front + 1 == ptr->rear)
    {
        ptr->front = NULL;
        ptr->rear = ptr->arptr;
        return;
    }
    ptr->front = ptr->front + 1;
}

int isFull(Queue *ptr)
{
    if (ptr->rear == ptr->arptr + ptr->size)
    {
        printf("Queue is full, no space for further values\n");
        return 1;
    }
    printf("Queue is not full, there is a space for further enqueue operations\n");
    return 0;
}

int isEmpty(Queue *ptr)
{
    if(ptr->front == NULL)
    {
        printf("Queue is empty, no elements in there\n");
        return 1;
    }
    printf("Queue is not empty \n");
    return 0;
}

int main(void)
{
    Queue queue;
    create(&queue);
    enqueue(&queue,18);
    enqueue(&queue,20);
    enqueue(&queue,24);
    enqueue(&queue,29);
    dequeue(&queue);
    isEmpty(&queue);
    isFull(&queue);
    display(&queue);
}