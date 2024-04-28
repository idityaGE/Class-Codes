#include <stdio.h>

int isIdentityMatrix(int n, int matrix[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i == j && matrix[i][j] != 1) || (i != j && matrix[i][j] != 0)) return 0;
        }
    }
    return 1;
}
int main() {
    int n;
    printf("Enter the number of rows and columns of square matrix: ");
    scanf("%d", &n);
    int matrix[n][n];
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);
    }
    if (isIdentityMatrix(n, matrix)) printf("The matrix is an identity matrix.\n");
    else printf("The matrix is not an identity matrix.\n");
}
