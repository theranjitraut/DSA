// Linked List Implementation of Queue
#include <stdio.h>
#include <stdlib.h>
struct linkedlistqueue
{
    int info;
    struct linkedlistqueue *link;
};
void enqueue(struct linkedlistqueue **rear, struct linkedlistqueue **front, int x);
void dequeue(struct linkedlistqueue **rear, struct linkedlistqueue **front);
void display(struct linkedlistqueue **front);
int main()
{
    struct linkedlistqueue *rear, *front;
    rear = NULL;
    front = NULL;
    int ch, x;
        while(ch!=4)
    {
        printf("Enter 1 for enqueue or 2 for dequeue or 3 for display or 4 for exit: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
            printf("Enter item to enqueue: ");
            scanf("%d", &x);
            enqueue(&rear, &front, x);
            break;

            case 2:
            dequeue(&rear, &front);
            break;

            case 3:
            display(&front);
            break;

            case 4:
            exit(0);
            break;

            default:
            printf("Invalid Input\n");
        }
    }
}
void enqueue(struct linkedlistqueue **rear, struct linkedlistqueue **front, int x)
{
    struct linkedlistqueue *node;
    node=(struct linkedlistqueue *)malloc(sizeof(struct linkedlistqueue));
    node->info = x;
    node->link = NULL;
    if(*rear == NULL)
    {
        *front = node;
        *rear = node;
    }
    else
    {
        (*rear)->link = node;
        *rear = (*rear)->link;
    }
}

void dequeue(struct linkedlistqueue **rear, struct linkedlistqueue **front)
{
    int item;
    struct linkedlistqueue *temp;
    if(*front == NULL)
    {
        printf("The queue is empty\n");
        exit(0);
    }
    else
    {
        // it tf ff ft
        item = temp->info;
        temp = *front;
        *front = (*front)->link;
        if(*front == NULL)
        {
            *rear = NULL;
            free(temp);
            printf("The dequeued item is: %d\n", item);
        }
    }
}

void display(struct linkedlistqueue **front)
{
    struct linkedlistqueue *temp;
    if(*front == NULL)
    {
        printf("The queue is empty\n");
        exit(0);
    }
    else
    {
        printf("The queue elements are: ");
        temp = *front;
        while(temp!=NULL)
        {
            printf("%d ", temp->info);
            temp = temp->link;
        }
    }
}