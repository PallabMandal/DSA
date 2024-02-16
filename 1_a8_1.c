#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *right, *left;
};

struct Queue
{
    int front, rear;
    int size;
    struct Node **array;
};

struct Node *newNode(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

struct Queue *createQueue(int size)
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->front = queue->rear = -1;
    queue->size = size;
    queue->array = (struct Node **)malloc(queue->size * sizeof(struct Node *));
    int i;
    for (i = 0; i < size; ++i)
        queue->array[i] = NULL;
    return queue;
}

int isEmpty(struct Queue *queue)
{
    return queue->front == -1;
}

int isFull(struct Queue *queue)
{
    return queue->rear == queue->size - 1;
}

int hasOnlyOneItem(struct Queue *queue)
{
    return queue->front == queue->rear;
}

void Enqueue(struct Node *root, struct Queue *queue)
{
    if (isFull(queue))
        return;
    queue->array[++queue->rear] = root;
    if (isEmpty(queue))
        ++queue->front;
}

struct Node *Dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
        return NULL;
    struct Node *temp = queue->array[queue->front];
    if (hasOnlyOneItem(queue))
        queue->front = queue->rear = -1;
    else
        ++queue->front;
    return temp;
}

struct Node *getFront(struct Queue *queue)
{
    return queue->array[queue->front];
}

int hasBothChild(struct Node *temp)
{
    return temp && temp->left && temp->right;
}

void insert(struct Node **root, int data, struct Queue *queue)
{
    struct Node *temp = newNode(data);
    if (!*root)
        *root = temp;
    else
    {
        struct Node *front = getFront(queue);
        if (!front->left)
            front->left = temp;
        else if (!front->right)
            front->right = temp;
        if (hasBothChild(front))
            Dequeue(queue);
    }
    Enqueue(temp, queue);
}

void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(struct Node *node)
{
    if (node != NULL)
    {
        postorder(node->left);
        postorder(node->right);
        printf("%d ", node->data);
    }
}

void preorder(struct Node *node)
{
    if (node != NULL)
    {
        printf("%d ", node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

int main()
{
    int n, temp;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    struct Node *root = NULL;
    struct Queue *queue = createQueue(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        insert(&root, temp, queue);
    }
    printf("\nInorder Traversal\n");
    inorder(root);
    printf("\nPreorder Traversal\n");
    preorder(root);
    printf("\nPostorder Traversal\n");
    postorder(root);
    return 0;
}