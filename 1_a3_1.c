#include <stdio.h>
#include <stdlib.h>

int main()
{
    int row, col;
    printf("Enter the number of rows: ");
    scanf("%d", &row);
    printf("Enter the number of columns: ");
    scanf("%d", &col);

    int matrix[row][col];
    printf("Enter the matrix elements:\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &matrix[i][j]);
        } 
    }
printf("your entered matrix is  : \n");
for(int i=0;i<row;i++)
    {
         for(int j=0;j<col;j++)
        {
            printf("%d ",matrix[i][j]);
        }
printf("\n");
}
printf("reoresentation of spiral matrix-1: \n");
    
    int startRow = 0, endCol = col-1, startCol = 0,endRow=row-1;
 while(startRow<row)
 {
       if(startRow % 2==0 )
       {
            for (int idx = startCol; idx <= endCol; idx++)
            {
                printf("%d ", matrix[startRow][idx]);
            }
        }
        
            
        else if(startRow % 2==1)
        {
            for (int idx = endCol; idx >= startCol; idx--)
            {
                printf("%d ", matrix[startRow][idx]);
            }
        }
         startRow++;
 }
 printf("\n\n");
 
 printf("reoresentation of spiral matrix-2: \n");
  int total = row * col;
    int count = 0;
     startRow = 0, endCol = col - 1, endRow = row - 1, startCol = 0;

    while (count < total)
    {
        for (int idx = startCol; count < total && idx <= endCol; idx++)
        {
            printf("%d ", matrix[startRow][idx]);
            count++;
        }
        startRow++;

        
        for (int idx = startRow; count < total && idx <= endRow; idx++)
        {
            printf("%d ", matrix[idx][endCol]);
            count++;
        }
        endCol--;

        
        for (int idx = endCol; count < total && idx >= startCol; idx--)
        {
            printf("%d ", matrix[endRow][idx]);
            count++;
        }
        endRow--;

        for (int idx = endRow; count < total && idx >= startRow; idx--)
        {
            printf("%d ", matrix[idx][startCol]);
            count++;
        }
        startCol++;
    }

    return 0;
}