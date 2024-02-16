#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int top;
    int size;
    int* array;
};
 
struct Stack* createStack(int size)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->size= size;
    stack->top = -1;
    stack->array = (int*)malloc(stack->size* sizeof(int));
    return stack;
}
 
int isFull(struct Stack* stack)
{
    return stack->top == stack->size - 1;
}
 
int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}
 
//Add an item to stack. It increases top by 1
void push(struct Stack* stack, int item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
    //printf("%d pushed to stack\n", item);
}
 
//Remove an item from stack.  It decreases top by 1
int pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}
 
//Return the top from stack without removing it
int peek(struct Stack* stack)
{
    if (isEmpty(stack))
     return INT_MIN;
    return stack->array[stack->top];
}
 
struct Stack* DuplicateStack(struct Stack* stack , int n)
{
  int arr[n];
  int k = 0;
  int count = 0;
  while(isEmpty(stack) == 0)
  {
    arr[k] = pop(stack);
    k++;
  }
  for(int i = 0; i < n/2;i++)
  {
    int temp = arr[i];
    arr[i] = arr[n - i - 1];
    arr[n - i - 1] = temp;
  }
  for(int i = 0; i < n;i++)
  {
    int found = 0;
    for(int j=0;j<i;j++)
    {
      if(arr[j] == arr[i])
      found = 1;
    }
    if(found == 0)
    count++;
  }
  struct Stack* finalStack = createStack(count);
  for(int i = n-1;i>=0;i--)
  {
    int found = 0;
    for(int j = 0;j<i;j++)
    {
      if(arr[j] == arr[i])
      found = 1;
    }
    if(found == 0)
    push(finalStack , arr[i]);
  }
  for(int i = n-1;i>=0;i--)
  push(stack , arr[i]);
  return finalStack;
}

void printStack(struct Stack* stack)
{
  while(isEmpty(stack) == 0)
  printf("%d " , pop(stack));
}

int main()
{  
    printf("Enter number of elements: \n");
    int ele_count;
    scanf("%d" , &ele_count);
    printf("Enter elements: \n");
    struct Stack* stack = createStack(ele_count);
    for(int i = 0; i < ele_count;i++)
    {
      int x;
      scanf("%d" , &x);
      push(stack , x);
    }
    struct Stack* NewStack = DuplicateStack(stack , ele_count);
    printf("Content of new stack after removal of duplicate elements: \n");
    while(isEmpty(NewStack) == 0)
    {
      printf("%d " , pop(NewStack));
    }
  printf("\n");
  printf("Content of original stack: \n");
  while(isEmpty(stack) == 0)
  printf("%d " , pop(stack) );
  return 0;
}