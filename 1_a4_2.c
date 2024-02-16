#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef struct {
    int ltop;
    size_t rtop, size;
    int* elements;
} Dualstk;

Dualstk stackInit(size_t size) {
    Dualstk stk;
    stk.ltop = -1;
    stk.rtop = size;
    stk.size = size;
    stk.elements = (int* ) calloc(size , sizeof(int));
    return stk;
}

void pushStk(Dualstk* stk, int atLeft) {
    if (atLeft) {    
        if (stk->ltop + 1 == stk->rtop) {
            printf("\t Stack full from 1st end\n");
        } else {
            int item;
            printf("\tElement: "); scanf("%d", &item);
            stk->ltop += 1;
            stk->elements[stk->ltop] = item;
            printf("\t%d added to top1 successfully\n", item);
        }
    } else {
        if (stk->rtop - 1 == stk->ltop) {
            printf("\t Stack full from 2nd end\n");
        } else {
            int item;
            printf("\tElement: "); scanf("%d", &item);
            stk->rtop -= 1;
            stk->elements[stk->rtop] = item;
            printf("\t%d added to top2 successfully\n", item);
        }
    }
}

void popStk(Dualstk* stk, int atLeft) {
    if (atLeft){    
        if (stk->ltop == -1) {
            printf("\t Stack empty from 1st end\n");
        } else {
            printf("\t%d popped from ltop\n", stk->elements[stk->ltop]);
            stk->elements[stk->ltop] = 0;
            stk->ltop -= 1;
        }
    } else {
        if (stk->rtop == stk->size) {
            printf("\t Stack empty from 2nd end\n");
        } else {
            printf("\t%d popped from top2\n", stk->elements[stk->rtop]);
            stk->elements[stk->rtop] = 0;
            stk->rtop += 1;
        }
    }
}

void displayStk(Dualstk* stk) {
    printf("\t");
    for (int i = 0; i < stk->size; i ++) {
        if (i == stk->ltop) printf("%d ] ", stk->elements[i]);
        else if (i == stk->rtop) printf("[ %d |", stk->elements[i]);
        else (i > stk->ltop && i < stk->rtop) ? printf("_ | "):printf("%d | ", stk->elements[i]);
    }
    printf("\n");
}

int main() {
    size_t n;
    int choice = 100, item;
    printf("Enter dualStack size: "); scanf("%ld", &n);
    
    Dualstk stk = stackInit(n);

    printf("Stack operations:\n1. PUSHLEFT()\n2. POPLEFT()\n3. PUSHRIGHT()\n4. POPRIGHT()\n0. EXIT()\n\n");
    
    while (choice) {
        printf("Enter your choice: "); ; scanf("%d", &choice);
        switch (choice) {
            case 1:
                pushStk(&stk, 1);
                displayStk(&stk);
                break;
            case 2:
                popStk(&stk, 1);
                displayStk(&stk);
                break;
            case 3:
                pushStk(&stk, 0);
                displayStk(&stk);
                break;
            case 4:
                popStk(&stk, 0);
                displayStk(&stk);
                break;
            default:
                printf("\tInvalid Input\n");
        }
        printf("\n");
    }
    return 0;
}