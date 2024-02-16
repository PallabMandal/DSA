#define SIZE 5
#include <stdio.h>
typedef struct
{
    int arr[SIZE];
    int top;
} stack;

void push(int, stack *);
int pop(stack *);
void display(stack);
int main()
{
    int ch;
    int ele;
    printf("Stack Implementation\n");
    stack stk;
    stk.top = -1;
    do
    {
        printf("\n1. Push element\n2. Pop element\n3. Display Stack\n4. Exit\n");
        printf("Enter your choice as integer : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Element to push : ");
            scanf("%d", &ele);
            push(ele, &stk);
            display(stk);
            break;
        case 2:
            ele = pop(&stk);
            if (ele != -99999)
                printf("Popped element : %d.", ele);
            break;
        case 3:
            display(stk);
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Wrong choice.Enter value from 1 to 4\n");
        }

    } while (ch != 4);
}
void push(int n, stack *stk)
{
    if (stk->top >= SIZE - 1)
    {
        printf("Stack Overflow.\n");
        return;
    }
    stk->top++;
    stk->arr[stk->top] = n;
}
int pop(stack *stk)
{
    if (stk->top <= -1)
    {
        printf("Stack Underflow.\n");
        return -99999;
    }
	
    return stk->arr[stk->top--];
}
void display(stack stk)
{
    int i;
    printf("Stack :\n");
    if (stk.top == -1)
    {
        printf("Stack empty\n");
        return;
    }
    for (i = stk.top; i >= 0; i--)
        printf("%d\n", stk.arr[i]);
}
