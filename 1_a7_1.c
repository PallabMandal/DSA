#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item {
 char value[100];
};

struct Queue {
    struct item* items;
    unsigned capacity;
    int front;
    int rear;
};

struct Queue* createQueue(unsigned capacity) {
    struct Queue* q= (struct Queue*)malloc(sizeof(struct Queue));
    q->capacity= capacity;
    q->front= 0;
    q->rear= -1;
    q->items= (struct item*)malloc(capacity*sizeof(struct item));
    return q;
}

int isFull(struct Queue* q) {
    return q->rear == q->capacity - 1;
}

int isEmpty(struct Queue* q) {
    return q->front > q->rear;
}

void enqueue(struct Queue* q, struct item i) {
    if (isFull(q)) {
        printf("Queue is full. Value not inserted.");
        return;
    }

    int pos;
    for(pos= q->front; pos<=q->rear; pos++)
        if(strcmp(i.value, q->items[pos].value) < 0) {
            break;
        }
    q->rear++;

    for(int x= q->rear; x>pos; x--)
        q->items[x]= q->items[x-1];

    q->items[pos]= i;
}

void fillQueue(struct Queue* q) {
    printf("Enter elements for queue in any order: \n");
    struct item input;
    for(int i=0; i<q->capacity; i++) {
        fflush(stdin);
        scanf("%s", input.value);
        enqueue(q, input);
    }
}

struct item extractMin(struct Queue* q) {
    if(isEmpty(q)) {
        printf("Queue is empty.");
        struct item x;
        return x;
    }
    else
        return q->items[q->front++];
}

struct Queue* merge(struct Queue* q1, struct Queue* q2) {
    struct Queue* res= createQueue(q1->capacity+q2->capacity);
    for(int i= q1->front; i<=q1->rear; i++) {
        enqueue(res, q1->items[i]);
    }
    for(int i= q2->front; i<=q2->rear; i++) {
        enqueue(res, q2->items[i]);
    }
    return res;
}

void display(struct Queue* q) {
    if(isEmpty(q)){
        printf("Queue is empty.");
    }
    else {
        printf("\nQueue is:\n");
        for(int i= q->front; i<=q->rear; i++)
            printf("| %s |", q->items[i].value);
        printf("\n");
    }
}

int main() {
    int sz;
    printf("Enter size of Queue: ");
    scanf("%d", &sz);
    struct Queue* q1= createQueue(sz);
    fillQueue(q1);
    printf("\nQueue 1:");
    display(q1);

    struct item rem= extractMin(q1);
    printf("Queue 1 after removing 1 element with highest priority:");
    display(q1);

    printf("Enter size of second Queue: ");
    scanf("%d", &sz);
    struct Queue* q2= createQueue(sz);
    fillQueue(q2);
    printf("\nQueue 2:");
    display(q2);

    struct Queue* res= merge(q1, q2);
    printf("\nMerged result:\n");
    display(res);

    return 0;
}
	

