#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Node;

typedef struct Queue
{
    Node *front;
    Node *rear;
}Queue;

// display

void enqueue(Queue *ptr, int value)
{
    Node *p = (Node *) malloc(sizeof(Node));
    if(p==NULL)
    {
        printf("Failed to allocated heap space for a new Node, Heap is full! \n");
        return;
    }

    p->data = value;
    p->next = NULL;

    if(ptr->rear == NULL)
    {
        ptr->front = p;
        ptr->rear = p;
        return;
    }

    ptr->rear->next = p;
    ptr->rear = p;
    printf("This is the enque function using linked lists ")
}

void dequeue(Queue *ptr)
{
    if(ptr->front == NULL)
    {
        printf("Queue is empty, no elements to dequeue it \n");
        return;
    }

    Node *t = ptr->front;
    ptr->front = ptr->front->next;
    free(t);
}

int isEmpty(Queue *ptr)
{
    if (ptr->front == NULL)
    {
        printf("Queue is emtpy \n");
        return 1;
    }
    printf("Queue is not empty \n");
    return 0;
}

int isFull()
{
    Node *p = (Node *) malloc(sizeof(Node));
    if (p==NULL)
    {
        printf("No memory available in heap for another node, queue is full\n");
        return 1;
    }
    printf("Sapce allocated for a new element \n");
    free(p);
    return 0;
}

int peek(Queue *ptr)
{
    int x = -1;
    if(ptr->front == NULL)
    {
        printf("No element in the queue \n");
        return x;
    }
    x = ptr->front->data;
    return x;
}

void display(Queue *ptr)
{
    Node *t;
    t = ptr->front;
    while(t!=NULL)
    {
        printf("%d --> ",t->data);
        t = t->next;
    }
}

int main(void)
{
    Queue queue;
    queue.front = NULL;
    queue.rear = NULL;
    return 0;
}