#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int data;
  struct Node *next;
}Node;

Node *first = NULL;

// creating a linked list using an array of values provided 
void create(int arr[], int n)
{
  if(n==0)
  {
    printf("An array is empty, aborting!\n");
    exit(-1);
  }
  Node *t, *last;
  int i;
  first = (Node *) malloc(sizeof(Node));
  first->data = arr[0];
  first->next = NULL;
  last = first;
  for(i=1;i<n;i++)
  {
    t = (Node *) malloc(sizeof(Node));
    t->data = arr[i];
    t->next = NULL;
    last->next = t;
    last = t;
  }
}

// inserting a node at the beginning of the linked list
void insert_at_beginning(Node **first, int value)
{
  Node *ptr = (Node *) malloc(sizeof(Node));
  ptr->data = value;
  ptr->next = *first;
  *first = ptr;
}

//inserting a node at the end of linked list 
void insert_at_end(Node **first, int value)
{
  Node *t, *ptr;
  ptr = (Node *) malloc(sizeof(Node));
  ptr->data = value;
  ptr->next = NULL;
  t = *first;
  while(t->next!=NULL)
  {
    t = t->next;
  }
  t->next = ptr;
}

// serching for a postion and checking if the value exists
void search_value(Node *first, int value)
{
  Node *ptr;
  ptr = first;
  int pos=0;
  if(ptr == NULL)
  {
    printf("Linked list is empty, no nodes found! \n");
    return;
  }
  while(ptr->data != value)
  {
    ptr = ptr->next;
    pos++;
    if (ptr->next == NULL && ptr->data != value)
    {
      printf("This value does not exist in linked list! \n");
      return;
    }  
}

printf("Value %d is found at position %d \n",ptr->data,pos);

}


//sum of all elements in the linked list

int calculate_sum(Node *ptr)
{
  int sum = 0,count = 0;
  while(ptr != NULL)
  {
    sum = sum + ptr->data;
    count++;
    ptr = ptr->next;
  }
  return sum;
}

//finding the maximum value in the linked list
int max_value(Node *ptr)
{
  if(ptr==NULL)
  {
    printf("Linked list is empty \n");
    return 0;
  }
  int max = ptr->data;
  while(ptr !=NULL)
  {
    if(ptr->data > max)
    {
      max = ptr->data;
    }
    ptr = ptr->next;
  }
  return max;
}

// prints the entire linked list
void display(Node *p)
{
  while(p!=NULL)
  {
    printf("%d -->",p->data);
    p = p->next;
  }
  printf("\n");
}

int main(void)
{
  int arr[] = {2,5,90,65,27,98,76};
  int n = 7;
  create(arr,n);
  display(first);
  insert_at_beginning(&first,0);
  display(first);
  insert_at_end(&first,9);
  display(first);
  search_value(first,2);
  printf("Max value of the linked list is %d\n", max_value(first));
  return 0;
}