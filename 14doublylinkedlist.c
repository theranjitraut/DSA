// Doubly Linked List Implementation
#include <stdio.h> 
#include <stdlib.h>
struct doublylinkedlist
{
    int info;
    struct doublylinkedlist *prevlink; 
    struct doublylinkedlist *nextlink;
};
void insertatfirst(struct doublylinkedlist **, int); 
void insertatlast(struct doublylinkedlist **, int);
void insertafteranyposition(struct doublylinkedlist **, int, int); 
void deletefromfirst(struct doublylinkedlist **);
void deletefromlast(struct doublylinkedlist **);
void deletefromanyposition(struct doublylinkedlist **, int); 
void display(struct doublylinkedlist **);
int main() 
{
    struct doublylinkedlist *startnode; 
    startnode=NULL; 
    int item;
    int position;
    int option; 
    int ch;
    printf("What do you want to do?\n"); 
    printf("1.Insert node at first\n"); 
    printf("2.Insert node at last\n"); 
    printf("3.Insert node at any position\n"); 
    printf("4.Delete node at first\n"); 
    printf("5.Delete node at last\n"); 
    printf("6.Delete node at any position\n"); 
    printf("7.Display the doubly linked list\n"); 
    while(ch!=8) 
    {
        printf("Enter your choice: "); 
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
            printf("Enter the information part: "); 
            scanf("%d", &item); 
            insertatfirst(&startnode, item);
            break;
            
            case 2:
            printf("Enter the information part: "); 
            scanf("%d", &item); 
            insertatlast(&startnode, item);
            break;

            case 3:
            printf("Enter the information part: "); 
            scanf("%d", &item);
            printf("Enter the position to insert after: ");
            scanf("%d",&position); 
            insertafteranyposition(&startnode, item, position); 
            break;

            case 4:
            deletefromfirst(&startnode);
            break; 

            case 5:
            deletefromlast(&startnode); 
            break;

            case 6:
            printf("Enter the position to delete: "); 
            scanf("%d", &position); 
            deletefromanyposition(&startnode, position); 
            break;

            case 7:
            display(&startnode); 
            break;

            case 8:
            exit(0);
            break;

            default:
            printf("Invalid Input\n");
        }
    }
}

void insertatfirst(struct doublylinkedlist **start, int x)
{
    struct doublylinkedlist *node;
    node=(struct doublylinkedlist *)malloc(sizeof(struct doublylinkedlist)); 
    node->info=x;
    if(*start==NULL)
    {
        node->prevlink=NULL; 
        node->nextlink=NULL;
        *start=node;
    }
    else
    {
        node->prevlink=NULL;
        node->nextlink=*start; 
        (*start)->prevlink=node;
        *start=node;
    }
}

void insertatlast(struct doublylinkedlist **start, int x)
{
    struct doublylinkedlist *node, *temp;
    node=(struct doublylinkedlist *)malloc(sizeof(struct doublylinkedlist)); 
    node->info=x;
    node->nextlink=NULL; 
    if(*start==NULL)
    {
        node->prevlink=NULL;
        *start=node;
    }
    else
    {
        temp=*start;
        while(temp->nextlink!=NULL) 
        temp=temp->nextlink;
        temp->nextlink=node;
        node->prevlink=temp;
    }
}

void insertafteranyposition(struct doublylinkedlist **start, int x, int pos)
{
    struct doublylinkedlist *node,*temp;
    node=(struct doublylinkedlist *)malloc(sizeof(struct doublylinkedlist)); 
    node->info=x;
    temp=*start; 
    for(int i=0;i<pos;i++)
    temp=temp->nextlink;
    temp->nextlink->prevlink=node; 
    node->nextlink=temp->nextlink;
    node->prevlink=temp; 
    temp->nextlink=node;
}

void deletefromfirst(struct doublylinkedlist **start)
{
    struct doublylinkedlist *temp; 
    if(*start == NULL)
    {
    printf("\n List is empty"); 
    return;
    }
    temp=*start;
    *start=(*start)->nextlink; 
    (*start)->prevlink=NULL; 
    free(temp);
}

void deletefromlast(struct doublylinkedlist **start) {
    struct doublylinkedlist *temp,*ptr; 
    if(*start==NULL)
    {
        printf("\n List is empty"); 
        return; 
    }
    else if((*start)->nextlink==NULL)
    {
        temp=*start;
        *start=NULL; 
        free(temp); 
    }
    else
    {
    ptr=*start; 
    temp=(*start)->nextlink;
    while(temp->nextlink!=NULL)
    {
        ptr=temp;
        temp=temp->nextlink;
    }
    ptr->nextlink=NULL; 
    free(temp); 
    }
}

void deletefromanyposition(struct doublylinkedlist **start,int pos)
{
    struct doublylinkedlist *temp, *ptr; 
    if(*start==NULL)
    {
        printf("\n List is empty"); 
        return;
    }
    else if((*start)->nextlink==NULL)
    {
        temp=*start;
        *start=NULL; 
        free(temp);
    }
    else
    {
        ptr=*start; 
        for(int i=0;i<pos;i++)
        {
        temp=ptr;
        ptr=ptr->nextlink;
        }
        ptr->nextlink->prevlink=temp;
        temp->nextlink=ptr->nextlink;
        free(ptr);
    }
}

void display(struct doublylinkedlist **start)
{
    struct doublylinkedlist *temp; 
    printf("The linked list elements are: ");
    for(temp=*start;temp!=NULL;temp=temp->nextlink)
    {
    printf("%d ",temp->info);
    }
    printf("\n");
}