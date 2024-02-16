#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int top;
    unsigned capacity;
    int *array;
};

struct Stack *createStack(unsigned capacity)
{
    struct Stack *stack = (struct Stack *) malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *) malloc(stack->capacity * sizeof(int));
    return stack;
}

int isFull(struct Stack *stack)
{
    return stack->top == stack->capacity - 1;
}

int size(struct Stack *stack)
{
    return stack->top + 1;
}

int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

void push(struct Stack *stack, int item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

int pop(struct Stack *stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}

int peek(struct Stack *stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top];
}

void sortedInsert(struct Stack *stack, int x)
{
    if (isEmpty(stack) || x >= peek(stack))
    {
        push(stack, x);
        return;
    }
    int temp = pop(stack);
    sortedInsert(stack, x);
    push(stack, temp);
}

struct Stack *sortStack(struct Stack *stack)
{
    if (isEmpty(stack) == 0)
    {
        int x = pop(stack);
        sortStack(stack);
        sortedInsert(stack, x);
    }
    return stack;
}

struct Stack *merge(struct Stack *a, struct Stack *b, struct Stack *c, int p, int q, int r)
{
    struct Stack *finalstack = createStack(p + q + r);
    while (!isEmpty(a))
        push(finalstack, pop(a));

    while (!isEmpty(b))
        push(finalstack, pop(b));

    while (!isEmpty(c))
        push(finalstack, pop(c));

    struct Stack *finalans = sortStack(finalstack);

    return finalans;
}

void printReverseStack(struct Stack *stack)
{
    if(isEmpty(stack))
    {
        return;
    }
    int x = pop(stack);
    printReverseStack(stack);
    printf("%d ",x);
    push(stack, x);
}

int main()
{
    printf("Enter no of elements of stack 1: \n");
    int p;
    scanf("%d", &p);
    struct Stack *stacka = createStack(p);
    printf("Enter the elements of stack 1: \n");
    for (int i = 0; i < p; i++)
    {
        int x;
        scanf("%d", &x);
        push(stacka, x);
    }
    printf("Enter no of elements of stack 2: \n");
    int q;
    struct Stack *stackb = createStack(q);
    scanf("%d", &q);
    printf("Enter the elements of stack 2: \n");
    for (int i = 0; i < q; i++)
    {
        int x;
        scanf("%d", &x);
        push(stackb, x);
    }
    printf("Enter no of elements of stack 3: \n");
    int r;
    scanf("%d", &r);
    struct Stack *stackc = createStack(r);
    printf("Enter the elements of stack 3: \n");
    for (int i = 0; i < r; i++)
    {
        int x;
        scanf("%d", &x);
        push(stackc, x);
    }

    struct Stack *finalstack = merge(stacka, stackb, stackc, p, q, r);
    printf("Content of final stack after merging and sorting: \n");
    printReverseStack(finalstack);
    return 0;
}