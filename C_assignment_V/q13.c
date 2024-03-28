#include <stdio.h>

int areMatricesEqual(int mat1[100][100], int mat2[100][100], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (mat1[i][j] != mat2[i][j])
            {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    int rows, cols;

    printf("Enter the number of rows : ");
    scanf("%d", &rows);
    printf("Enter the number of columns : ");
    scanf("%d", &cols);

    int mat1[100][100], mat2[100][100];

    printf("Enter elements of first matrix:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("Enter element at position (%d,%d): ", i + 1, j + 1);
            scanf("%d", &mat1[i][j]);
        }
    }

    printf("\nEnter elements of second matrix:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("Enter element at position (%d,%d): ", i + 1, j + 1);
            scanf("%d", &mat2[i][j]);
        }
    }

    if (areMatricesEqual(mat1, mat2, rows, cols))
    {
        printf("\nMatrices are equal.\n");
    }
    else
    {
        printf("\nMatrices are not equal.\n");
    }

    return 0;
}
