#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head, *tail;

void create()
{
    struct node *newnode;
    tail=0;
    int choice=1;
    while(choice)
    {
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("enter data: ");
    scanf("%d",&newnode->data);
    if(tail == NULL)
    {     
           tail = newnode;
           tail->next = newnode;
    }
    else
    {
        newnode->next=tail->next;
        tail->next=newnode;
        tail=newnode;
    }
    tail->next->data;
    printf("would you like to contiue(1,0)");
    scanf("%d",&choice);
    }
}

void viewList()
{
    // If list is empty
    if (tail == NULL)
        printf("\nList is empty\n");
    else
    {
        struct node *temp;
        temp = tail->next;
        do
        {
            printf("\nData = %d", temp->data);
            temp = temp->next;
        } while (temp != tail->next);
    }
}

int main()
{
    create();
    viewList();

    return 0;
}