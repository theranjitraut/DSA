// Linked List Implementation of Stack
#include <stdio.h>
#include <stdlib.h>
struct linkedliststack
{
    int info;
    struct linkedliststack *link;
};
void push(struct linkedliststack **top, int x);
void pop(struct linkedliststack **top);
void display(struct linkedliststack **top);
int main()
{
    struct linkedliststack *top;
    top = NULL;
    int ch, x;
        while(ch!=4)
    {
        printf("\nEnter 1 for push or 2 for pop or 3 for display or 4 for exit: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
            printf("Enter item to enqueue: ");
            scanf("%d", &x);
            push(&top, x);
            break;

            case 2:
            pop(&top);
            break;

            case 3:
            display(&top);
            break;

            case 4:
            exit(0);
            break;

            default:
            printf("Invalid Input\n");
        }
    }
}
void push(struct linkedliststack **top, int x)
{
    struct linkedliststack *node;
    node = (struct linkedliststack*) malloc (sizeof(struct linkedliststack));
    node->info = x;
    node->link = *top;
    *top = node;
}
void pop(struct linkedliststack **top)
{
    int item;
    struct linkedliststack *temp;
    if(*top == NULL)
    {
        printf("The linkedlist stack is empty\n");
        exit(0);
    }
    else
    {
        // it tt tt ft
        item = (*top)->info;
        temp = *top;
        *top = (*top)->link;
        free(temp);
        printf("The poped item is: %d", item);
    }
}
void display(struct linkedliststack **top)
{
    struct linkedliststack *temp;
    if(*top == NULL)
    {
        printf("The linkedlist stack is empty");
        exit(0);
    }
    else
    {
        printf("The stack elements are: ");
        temp = *top;
        while(temp!=NULL)
        {
        printf("%d ", temp->info);
        temp = temp->link;
        }
    }
}