#include <iostream>
using namespace std;

void input_Diagonal_matrix(int *arr, int r) {
  for (int i = 0; i < r; i++) {
    cout << "Enter the element of (" << i << "," << i << ") :";
    cin >> arr[i];
  }
}

void display_Diagonal_matrix(int *arr, int r) {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < r; j++) {
      if (i == j) {
        cout << 1 << "  ";
      } else {
        cout << 0 << "  ";
      }
    }
    cout << endl;
  }
}

void read_matrix(int **arr, int r) {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < r; j++) {
      cout << "Enter the element of (" << i << "," << j << ") :";
      cin >> arr[i][j];
    }
  }
}

void display_matrix(int **arr, int r) {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < r; j++) {
      cout << arr[i][j] << "  ";
    }
    cout << endl;
  }
}

void add_matrix(int *dArr, int **sArr, int r) {
  int **sumArr;
  sumArr = new int *[r];
  for (int i = 0; i < r; i++)
    sumArr[i] = new int[r];

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < r; j++) {
      if (i == j)
        sumArr[i][j] = sArr[i][j] + dArr[i];
      else
        sumArr[i][j] = sArr[i][j];
    }
  }
  cout << "Sum of Diagonal and Simple Matrix : " << endl;
  display_matrix(sumArr, r);
}

int main() {
  int r;
  cout << "Enter the number of rows and columns (square matrix) : ";
  cin >> r;
  int *dArr = new int[r];
  cout << "Input diagonal matrix : " << endl;
  input_Diagonal_matrix(dArr, r);

  int **sArr;
  sArr = new int *[r];
  for (int i = 0; i < r; i++)
    sArr[i] = new int[r];
  cout << "Input simple matrix : " << endl;
  read_matrix(sArr, r);

  cout << "Diagonal Matrix : " << endl;
  display_Diagonal_matrix(dArr, r);
  cout << "Simple Matrix :" << endl;
  display_matrix(sArr, r);

  add_matrix(dArr, sArr, r);
  return 0;
}