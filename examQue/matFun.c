#include <stdio.h>

void readMat(int mat[][50], int rows, int cols)
{
  printf("Enter elements of the matrix:\n");
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      printf("Enter element at position (%d,%d): ", i + 1, j + 1);
      scanf("%d", &mat[i][j]);
    }
  }
}

void printMat(int mat[][50], int rows, int cols)
{
  printf("Matrix:\n");
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      printf("%d\t", mat[i][j]);
    }
    printf("\n");
  }
}