#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_STACK_SIZE 100

typedef struct
    {
        int items[MAX_STACK_SIZE];
        int top;
    } Stack;

void initialize(Stack *s)
    {
        s->top = -1;
    }

int is_empty(Stack *s)
    {
        return s->top == -1;
    }

int is_full(Stack *s)
    {
        return s->top == MAX_STACK_SIZE - 1;
    }

void push(Stack *s, int item)
    {
        if (is_full(s))
        {
            printf("Stack overflow\n");
            exit(1);
        }
        s->items[++s->top] = item;
    }   

int pop(Stack *s)
    {
        if (is_empty(s))
            {
                printf("Stack underflow\n");
                exit(1);
            }
         return s->items[s->top--];
    }

int evaluate_postfix(char *expression)
    {
        Stack s;
        initialize(&s);

        for (int i = 0; expression[i] != '\0'; i++)
            {
                if (isdigit(expression[i]))
                {
                    int num = 0;
                    while (isdigit(expression[i]))
                        {
                            num = num * 10 + (expression[i] - '0');
                            i++;
                        }
                    push(&s, num);
                } else if (expression[i] != ' ')
                    {
                        int operand2 = pop(&s);
                        int operand1 = pop(&s);
                        switch (expression[i])
                            {
                                case '+':
                                push(&s, operand1 + operand2);
                                break;
                                case '-':
                                push(&s, operand1 - operand2);
                                break;
                                case '*':
                                push(&s, operand1 * operand2);
                                break;
                                case '/':
                                push(&s, operand1 / operand2);
                                break;
                                default:
                                printf("Invalid operator: %c\n", expression[i]);
                                exit(1);
                            }
                    }
            }

        return pop(&s);
    }

int evaluate_prefix(char *expression)
{
    Stack s;
    initialize(&s);

    int len = strlen(expression);

    for (int i = len - 1; i >= 0; i--)
    {
        if (isdigit(expression[i]))
        {
            int num = 0;
            int multiplier = 1;
            while (i >= 0 && isdigit(expression[i]))
            {
                num = num + (expression[i] - '0') * multiplier;
                multiplier *= 10;
                i--;
            }
            push(&s, num);
        } else if (expression[i] != ' ')
        {
            int operand1 = pop(&s);
            int operand2 = pop(&s);
            switch (expression[i])
            {
                case '+':
                    push(&s, operand1 + operand2);
                    break;
                case '-':
                    push(&s, operand1 - operand2);
                    break;
                case '*':
                    push(&s, operand1 * operand2);
                    break;
                case '/':
                    push(&s, operand1 / operand2);
                    break;
                default:
                    printf("Invalid operator: %c\n", expression[i]);
                    exit(1);
            }
        }
    }

    return pop(&s);
}

int main()
{
    char postfix_expression[] = "112 34 5 * +";
    char prefix_expression[] = "+ 112 * 34 5";

    int postfix_result = evaluate_postfix(postfix_expression);
    int prefix_result = evaluate_prefix(prefix_expression);

    printf("Postfix Result: %d\n", postfix_result);
    printf("Prefix Result: %d\n", prefix_result);

    return 0;
}