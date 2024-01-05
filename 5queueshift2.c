#include <stdio.h>
#include <stdlib.h>
#define size 10
struct queueversion12
{
    int item[size];
    int rear, front;
}q;
void enqueue(struct queueversion12 *q, int x);
void dequeue(struct queueversion12 *q);
void display(struct queueversion12 *q);
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
void enqueue(struct queueversion12 *q, int x)
{
    if(q->rear == size-1 && q->front == 0)
    {
        printf("The queue is full\n");
        exit(0);
    }
    else if(q->rear == size-1 && q->front>0)
    {
        int zeroth = 0;
        for(int i=q->front;i<=q->rear;i++)
        {
            q->item[i-q->front] = q->item[q->front+zeroth];
            q->front = 0;
            q->rear = zeroth;
            q->item[q->rear] = x;
            zeroth++;
            printf("The item is enqueued successfully\n");

        }
    }
    else
    {
        q->item[++q->rear] = x;
        printf("The item is enqueued successfully\n");
    }
}
void dequeue(struct queueversion12 *q)
{
    if(q->rear == -1)
    {
        printf("The queue is empty\n");
        exit(0);
    }
    else
    {
        printf("The dequeued item is: %d", q->item[q->front++]);
    }
}
void display(struct queueversion12 *q)
{
    printf("The queue elements are: ");
    for(int i=q->front;i<=q->rear;i++)
    {
        printf("%d ", q->item[i]);
    }
}