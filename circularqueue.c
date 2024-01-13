// implement circular queue using array but this code is not give the right output.?
#include <stdio.h>
#define N 5
int queue[N];
int front, rear = -1;

void enqueue(int x)
{
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = x;
    }
    else if ((rear + 1) % N == front)
    {
        printf("queue is overflow");
    }
    else
    {
        rear = (rear + 1) % N;
        queue[rear] = x;
    }
}

void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("queue is underflow");
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        printf("%d ", queue[front]); // Add a space after printing the element
        front = (front + 1) % N;
    }
}

void display()
{
    int i = front; // Initialize i to front
    if (front == -1 && rear == -1)
    {
        printf("queue is empty");
    }
    else
    {
        printf("queue is: ");
        while (i != rear)
        {
            printf("%d ", queue[i]); // Add a space after printing each element
            i = (i + 1) % N;
        }
        printf("%d", queue[i]); // Print the last element
    }
}

int main()
{
    enqueue(5);
    enqueue(6);
    enqueue(7);
    display();
    dequeue();
    display();
    return 0;
}
