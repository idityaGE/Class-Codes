#include <stdio.h>


void displayDiagonal(int matrix[][100], int ROWS, int COLS)
{
    printf("Diagonal elements of the matrix:\n");
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (i == j)
            {
                printf("%d ", matrix[i][j]);
            }
        }
    }
    printf("\n");
}

int main()
{
    int rows, cols;

    printf("Enter the number of rows : ");
    scanf("%d", &rows);
    printf("Enter the number of columns : ");
    scanf("%d", &cols);

    if (rows != cols)
    {
        printf("Diagonal elements can only be displayed for a square matrix.\n");
        return 0;
    }

    int mat[100][100];

    printf("\nEnter elements of first matrix:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("Enter element at position (%d,%d): ", i + 1, j + 1);
            scanf("%d", &mat[i][j]);
        }
    }

    displayDiagonal(mat, rows, cols);

    return 0;
}
