#include<stdio.h>
#include<stdlib.h>

int insert_first()
{

}
int main()
{
    struct node
    {
        int data;
        struct node* next;
    };
    struct node *head, *newnode, *temp;
    head = NULL;
    int choice=1,count = 0;
    while(choice)
    {
        newnode = (struct node*) malloc(sizeof(struct node));
        printf("enter data : ");
        scanf("%d",&newnode->data);
        newnode->next=0;
        if (head == NULL)
        {
            head=temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
        printf("do you want to continue(0,1)?");
        scanf(" %d",&choice);
    }

    //print the value 
    temp=head;
    while (temp != NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
        count++;
    }
    printf("\nNumber of node in list: %d ",count);
    return 0;
}