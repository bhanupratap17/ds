//queue implement using array
#include <stdio.h>
#define N 5

int queue[N];
int front, rear = -1;

void enqueue(int x)
{
    if (rear == N - 1)
    {
        printf("Queue is overflow\n");
    }
    else if (front == -1 && rear == -1)
    {
        printf("Only one element present\n");
        front = rear = 0;
        queue[rear] = x;
    }
    else
    {
        rear++;
        queue[rear] = x;
    }
}

void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is underflow\n");
    }
    else if (front == rear)
    {
        printf("Dequeued element: %d\n", queue[front]);
        front = rear = -1;
    }
    else
    {
        printf("Dequeued element: %d\n", queue[front]);
        front++;
    }
}

void display()
{
    int i;
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        for (i = front; i <= rear; i++)
        {
            printf("%d\n", queue[i]);
        }
    }
}

void peek()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Front element: %d\n", queue[front]);
    }
}

void main()
{
    enqueue(2);
    enqueue(5);
    enqueue(-1);
    display();
    peek();
    dequeue();
    peek();
    display();
}
