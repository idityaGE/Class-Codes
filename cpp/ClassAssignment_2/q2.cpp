//! Q2-> Write a C++ program to store lower triangular matrix. Also, performs addition of this lower triangular matrix with another simple matrix. [Assume only square matrix for this]

#include <iostream>
using namespace std;

void print_lower_diagonal_matrix(int *mat, int r) {
  int k = 0;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j <= i; j++) {
      cout << mat[k++] << "  ";
    }
    for (int j = 0; j < r - i - 1; j++) {
      cout << 0 << "  ";
    }
    cout << endl;
  }
}
void input_lower_diagonal_matrix(int *mat, int n) {
  for (int i = 0; i < n; i++) {
    cout << "Enter the element of lower_diagonal_matrix :";
    cin >> mat[i];
  }
}

void read_matrix(int **mat, int r) {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < r; j++) {
      cout << "Enter the element of (" << i << "," << j << ") :";
      cin >> mat[i][j];
    }
  }
}

void display_matrix(int **mat, int r) {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < r; j++) {
      cout << mat[i][j] << "  ";
    }
    cout << endl;
  }
}

void add_matrix(int *dMat, int **sMat, int r) {
  int **sumMat;
  sumMat = new int *[r];
  for (int i = 0; i < r; i++)
    sumMat[i] = new int[r];

  int l = 0;

  for (int i = 0; i < r; i++) {
    for (int j = 0; j <= i; j++) {
      sumMat[i][j] = sMat[i][j] + dMat[l++];
    }
    for (int k = i + 1; k < r; k++) {
      sumMat[i][k] = sMat[i][k];
    }
  }
  cout << "Sum of Lower Diagonal and Simple Matrix : " << endl;
  display_matrix(sumMat, r);
}

int main() {
  int r;
  cout << "Enter the number of rows and columns (square matrix) : ";
  cin >> r;
  int n = r * (r + 1) / 2;
  int *ld_mat = new int[n];
  input_lower_diagonal_matrix(ld_mat, n);

  int **sMat;
  sMat = new int *[r];
  for (int i = 0; i < r; i++)
    sMat[i] = new int[r];
  cout << "Input simple matrix : " << endl;
  read_matrix(sMat, r);

  cout << "Lower Diagonal Matrix : " << endl;
  print_lower_diagonal_matrix(ld_mat, r);

  cout << "Simple Matrix : " << endl;
  display_matrix(sMat, r);

  add_matrix(ld_mat, sMat, r);

  return 0;
}