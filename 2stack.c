#include <stdio.h>
#include <stdlib.h>
#define size 5
struct stack
{
    int item[size];
    int top;
};
void push(struct stack *s, int x)
{
    if(s->top == size-1)
    {
        printf("Stackoverflow\n");
        exit(0);
    }
    else
    {
        s->item[++(s->top)] = x;
        printf("The item is pushed successfully\n");
    }
}
void pop(struct stack *s)
{
    if(s->top==-1)
    {
        printf("Stackunderflow\n");
        exit(0);
    }
    else
    {
        printf("The deleted item is %d\n", s->item[(s->top--)]);
    }
}
void display(struct stack *s)
{
    printf("The stack elements are: ");
    for(int i=s->top;i>=0;i--)
    {
        printf("%d ", s->item[i]);
    }
    printf("\n");
}
int main()
{
    struct stack s;
    s.top = -1;
    int ch, x;
    while(ch!=4)
    {
        printf("\nEnter 1 for push or 2 for pop or 3 for display or 4 for exit: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
            printf("Enter data to insert: ");
            scanf("%d", &x);
            push(&s, x);
            break;

            case 2:
            pop(&s);
            break;

            case 3:
            display(&s);
            break;

            case 4:
            exit(0);

            default:
            printf("Error 404");
        }
    }
}