// Linked List Implementation
#include <stdio.h> 
#include <stdlib.h>
struct linkedlist
{
    int info;
    struct linkedlist *link;
};
void insertatfirst(struct linkedlist **,int);
void insertatlast(struct linkedlist **, int);
void insertatanypos(struct linkedlist **, int, int);
void deletefromfirst(struct linkedlist **);
void deletefromlast(struct linkedlist **);
void deletefromanypos(struct linkedlist **, int);
void display(struct linkedlist **);
// void reverse(struct linkedlist **);
int main() 
{
    struct linkedlist *startnode; 
    startnode = NULL;
    int ch, x, pos;
    printf("What do you want to do?");
    printf("1.Insert node at first\n"); 
    printf("2.Insert node at last\n"); 
    printf("3.Insert node at any position\n"); 
    printf("4.Delete node at first\n"); 
    printf("5.Delete node at last\n"); 
    printf("6.Delete node at any position\n"); 
    printf("7.Display the linked list\n"); 
    // printf("8.Display reverse of linked list\n"); 
    printf("9.Exit\n"); 
    while(ch!=9) 
    {
    printf("Enter your choice: "); 
    scanf("%d", &ch); 
    switch(ch) 
    {
        case 1:
        printf("Enter the information part: ");
        scanf("%d", &x); 
        insertatfirst(&startnode, x);
        break;

        case 2:
        printf("Enter the information part: ");
        scanf("%d", &x); 
        insertatlast(&startnode, x);
        break; 
        
        case 3:
        printf("Enter the information part: ");
        scanf("%d", &x);
        printf("Enter the position to insert after: ");
        scanf("%d", &pos);
        insertatanypos(&startnode,x,pos); 
        break;
        
        case 4:
        deletefromfirst(&startnode); 
        break;
        
        case 5:
        deletefromlast(&startnode); 
        break;
        
        case 6:
        printf("Enter the position to delete: ");
        scanf("%d", &pos);
        deletefromanypos(&startnode,pos);
        break;
        
        case 7:
        display(&startnode); 
        break;
        
        // case 8:
        // reverse(&startnode); 
        // break;
        
        case 9:
        exit(0);
        break;

        default:
        printf("Invalid Input\n");
        }
    }
}
void insertatfirst(struct linkedlist **start, int x)
{
    struct linkedlist *node;
    node=(struct linkedlist *) malloc (sizeof(struct linkedlist));
    node->info = x; 
    if(*start == NULL)
    {
        node->link = NULL;
    }
    else
    {
        node->link = *start;
    }
    *start = node;
    printf("The node is inserted at first successfully\n");
}

void deletefromfirst(struct linkedlist **start)
{
    struct linkedlist *temp;
    if(*start == NULL)
    {
    printf("The linked list is empty\n"); 
    exit(0);
    }
    temp = *start;
    *start = (*start)->link; 
    free(temp);
    printf("The node is deleted from first successfully\n");
}

void insertatlast(struct linkedlist **start, int x)
{
    struct linkedlist *node, *temp;
    node = (struct linkedlist *) malloc (sizeof(struct linkedlist));
    node->info = x; 
    node->link = NULL; 
    if(*start == NULL)
    {
        *start = node;
    }
    else
    {
        temp = *start;
        while(temp->link!=NULL) 
        {
            temp = temp->link;
            temp->link = node;
        }
    }
    printf("The node is inserted at last successfully\n");
}

void deletefromlast(struct linkedlist **start) 
{
    struct linkedlist *temp, *ptr; 
    if(*start == NULL) 
    {
        printf("The linked list is empty\n"); 
        exit(0);
    }
    else if((*start)->link == NULL)
    {
        temp = *start;
        *start = NULL; 
        free(temp); 
    }
    else
    {
        ptr = *start; 
        temp = (*start)->link;
        while(temp->link!=NULL)
        {
            ptr = temp; 
            temp = temp->link;
        }
        ptr->link = NULL; 
        free(temp); 
    }
}

void insertatanypos(struct linkedlist **start, int x, int pos)
{
    struct linkedlist *node, *temp;
    node=(struct linkedlist *)malloc(sizeof(struct linkedlist)); 
    node->info = x;
    temp = *start; 
    for(int i=0;i<pos;i++)
    {
        temp = temp->link; 
        node->link = temp->link;
        temp->link = node;
    }
}

void deletefromanypos(struct linkedlist **start, int pos) {
    struct linkedlist *temp, *ptr; 
    if(*start == NULL) 
    {
        printf("The linked list is empty\n"); 
        return; 
    }
    else
    {
        ptr = *start; 
        for(int i=0;i<pos;i++) 
        {
            temp = ptr; 
            ptr = ptr->link;
        }
        temp->link = ptr->link; 
        free(ptr); 
    }
}
void display(struct linkedlist **start) 
{
    struct linkedlist *temp;
    printf("The linked list elements are: "); 
    temp = *start;
    while(temp!=NULL)
    {
        printf("%d ", temp->info);
        temp = temp->link;
    }
    printf("\n");
}
// void reverse(struct linkedlist **)
// {

// }