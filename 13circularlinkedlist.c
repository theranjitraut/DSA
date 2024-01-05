// Circular Linked List Implementation
#include <stdio.h> 
#include <stdlib.h>
struct circularlinkedlist
{
    int info;
    struct circularlinkedlist *link;
};
void insertatfirst(struct circularlinkedlist **, int); 
void insertatlast(struct circularlinkedlist **, int);
void insertafteranyposition(struct circularlinkedlist **, int, int); 
void deletefromfirst(struct circularlinkedlist **);
void deletefromlast(struct circularlinkedlist **);
void deletefromanyposition(struct circularlinkedlist **,int); 
void display(struct circularlinkedlist **);
int main() 
{
    struct circularlinkedlist *lastnode; 
    lastnode = NULL;
    int item, ch, position;
    printf("What do you want to do?\n"); 
    printf("1.Insert node at first\n"); 
    printf("2.Insert node at last\n"); 
    printf("3.Insert node after any position\n"); 
    printf("4.Delete node at first\n"); 
    printf("5.Delete node at last\n"); 
    printf("6.Delete node at any position\n"); 
    printf("7.Display the circular linked list\n");
    while(ch!=8) {
    printf("Enter your choice: "); 
    scanf("%d", &ch);
    switch(ch)
    {
        case 1:
        printf("Enter the information part: "); 
        scanf("%d", &item);
        insertatfirst(&lastnode, item); 
        break;

        case 2:
        printf("Enter the information part: "); 
        scanf("%d", &item);
        insertatlast(&lastnode, item); 
        break;

        case 3:
        printf("Enter the information part: "); 
        scanf("%d", &item);
        printf("Enter the position to insert after: "); 
        scanf("%d", &position); 
        insertafteranyposition(&lastnode,item,position);
        break;

        case 4:
        deletefromfirst(&lastnode); 
        break;

        case 5:
        deletefromlast(&lastnode); 
        break;

        case 6:
        printf("Enter the position to delete: "); 
        scanf("%d",&position); 
        deletefromanyposition(&lastnode,position); 
        break;

        case 7:
        display(&lastnode); 
        break;

        case 8:
        exit(0);
        break;

        default:
        printf("Invalid Input\n");
    }
}
}
void insertatfirst(struct circularlinkedlist **last, int x)
{
    struct circularlinkedlist *node;
    node = (struct circularlinkedlist *) malloc (sizeof(struct circularlinkedlist)); 
    node->info = x;
    if(*last == NULL)
    {
        *last = node;
        node->link = *last;
    }
    else
    {
        node->link = (*last)->link; 
        (*last)->link = node;
    }
}
void insertatlast(struct circularlinkedlist **last, int x)
    {
        struct circularlinkedlist *node, *temp;
        node=(struct circularlinkedlist *) malloc (sizeof(struct circularlinkedlist)); 
        node->info = x;
        node->link = NULL;
        if(*last == NULL)
        {
            *last = node;
            node->link = *last;
        }
        else
        {
            node->link = (*last)->link; 
            (*last)->link = node;
            *last = node;
        }
}
void insertafteranyposition(struct circularlinkedlist **last, int x, int pos)
{
    int i;
    struct circularlinkedlist *node,*temp;
    node = (struct circularlinkedlist *) malloc (sizeof(struct circularlinkedlist)); 
    node->info = x;
    temp = (*last)->link; 
    for(i=0;i<pos;i++)
    {
        temp = temp->link; 
        node->link = temp->link; 
        temp->link = node;
    }
}

void deletefromfirst(struct circularlinkedlist **last)
{
    struct circularlinkedlist *temp; 
    if(*last == NULL)
    {
        printf("The circular linkedlist is empty\n"); 
        return;
    }
    else if((*last)->link == *last)
    {
        temp = *last;
        *last = NULL; 
        free(temp);
    }
    else
    {
        temp = (*last)->link; 
        (*last)->link = temp->link; 
        free(temp);
    }
}

void deletefromlast(struct circularlinkedlist **last) 
{
    struct circularlinkedlist *temp,*ptr; 
    if(*last==NULL) 
    {
        printf("The circular linkedilst is empty\n"); 
        return; 
    }
    else if((*last)->link==*last)
    {
        temp=*last;
        *last=NULL; 
        free(temp); 
    }
    else
    {
        temp=*last; 
        ptr=(*last)->link; 
        while(ptr->link!=*last) 
        {
            ptr=ptr->link;
            ptr->link=(*last)->link;
            *last=ptr; 
            free(temp); 
        }
    }
}
void deletefromanyposition(struct circularlinkedlist **last,int pos) 
{
    struct circularlinkedlist *temp,*ptr; 
    int i;
    ptr=(*last)->link; 
    for(i=0;i<pos;i++) 
    {
        temp=ptr; 
        ptr=ptr->link;
    }
    temp->link=ptr->link; 
    free(ptr); 
}

void display(struct circularlinkedlist **last) 
{
    struct circularlinkedlist *temp; 
    if(*last==NULL) 
    {
        printf("The ciruclar list is empty\n"); 
        return; 
    }
    printf("The linked list elements are: "); 
    for(temp=(*last)->link;temp!=*last;temp=temp->link)
    {
        printf("%d ",temp->info);
    }
    printf("%d\n",(*last)->info);
}