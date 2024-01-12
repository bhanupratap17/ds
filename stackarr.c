//impliment stack using array
#include <stdio.h>
#include <conio.h>
#define N 5
int stack[N];
int top = -1;

void push()
{
    int x;
    printf("enter value: ");
    scanf("%d", &x);
    if (top == N - 1)
    {
        printf("overflow\n");
    }
    else
    {
        top++;
        stack[top] = x;
    }
}

void pop()
{
    int item;
    if (top == -1)
    {
        printf("stack is underflow\n");
    }
    else
    {
        item = stack[top];
        top--;
        printf("%d\n", item);
    }
}

void peek()
{
    if (top == -1)
    {
        printf("stack is underflow\n");
    }
    else
    {
        printf("%d\n", stack[top]);
    }
}

void display()
{
    int i;
    if (top == -1)
    {
        printf("stack is empty\n");
    }
    else
    {
        for (i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main()
{
    int choice;
    do
    {
        printf("enter choice: 1.push\n2.pop\n3.peek\n4.display\n");
        printf("enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        default:
            printf("invalid choice\n");
            break;
        }
    } while (choice != 0);
    return 0;
}
