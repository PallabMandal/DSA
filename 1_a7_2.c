#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;
void insertSortArr(int num, int *sorted, int len)
{
    int i = len;
    while (i >= 0)
    {
        if (num < sorted[i])
        {
            sorted[i + 1] = sorted[i];
        }
        else
            break;
        i--;
    }
    sorted[i + 1] = num;
}
node *insertSortLL(int num, node *head)
{
    if (head->data == 0)
    {
        head->data = num;
        head->next = NULL;
        return head;
    }
    node *new = malloc(sizeof(node));
    new->data = num;
    new->next = NULL;
    if (num <= head->data)
    {
        new->next = head;
        head = new;
        return head;
    }
    node *temp = head;

    while (temp->next != NULL)
    {
        if (num <= temp->next->data)
        {

            new->next = temp->next;
            break;
        }
        temp = temp->next;
    }
    temp->next = new;
    return head;
}
int displayLL(node *head)
{
    node *temp = head;
    while (temp->next != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}
int main(int argc, char *argv[5])
{
    if (argc > 2)
    {
        printf("Error: More than 1 cmd line args passed.Exiting...");
        exit(0);
    }
    int n = atoi(argv[1]);

    int num;
    int ch;
    printf("1. Array implementation\n2. Linked List implementation\nEnter your choice: ");
    scanf("%d", &ch);
    float tavg, time_ms;
    switch (ch)
    {
    case 1:
    {
        int sorted[10000];
        tavg = 0;
        for (int i = 1; i <= 6; i++)
        {
            time_ms = 0;
            printf("\nRun - %d:\n", i);

            srand(clock()); 
            for (int j = 1; j <= n; j++)
            {
                num = rand() % 9999 + 1;

                clock_t t = clock();
                insertSortArr(num, sorted, j - 2);
                t = clock() - t;
                time_ms += ((double)t) / CLOCKS_PER_SEC * 1000;
            }
            printf("Sorted list:\n");
            for (int k = 0; k < n-1; k++)
                printf("%d -> ", sorted[k]);
            printf("%d", sorted[n-1]);
            printf("\n");
            fprintf(stderr, "Time taken: %f ms.\t", time_ms);
            tavg += time_ms;
            printf("\n");
        }
        printf("\nAverage time taken for N = %d: %f ms.\n", n, tavg / 6.0);
        break;
    }

    case 2:
        tavg = 0;

        for (int i = 1; i <= 6; i++) 
        {
            node *head = malloc(sizeof(node)); 
            head->data = 0;
            head->next = NULL;

            time_ms = 0;
            printf("\nRun - %d:\n", i);

            srand(clock());
            for (int j = 1; j <= n; j++)
            {
                num = rand() % 9999 + 1;

                clock_t t = clock();
                head = insertSortLL(num, head);
                t = clock() - t;
                time_ms += ((double)t) / CLOCKS_PER_SEC * 1000;
            }
            printf("Sorted list:\n");
            displayLL(head);
            fprintf(stderr, "Time taken: %f ms.\t", time_ms);
            tavg += time_ms;
            printf("\n");
        }
        printf("\nAverage time taken for N = %d: %f ms.\n", n, tavg / 6.0);
        break;

    default:
        printf("Wrong choice entered. Exiting...\n");
    }
    return 0;
}