#include <stdio.h>

#define MAX_ROWS 10
#define MAX_COLS 10

void interchangeRows(int matrix[MAX_ROWS][MAX_COLS], int row1, int row2, int cols) {
    for (int i = 0; i < cols; i++) {
        int temp = matrix[row1][i];
        matrix[row1][i] = matrix[row2][i];
        matrix[row2][i] = temp;
    }
}
void displayMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d \t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    int matrix[MAX_ROWS][MAX_COLS];
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("Matrix:\n");
    displayMatrix(matrix, rows, cols);
    int row1, row2;
    printf("Enter the indices of the rows to interchange (0th indexing): ");
    scanf("%d %d", &row1, &row2);
    if (row1 >= 0 && row1 < rows && row2 >= 0 && row2 < rows) {
        interchangeRows(matrix, row1, row2, cols);
        printf("Matrix after interchanging rows %d and %d:\n", row1, row2);
        displayMatrix(matrix, rows, cols);
    } else {
        printf("Invalid row indices.\n");
    }
    return 0;
}
