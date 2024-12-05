//! Q3-> Write a C++ program to represent sparse matrix. Also, performs addition of this lower triangular matrix with another simple matrix.

#include <iostream>
using namespace std;

// struct sparse_mat {
//   int *row;
//   int *col;
//   int *ele;
// };

void read_sparse_mat(int *mat_ele, int *mat_row, int *mat_col, int n) {
  cout << "Enter the elements of sparse matrix along with its row index and column index :" << endl;
  for (int i = 0; i < n; i++) {
    cout << "Row no. : ";
    cin >> mat_row[i];
    cout << "Column no. : ";
    cin >> mat_col[i];
    cout << "Element no. : ";
    cin >> mat_ele[i];
  }
}
void print_sparse_mat(int *mat_ele, int *mat_row, int *mat_col, int n, int row, int col) {
  int k = 0;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (i == mat_row[k] && j == mat_col[k]) {
        cout << mat_ele[k++] << "  ";
      } else {
        cout << 0 << "  ";
      }
    }
    cout << endl;
  }
}
void readMatrix(int **arr, int r, int c) {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cout << "Enter the element of (" << i << "," << j << ") :";
      cin >> arr[i][j];
    }
  }
}
void printMatrix(int **arr, int r, int c) {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cout << arr[i][j] << "  ";
    }
    cout << endl;
  }
}
void add_sparse_and_simple_mat(int **sMat, int *mat_ele, int *mat_row, int *mat_col, int n, int row, int col) {
  int **sumMat;
  sumMat = new int *[row];
  for (int i = 0; i < row; i++)
    sumMat[i] = new int[col];

  int k = 0;

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (i == mat_row[k] && j == mat_col[k]) {
        sumMat[i][j] = sMat[i][j] + mat_ele[k];
        k++;
      } else {
        sumMat[i][j] = sMat[i][j];
      }
    }
  }

  cout << "Sum of sparse and simple Matrix :" << endl;
  printMatrix(sumMat, row, col);
  for (int i = 0; i < row; i++)
    delete[] sumMat[i];
  delete[] sumMat;
}

int main() {
  int row, col, n;
  cout << "Enter the number of rows: ";
  cin >> row;
  cout << "Enter the number of columns: ";
  cin >> col;
  cout << "No. of Element in sparse matrix :";
  cin >> n;

  int *sparse_mat_ele = new int[n];
  int *sparse_mat_row = new int[n];
  int *sparse_mat_col = new int[n];
  read_sparse_mat(sparse_mat_ele, sparse_mat_row, sparse_mat_col, n);

  int **sMat;
  sMat = new int *[row];
  for (int i = 0; i < row; i++)
    sMat[i] = new int[col];
  cout << "Enter the element of simple matrix :" << endl;
  readMatrix(sMat, row, col);

  cout << "Sparse Matrix :" << endl;
  print_sparse_mat(sparse_mat_ele, sparse_mat_row, sparse_mat_col, n, row, col);

  cout << "Simple Matrix :" << endl;
  printMatrix(sMat, row, col);

  add_sparse_and_simple_mat(sMat, sparse_mat_ele, sparse_mat_row, sparse_mat_col, n, row, col);

  for (int i = 0; i < row; i++)
    delete[] sMat[i];
  delete[] sMat;
  delete[] sparse_mat_ele;
  delete[] sparse_mat_row;
  delete[] sparse_mat_col;
  return 0;
}