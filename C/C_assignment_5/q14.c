#include <stdio.h>

void matrixMultiplication(int mat1[][100], int mat2[][100], int result[][100], int rows1, int cols1, int cols2)
{
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols2; j++)
        {
            result[i][j] = 0;
        }
    }

    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols2; j++)
        {
            for (int k = 0; k < cols1; k++)
            {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main()
{
    int rows1, cols1, rows2, cols2;

    printf("Enter the number of rows in first Matrix : ");
    scanf("%d", &rows1);
    printf("Enter the number of columns in first Matrix : ");
    scanf("%d", &cols1);

    printf("Enter the number of rows in second Matrix : ");
    scanf("%d", &rows2);
    printf("Enter the number of columns in second Matrix : ");
    scanf("%d", &cols2);

    if (cols1 != rows2)
    {
        printf("Matrix multiplication is not possible because the number of columns in the first matrix is not equal to the number of rows in the second matrix.\n");
        return 0;
    }

    int mat1[100][100], mat2[100][100], result[100][100];

    printf("\nEnter elements of first matrix:\n");
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols1; j++)
        {
            printf("Enter element at position (%d,%d): ", i + 1, j + 1);
            scanf("%d", &mat1[i][j]);
        }
    }

    printf("\nEnter elements of second matrix:\n");
    for (int i = 0; i < rows2; i++)
    {
        for (int j = 0; j < cols2; j++)
        {
            printf("Enter element at position (%d,%d): ", i + 1, j + 1);
            scanf("%d", &mat2[i][j]);
        }
    }

    matrixMultiplication(mat1, mat2, result, rows1, cols1, cols2);

    printf("\nResult of matrix multiplication:\n");
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols2; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
