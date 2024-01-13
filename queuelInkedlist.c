#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int x)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    if (front == NULL && rear == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}

void dequeue()
{
    struct node *temp;
    if (front == NULL && rear == NULL)
    {
        printf("Queue is underflow\n");
    }
    else
    {
        temp = front;
        front = front->next;
        free(temp);
    }
}

void display()
{
    struct node *temp;
    if (front == NULL && rear == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        temp = front;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void peek()
{
    if (front == NULL && rear == NULL)
    {
        printf("Queue is underflow or empty\n");
    }
    else
    {
        printf("Front element: %d\n", front->data);
    }
}

int main()
{
    enqueue(2);
    enqueue(3);
    enqueue(5);
    display();
    peek();
    dequeue();
    display();

    return 0;
}
