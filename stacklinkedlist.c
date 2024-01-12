#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};
struct node *top = NULL;

void push(int x)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->link = top;
    top = newnode;
    printf("Node pushed in stack\n");
}

void display()
{
    struct node *temp;
    temp = top;
    if (top == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
}

void peek()
{
    if (top == NULL)
    {
        printf("Stack is underflow\n");
    }
    else
    {
        printf("Top element: %d\n", top->data);
    }
}

void pop()
{
    struct node *temp;
    if (top == NULL)
    {
        printf("Stack is underflow\n");
    }
    else
    {
        temp = top;
        printf("Popped element: %d\n", top->data);
        top = top->link;
        free(temp);
    }
}

int main()
{
    push(2);
    push(3);
    push(10);
    display();
    peek();
    pop();
    display();
    return 0;
}
