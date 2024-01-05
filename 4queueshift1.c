/*
Solution: (Always deleting 0th element strategy) Modify the dequeue operation, so that whenever an item is deleted, the entire queue is shifted to the beginning of the array.
*/
#include <stdio.h>
#include <stdlib.h>
#define size 10
struct queueversion11
{
    int item[size];
    int rear;
}q;
void enqueue(struct queueversion11 *q, int x);
void dequeue(struct queueversion11 *q);
void display(struct queueversion11 *q);
int main()
{
    q.rear = -1;
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
void enqueue(struct queueversion11 *q, int x)
{
    if(q->rear == size-1)
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
void dequeue(struct queueversion11 *q)
{
    if(q->rear == -1)
    {
        printf("The queue is empty\n");
        exit(0);
    }
    else
    {
        int zeroth = q->item[0];
        for(int i=0;i<q->rear;i++)
        {
            q->item[i] = q->item[i+1];
            q->rear--;
            printf("The dequeued item is: %d\n", zeroth);
        }
    }
}
void display(struct queueversion11 *q)
{
    printf("The queue elements are: ");
    for(int i=0;i<=q->rear;i++)
    {
        printf("%d ", q->item[i]);
    }
}