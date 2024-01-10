#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head, *tail;

void create()
{
    struct node *newnode;
    head = 0;
    int choice = 1;
    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("enter data : ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        newnode->prev = NULL;
        if (head == NULL)
        {
            tail = head = newnode;
        }
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
        printf("do you want to continue(0,1)?");
        scanf("%d", &choice);
    }
    printf("\nlist created\n");
}

void printList()
{
    tail = head;
   if(head==NULL)
   {
       printf("\nno node here : \n");
   }
   else
   {
    printf("\nlist: ");
       while (tail != NULL)
       {
           printf("%d", tail->data);
           tail = tail->next;
       }
   }
    
}

void insertAtfirst()
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("enter data to insert at first: ");
    scanf("%d", &newnode->data);
    newnode->prev=NULL;
    newnode->next=NULL;
    if(head==NULL)
    {
        printf("doubly linked list is empty");
    }
    else
    {
        head->prev=newnode;
        newnode->next=head;
        head=newnode;
    }
}

void insertAtlast()
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter data to insert at last: ");
    scanf("%d", &newnode->data);
    newnode->prev=NULL;
    newnode->next=NULL;
    if(head==NULL)
    {
        printf("empty doubly linked list");
    }
    else
    {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }

}

void insertAtpos()
{
    int pos;
    printf("\nenter postion: ");
    scanf("%d",&pos);
    if(pos<1)
    {
        printf("invalid");
    }
    else if(pos==1)
    {
        insertAtfirst();
    }
    else
    {
        struct node *newnode, *temp;
        int i=1;
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("enter data to insert at postion %d : ",pos);
        scanf("%d", &newnode->data);
        newnode->prev = NULL;
        newnode->next = NULL;
        temp = head;
        while(i<pos-1)
        {
            temp = temp->next;
            i++;
        }
        newnode->prev = temp;
        newnode->next = temp->next;
        if(temp->next != NULL)
        {
            temp->next->prev = newnode;
        }
        temp->next = newnode;
    }

}

void insertAfterpos()
{
    struct node *newnode, *temp;
    int pos, i = 1; // Initialize i to 1
    printf("enter position to insert after it: ");
    scanf("%d", &pos);

    if (pos < 1)
    {
        printf("invalid position");
    }
    else if (pos == 1)
    {
        insertAtfirst();
    }
    else
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("enter data: ");
        scanf("%d", &newnode->data);
        newnode->prev = NULL;
        newnode->next = NULL;
        temp = head;

        // Check if the position is within the current length of the linked list
        while (i < pos && temp != NULL)
        {
            temp = temp->next; // Move to the next node
            i++;
        }

        if (temp == NULL)
        {
            printf("Invalid position. The list is not long enough.\n");
        }
        else
        {
            newnode->prev = temp;
            newnode->next = temp->next;

            if (temp->next != NULL)
            {
                temp->next->prev = newnode;
            }

            temp->next = newnode;
        }
    }
}

void deleteAtfirst()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("empty");
    }
    else
    {
        temp = head;
        head=head->next;
        head->prev=NULL;
        free(temp);
        printf("\nfirst node deleted\n");
    }
}

void deleteAtend()
{
    struct node *temp;
    if (tail == NULL)
    {
        printf("\nThe list is empty.\n");
    }
    else
    {
        temp = tail;
        if (tail->prev != NULL)
        {
            tail->prev->next = NULL;
            tail = tail->prev;
        }
        else
        {
            // If there is only one node in the list
            head = tail = NULL;
        }
        free(temp);
        printf("\nLast node deleted successfully.\n");
    }
}

void deleteBypos()
{
    struct node *temp;
    int pos, i = 1;
    printf("\nenter position to delete: ");
    scanf("%d", &pos);

    if (pos < 1)
    {
        printf("invalid position");
        return;
    }

    temp = head;

    // Check if the position is within the current length of the linked list
    while (temp != NULL && i < pos)
    {
        temp = temp->next;
        i++;
    }

    if (temp == NULL)
    {
        printf("Invalid position. The list is not long enough.\n");
        return;
    }

    if (temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }
    else
    {
        // If the node to be deleted is the head node
        head = temp->next;
    }

    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }

    free(temp);
    printf("Node at position %d deleted successfully.\n", pos);
}

int main()
{
    create();
    insertAtfirst();
    insertAtlast();
    printList();
    insertAtpos();
    insertAfterpos();
    printList();
    deleteAtfirst();
    deleteAtend();
    deleteBypos();
    printList();
}