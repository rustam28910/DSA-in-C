#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int size; //size of the array
    int front; // pointer to the first of the queue
    int rear;//pointer to the last element of the queue
    int * arptr; //pointer to an array
}Queue;


void create(Queue *ptr)
{
    printf("Enter the size of the queue: ");
    scanf("%d",&ptr->size);
    ptr->front = ptr->rear = 0;
    ptr->arptr = (int *) malloc(sizeof(int) * ptr->size);
    printf("Array of size %d created successfully \n", ptr->size);
}


void enqueue(Queue *ptr, int value)
{
    if((ptr->rear + 1) % ptr->size == ptr->front)
    {
        printf("Queue is full\n");
    }
    else
    {
        ptr->rear = (ptr->rear + 1) % ptr->size;
        ptr->arptr[ptr->rear] = value;
    }    

}

int dequeue(Queue *ptr)
{
    int x = -1;
    if(ptr->front == ptr->rear)
    {
        printf("Queue is empty, nothing to dequeue \n");
        return x;
    }

    x = ptr->arptr[ptr->front];
    ptr->front = (ptr->front + 1) % ptr->size;
    return x;

}

int isFull(Queue *ptr)
{
    if ((ptr->rear + 1) % ptr->size == ptr->front)
    {
        printf("Queue is full \n");
        return 1;
    }
    printf("Queue is not full \n");
    return 0;
}

int isEmpty(Queue *ptr)
{
    if (ptr->front == ptr->rear)
    {
        printf("Queue is empty \n");
        return 1;
    }
    printf("Queue is not empty \n");
    return 0;
}

int peek(Queue *ptr)
{
    int x = -1;
    if (ptr->front == ptr->rear)
    {
        printf("Queue is empty, nothing to look for\n");
        return x;
    }

    return ptr->arptr[ptr->front];
}

void display(Queue *ptr)
{
    while(ptr->front != ptr->rear)
    {
        printf("%d -->",ptr->arptr[ptr->front]);
        ptr->front = (ptr->front + 1) % ptr->size;
    }
    printf("%d.\n",ptr->arptr[ptr->front]);
}

int main(void)
{
    Queue queue;
    create(&queue);
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40);
    enqueue(&queue, 50);
    dequeue(&queue);
    enqueue(&queue, 60);
    dequeue(&queue);
    dequeue(&queue);
    peek(&queue);
    isEmpty(&queue);
    isFull(&queue);
    display(&queue);
    return 0;
}