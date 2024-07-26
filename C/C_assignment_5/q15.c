#include <stdio.h>

void transposeMatrix(int mat[][100], int trans[][100], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            trans[j][i] = mat[i][j];
        }
    }
}

int main()
{
    int rows, cols;

    printf("Enter the number of rows : ");
    scanf("%d", &rows);
    printf("Enter the number of columns : ");
    scanf("%d", &cols);

    int mat[100][100], trans[100][100];

    printf("\nEnter elements of the matrix:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("Enter element at position (%d,%d): ", i + 1, j + 1);
            scanf("%d", &mat[i][j]);
        }
    }

    transposeMatrix(mat, trans, rows, cols);

    printf("\nOriginal Matrix:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    printf("\nTransposed Matrix:\n");
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            printf("%d ", trans[i][j]);
        }
        printf("\n");
    }

    return 0;
}
