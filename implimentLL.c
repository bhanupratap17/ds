#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head, *newnode, *temp;

// Function to create list with n nodes initially
void createlist()
{
    // struct node *head, *newnode, *temp;
    head = NULL;
    int choice=1;;
    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("enter data : ");
        scanf("%d", &newnode->data);
        newnode->next = 0;
        if (head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        printf("do you want to continue(0,1)?");
        scanf(" %d", &choice);
    }
}

void printlist(){
    if(head == NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        temp = head;
        printf("\nlist : \n");
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
            // count++;
        }
    }
}

void insertAtfront()
{
    newnode = (struct node*) malloc(sizeof(struct node));
    printf("Enter data you want to insert at first: ");
    scanf("%d",&newnode->data);
    newnode->next = head;
    head=newnode;
}

void insertAtEnd()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data you want to insert at end: ");
    scanf("%d", &newnode->data);

    newnode->next = 0;
    temp = head;
    while (temp->next != 0)
    {
        temp = temp->next;
 }
 temp->next = newnode;
}

void insertAtPostion()
{
    int pos, i=1;
    printf("\nEnter index : ");
    scanf("%d", &pos);
    temp=head;
    while(i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    // struct node *head, *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter data : ");
    scanf("%d", &newnode->data);
    newnode->next = temp->next;
    temp->next = newnode;
}

void deleteFrombeg()
{
    if (head == NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        temp = head;
        head = head->next;
        free(temp);
        printf("starting node deleted\n");
    }
}

void deleteFromend()
{
    struct node *prevnode;
    temp = head;
    while (temp->next != 0)
    {
        prevnode = temp;
        temp = temp->next;
}
// if only one node 
if(temp == head)
{
    head = 0;
}
else
{
    prevnode->next = 0;
    free(temp);
    printf("Last node deleted\n");
}
}

void deleteAtPos()
{
    struct node *nextnode;
        int pos, i = 1;
        temp = head;
        printf("enter positon: ");
        scanf("%d", &pos);
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        nextnode = temp->next;
        temp->next = nextnode->next;
        free(nextnode);
}

void getLength()
{
    int length = 0;
    temp = head;
    while(temp != NULL)
    {
        length++;
        temp = temp->next; 
    }
    printf("length of linked list : %d", length);
}

void reverse()
{
    struct node *prevnode, *currnode, *nextnode;
    prevnode = 0;
    currnode = nextnode = head;
    while(nextnode != 0)
    {
        nextnode = nextnode->next;
        currnode->next = prevnode;
        prevnode = currnode;
        currnode = nextnode;
    }
    head = prevnode;
}

int main()
{
    createlist();
    insertAtfront();
    insertAtEnd();
    insertAtPostion();
    printlist();
    deleteFrombeg();
    deleteFromend();
    deleteAtPos();
    getLength();
    printlist();
    reverse();
    printlist();
    return 0;   
}