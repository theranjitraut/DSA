// stack
// #include <stdio.h>
// #include <stdlib.h>
// #define size 10
// struct stack
// {
//     int item[size];
//     int top;
// }s;
// void push(struct stack *s, int x);
// void pop(struct stack *s);
// void display(struct stack *s);
// int main()
// {
//     s.top = -1;
//     int ch, x;
//     while(ch!=4)
//     {
//         printf("\nEnter 1 for push or 2 for pop or 3 for display or 4 for exit: ");
//         scanf("%d", &ch);
//         switch(ch)
//         {
//             case 1:
//             printf("Enter item to enqueue: ");
//             scanf("%d", &x);
//             push(&s, x);
//             break;

//             case 2:
//             pop(&s);
//             break;

//             case 3:
//             display(&s);
//             break;

//             case 4:
//             exit(0);
//             break;

//             default:
//             printf("Invalid Input\n");
//         }
//     }
// }
// void push(struct stack *s, int x)
// {
//     if(s->top == size-1)
//     {
//         printf("The stack is full\n");
//         exit(0);
//     }
//     else
//     {
//         s->item[++s->top] = x;
//         printf("The item is pushed successfully\n");
//     }
// }
// void pop(struct stack *s)
// {
//     if(s->top==-1)
//     {
//         printf("The stack is empty\n");
//         exit(0);
//     }
//     else
//     {
//         printf("The poped item is: %d", s->item[s->top--]);
//     }
// }
// void display(struct stack *s)
// {
//     printf("The stack elements are: ");
//     for(int i=s->top;i>=0;i--)
//     {
//         printf("%d ", s->item[i]);
//     }
// }

// queue
// #include <stdio.h>
// #include <stdlib.h>
// #define size 10
// struct queue
// {
//     int item[size];
//     int rear, front;
// }q;
// void enqueue(struct queue *q, int x);
// void dequeue(struct queue *q);
// void display(struct queue *q);
// int main()
// {
//     q.rear = -1;
//     q.front = 0;
//     int ch, x;
//     while(ch!=4)
//     {
//         printf("\nEnter 1 for enqueue or 2 for dequeue or 3 for display or 4 for exit: ");
//         scanf("%d", &ch);
//         switch(ch)
//         {
//             case 1:
//             printf("Enter item to enqueue: ");
//             scanf("%d", &x);
//             enqueue(&q, x);
//             break;

//             case 2:
//             dequeue(&q);
//             break;

//             case 3:
//             display(&q);
//             break;

//             case 4:
//             exit(0);
//             break;

//             default:
//             printf("Invalid Input\n");
//         }
//     }
// }
// void enqueue(struct queue *q, int x)
// {
//     if(q->rear == size-1)
//     {
//         printf("The queue is full\n");
//         exit(0);
//     }
//     else
//     {
//         q->item[++q->rear] = x;
//         printf("The item is queued successfully\n");
//     }
// }
// void dequeue(struct queue *q)
// {
//     if(q->rear<q->front)
//     {
//         printf("The queue is empty\n");
//         exit(0);
//     }
//     else
//     {
//         printf("The dequeued item is: %d", q->item[q->front++]);
//     }
// }
// void display(struct queue *q)
// {
//     printf("The queue elements are: ");
//     for(int i=q->front;i<=q->rear;i++)
//     {
//         printf("%d ", q->item[i]);
//     }
// }

// 
#include <stdio.h>
#include <stdlib.h>
#define size 10
struct queue
{
    int item[size];
    int rear, front;
}q;
void enqueue(struct queue *q, int x);
void dequeue(struct queue *q);
void display(struct queue *q);
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
void enqueue(struct queue *q, int x)
{
    if(q->rear == size-1)
    {
        printf("The queue is full\n");
        exit(0);
    }
    else
    {
        q->item[++q->rear] = x;
        printf("The item is queued successfully\n");
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
    printf("The queue elements are: ");
    for(int i=q->front;i<=q->rear;i++)
    {
        printf("%d ", q->item[i]);
    }
}

// queue by shifting each to 0th index after dequeuing
// queue by shifing each time to 0th index
#include <stdio.h>
#include <stdlib.h>
#define size 10
struct queue
{
    int item[size];
    int rear;
}q;
void enqueue(struct queue *q, int x);
void dequeue(struct queue *q);
void display(struct queue *q);
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
void enqueue(struct queue *q, int x)
{
    if(q->rear == size-1)
    {
        printf("The queue is full\n");
        exit(0);
    }
    else
    {
        q->item[++q->rear] = x;
        printf("The item is queued successfully\n");
    }
}
void dequeue(struct queue *q)
{
    if(q->rear == -1)
    {
        printf("The queue is empty\n");
        exit(0);
    }
    else
    {
        int zeroth = q->item[0];
        for(int i=0;i<=q->rear;i++)
        {
            q->item[i] = q->item[i+1];
            q->rear--;
            printf("The dequeued item is: %d\n", zeroth);
        }
    }
}
void display(struct queue *q)
{
    printf("The queue elements are: ");
    for(int i=0;i<=q->rear;i++)
    {
        printf("%d ", q->item[i]);
    }
}

// queue by shifting once in each enqueuing\#include <stdio.h>
#include <stdlib.h>
#define size 10
struct queue
{
    int item[size];
    int rear, front;
}q;
void enqueue(struct queue *q, int x);
void dequeue(struct queue *q);
void display(struct queue *q);
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
void enqueue(struct queue *q, int x)
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
void dequeue(struct queue *q)
{
    if(q->rear==-1)
    {
        printf("The queue is empty\n");
        exit(0);
    }
    else
    {
        printf("The dequeued item is: %d\n", q->item[q->front++]);
    }
}
void display(struct queue *q)
{
    printf("The queue elements are: ");
    for(int i=q->front;i<=q->rear;i++)
    {
        printf("%d ", q->item[i]);
    }
}

// circular queue
#include <stdio.h>
#include <stdlib.h>
#define size 10
struct circularqueue
{
    int item[size];
    int rear, front;
}q;
void enqueue(struct circularqueue *q, int x);
void dequeue(struct circularqueue *q);
void display(struct circularqueue *q);
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
void enqueue(struct circularqueue *q, int x)
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
    }
}
void dequeue(struct circularqueue *q)
{
    if(q->rear == q->front)
    {
        printf("The queue is empty\n");
        exit(0);
    }
    else
    {
        printf("The dequeued item is: %d\n", q->item[(q->front+1)%size]);
        q->front = (q->front+1)%size;
    }
}
void display(struct circularqueue *q)
{
    printf("The queue elements are: ");
    for(int i=(q->front+1)%size;i!=(q->rear+1)%size;i=(i+1)%size)
    {
        printf("%d ", q->item[i]);
    }
}

// priority queue

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
                if(q->priority[i]>q->priority[j])
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
