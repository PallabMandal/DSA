#include <stdio.h>
#include <stdlib.h>

// Function of the Tic-Tac-Toe board
void displayBoard(char board[3][3])
{
    printf("Current Board:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %c ", board[i][j]);
            if (j < 2)
            {
                printf("|");
            }
        }
        printf("\n");
        if (i < 2)
        {
            printf("---|---|---\n");
        }
    }
    printf("\n");
}

// Function to check if a player has won
int checkWin(char board[3][3], char player)
{
    for (int i = 0; i < 3; i++)
    {
        if ((board[0][i] == player && board[1][i] == player && board[2][i] == player) ||
            (board[i][0] == player && board[i][1] == player && board[i][2] == player))
            {
                return 1;
            }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        {
            return 1;
        }
return 0;
}

int main()
{
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int currentPlayer = 1; // 1 for user, -1 for machine
    int moves = 0;

    while (moves < 9)
    {
        displayBoard(board);
        int row, col;
        
        if (currentPlayer == 1)
        {
            printf("User's turn. Enter row and column (1-3) separated by space: ");
            scanf("%d %d", &row, &col);
            row--;
            col--;
        } else
        {
            // Machine's turn (random move)
            do
            {
                row = rand() % 3;
                col = rand() % 3;
            } while (board[row][col] == 'X' || board[row][col] == 'O');
            printf("Machine's turn.\n");
        }
        
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] != 'X' && board[row][col] != 'O')
        {
            if (currentPlayer == 1)
            {
                board[row][col] = 'X';
            } else
            {
                board[row][col] = 'O';
            }
            moves++;
            if (checkWin(board, currentPlayer == 1 ? 'X' : 'O'))
            {
                displayBoard(board);
                printf(currentPlayer == 1 ? "User wins!\n" : "Machine wins!\n");
                break;
            }
            currentPlayer *= -1;
        } else
        {
            printf("Invalid move. Try again.\n");
        }
    }
    if (checkWin(board, 'X') == 0 && checkWin(board, 'O') == 0) {
        displayBoard(board);
        printf("It's a draw!\n");
    }

    return 0;
}
