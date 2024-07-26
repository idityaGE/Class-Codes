#include <stdio.h>
#define MAX_ROWS 10
#define MAX_COLS 10
int smallestElement(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols){
    int min = matrix[0][0];
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            if (matrix[i][j] < min){
                min = matrix[i][j];
            }
        }
    }
    return min;
}
int postionOfElement(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols, int element){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            if (matrix[i][j] == element){
                return i*cols + j + 1;
            }
        }
    }
    return -1;
}
int main(){
    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    int matrix[MAX_ROWS][MAX_COLS];
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            printf("%d \t", matrix[i][j]);
        }
        printf("\n");
    }
    int min = smallestElement(matrix, rows, cols);
    printf("Smallest element in the matrix: %d\n", min);
    int pos = postionOfElement(matrix, rows, cols, min);
    printf("Position of the smallest element in the matrix: %d\n", pos);
}