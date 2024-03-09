#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
}*first = NULL,*tmp = NULL;

int menu()
{
    int a;
    printf("\n-:PRESS 1 TO CREATE THE LIST:-\n");
    printf("\n-:PRESS 2 TO INSERT A NODE AT BEGENING:-\n");
    printf("\n-:PRESS 3 TO INSERT A NODE AT ANY POINT:-\n");
    printf("\n-:PRESS 4 TO INSERT A NODE AT END:-\n");
    printf("\n-:PRESS 5 TO DELETE A NODE AT BEGENING:-\n");
    printf("\n-:PRESS 6 TO DELETE A NODE AT ANY POINT:-\n");
    printf("\n-:PRESS 7 TO DELETE A NODE AT END:-\n");
    printf("\n-:PRESS 8 TO DISPLAY THE LIST:-\n");
    printf("\n-:PRESS 9 TO EXIT:-\n");
    printf("\nEnter Your Choice:- ");
    scanf("%d",&a);
    return a;
}

void createlist(int n)
{
    int i;
    struct node *head,*newnode;
    printf("Enter the 1 Node:- \n");
    head = (struct node*)malloc(sizeof(struct node));
    scanf("%d",&head -> data);
    head -> link = NULL;
    first = head;
    tmp = head;
    if(head == NULL)
    {
        printf("-:MEMORY ALLOCATION FAILED:-\n");
    }
    else
    {
        for(i=1;i<n;i++)
        {
            printf("Enter the %d Node:- \n",i+1);
            newnode = (struct node*)malloc(sizeof(struct node));
            scanf("%d",&newnode -> data);
            newnode -> link = NULL;
            tmp -> link = newnode;
            tmp = tmp -> link;
        }
    }
}

void insertatbeg()
{
    struct node *node;
    printf("\nEnter the New Node:- \n");
    node = (struct node*)malloc(sizeof(struct node));
    scanf("%d",&node -> data);
    node -> link = first;
    first = node;
}

void insertatany(int n)
{
    struct node *ptr,*node;
    int s;
    ptr = first;
    printf("\nEnter the position u want to insert the new node:- \n");
    scanf("%d",&s);
    printf("Enter the New Node:- \n");
    node = (struct node*)malloc(sizeof (struct node));
    scanf("%d",&node -> data);
    for(int i=1;i<s-1;i++)
        ptr = ptr -> link;
    node -> link = ptr -> link;
    ptr -> link = node;
}

void insertatend(int n)
{
    struct node *node,*ptr;
    ptr = first;
    printf("\nEnter the New Node:- \n");
    node = (struct node*)malloc(sizeof(struct node));
    scanf("%d",&node -> data);
    node -> link = NULL;
    while(ptr -> link != NULL)
    {
        ptr = ptr -> link;
    }
    ptr -> link = node;
}

void deleteatbeg()
{
    struct node *del;
    int i;
    del = first;
    first = first -> link;
    printf("\nThe Deleted value is:- %d\n",del -> data);
    free(del);
}

void deleteatany(int n)
{
    struct node *del,*ptr;
    int a,count = 0;
    del = ptr = first;
    printf("Enter the position u want to DELETE:- ");
    scanf("%d",&a);
    if(a == 1)
        deleteatbeg();
    else
    {
        for(int i=1;i<a-1;i++)
        {
            ptr = ptr -> link;
        }   
        del = ptr -> link;
        ptr -> link = ptr -> link -> link;
        printf("The Deleted Node is:- %d\n",del -> data);
        free(del);
    }
}

void deleteatend(int n)
{
    struct node *del = first;
    int a;
    while(del -> link -> link != NULL)
        del = del -> link;
    printf("The Deleted Node is:- %d",del -> link -> data);
    del -> link = NULL;
    free(del -> link);
}

void displaylist()
{
    struct node *temp;
    temp = first;
    if(first == NULL)
        printf("\n-:Linked list is Empty:-");
    else
    {
        printf("-:LINKED LIST:-");
        while(temp != NULL)
        {
            printf("%d ",temp -> data);
            temp = temp -> link;
        }
    }
}

void main()
{
    int n,a,b;
    
    while(1)
    {
        b = menu();
        switch(b)
        {
            case 1:
                printf("Enter the Size of Linked List:-\n ");
                scanf("%d",&n);
                createlist(n);
                break;
            case 2:
                insertatbeg();
                break;
            case 3:
                insertatany(n);
                break;
            case 4:
                insertatend(n);
                break;
            case 5:
                deleteatbeg();
                break;
            case 6:
                deleteatany(n);
                break;
            case 7:
                deleteatend(n);
                break;
            case 8:
                displaylist();
                break;
            case 9:
                exit(0);
                break;
            default:
                printf("-:Enter A correct Choice:-");
        }
    }

    

}
