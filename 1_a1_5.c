#include <stdio.h>

#define MAX_SIZE 100

struct SparseMatrixElement 
{
    int row;
    int col;
    int value;
};

void displaySparseMatrix(struct SparseMatrixElement matrix[], int size) 
{
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i < size; i++) 
    {
        printf("%d\t%d\t%d\n", matrix[i].row, matrix[i].col, matrix[i].value);
    }
}

int main() 
{
    int n;
    int count = 0;
    struct SparseMatrixElement sparseMatrix[MAX_SIZE];

    printf("Enter the order of the square matrix (n x n): ");
    scanf("%d", &n);

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            int element;
            scanf("%d", &element);

            if (element != 0) 
            {
                sparseMatrix[count].row = i;
                sparseMatrix[count].col = j;
                sparseMatrix[count].value = element;
                count++;
            }
        }
    }

    printf("\nSparse Matrix Representation:\n");
    displaySparseMatrix(sparseMatrix, count);

    return 0;
}
