#include <stdio.h>
#include <stdlib.h>
#define size 10
struct queue
{
    int item[size];
    int rear, front;
}q;
void enqueue(struct queue *q, int x)
{
    if(q->rear==size-1)
    {
        printf("The queue is full\n");
        exit(0);
    }
    else
    {
        q->item[++q->rear] = x;
        printf("The item is enqueued successfully\n");
    }
}
void dequeue(struct queue *q)
{
    if(q->rear<q->front)
    {
        printf("The queue is empty\n");
        exit(0);
    }
    else
    {
        printf("The dequeued item is: %d", q->item[q->front++]);
    }
}
void display(struct queue *q)
{
    printf("The queue items are: ");
    for(int i=q->front;i<=q->rear;i++)
    {
        printf("%d ", q->item[i]);
    }
}
int main()
{
    q.rear = -1;
    q.front = 0;
    int ch, x;
    while(ch!=4)
    {
        printf("\nEnter 1 for enqueue or 2 for dequeue or 3 for display or 4 for exit: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
            printf("Enter item to enqueue: ");
            scanf("%d", &x);
            enqueue(&q, x);
            break;

            case 2:
            dequeue(&q);
            break;

            case 3:
            display(&q);
            break;

            case 4:
            exit(0);
            break;

            default:
            printf("Invalid Input\n");
        }

    }
}