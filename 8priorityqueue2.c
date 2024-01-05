// Descending Priority Queue
#include <stdio.h>
#include <stdlib.h>
#define size 10
struct priorityqueue
{
    int item[size];
    int rear, front;
    int priority[size];
}q;
void enqueue(struct priorityqueue *q, int x);
void dequeue(struct priorityqueue *q);
void display(struct priorityqueue *q);
int main()
{
    q.rear = size-1;
    q.front = size-1;
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
void enqueue(struct priorityqueue *q, int x)
{
    if((q->rear+1)%size == q->front)
    {
        printf("The queue is full\n");
        exit(0);
    }
    else
    {
        q->rear = (q->rear+1)%size;
        q->item[q->rear] = x;
        printf("The item is enqueued successfully\n");
        printf("Enter priority: ");
        scanf("%d", &q->priority[q->rear]);
    }
}
void dequeue(struct priorityqueue *q)
{
    int temp;
    if(q->rear == q->front)
    {
        printf("The queue is empty\n");
        exit(0);
    }
    {
        for(int i=(q->front+1)%size;i!=(q->rear)%size;i=(i+1)%size)
        {
            for(int j=(i+1)%size;j!=(q->rear+1)%size;j=(j+1)%size)
            {
                if(q->priority[i]<q->priority[j])
                {
                    temp = q->priority[i];
                    q->priority[i] = q->priority[j];
                    q->priority[j] = temp;
                }
            }
        }
        printf("The dequeued item is: %d", (q->item[(q->front+1)%size]));
        q->front = (q->front+1)%size;
    }
}
void display(struct priorityqueue *q)
{
    printf("The queue elements are: ");
    for(int i=(q->front+1)%size;i!=(q->rear+1)%size;i=(i+1)%size)
    {
        printf("%d with priority %d\t", q->item[i], q->priority[i]);
    }
}