#include <stdio.h>
#define MAX_ROWS 10
#define MAX_COLS 10
int sumOfRow(int matrix[MAX_ROWS][MAX_COLS], int col, int n){
    int sum = 0;
    for (int i = 0; i < col; i++){
        sum += matrix[n][i];
    }
    return sum;
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
    for (int i = 0; i < rows; i++){
        printf("Sum of row %d: %d\n", i+1, sumOfRow(matrix, cols, i));
    }
    // sum of all elements in the matrix
    int sum = 0;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            sum += matrix[i][j];
        }
    }
    printf("Sum of all elements in the matrix: %d\n", sum);

    return 0;
}