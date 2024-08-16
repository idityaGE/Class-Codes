//! Q2 -> Design a data structure in C++ to represent the sparse matrix using linked list. Also write functions to display and add two sparse matrices.

#include <iostream>
using namespace std;

struct NODE {
  int ele, row, col;
  NODE *next;
};

NODE *read_sparse_mat(NODE *p, int n) {
  for (int i = 0; i < n; i++) {
    int ele, row, col;
    cout << "Row no. : ";
    cin >> row;
    cout << "Column no. : ";
    cin >> col;
    cout << "Element no. : ";
    cin >> ele;
    NODE *newNode = new NODE;
    newNode->ele = ele;
    newNode->row = row;
    newNode->col = col;
    newNode->next = NULL;

    if (p == NULL) {
      p = newNode;
    } else {
      NODE *temp = p;
      while (temp->next != NULL)
        temp = temp->next;
      temp->next = newNode;
    }
  }
  return p;
}

void display_sparse_mat(NODE *p, int r, int c) {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      int ele = 0;
      NODE *temp = p;
      while (temp != NULL) {
        if (temp->row == i && temp->col == j)
          ele = temp->ele;
        temp = temp->next;
      }
      cout << ele << "  ";
    }
    cout << endl;
  }
}

NODE *sum_mat(NODE *mat1, NODE *mat2) {
  NODE *sum = NULL;
  NODE *cp = NULL;

  while (mat1 != NULL || mat2 != NULL) {
    NODE *temp = new NODE;
    temp->next = NULL;

    if (mat1 != NULL && (mat2 == NULL || (mat1->row < mat2->row) || (mat1->row == mat2->row && mat1->col < mat2->col))) {
      temp->row = mat1->row;
      temp->col = mat1->col;
      temp->ele = mat1->ele;
      mat1 = mat1->next;
    } else if (mat2 != NULL && (mat1 == NULL || (mat1->row > mat2->row) || (mat1->row == mat2->row && mat1->col > mat2->col))) {
      temp->row = mat2->row;
      temp->col = mat2->col;
      temp->ele = mat2->ele;
      mat2 = mat2->next;
    } else {
      temp->row = mat1->row;
      temp->col = mat1->col;
      temp->ele = mat1->ele + mat2->ele;
      mat1 = mat1->next;
      mat2 = mat2->next;
    }
    if (sum == NULL) {
      sum = temp;
      cp = sum;
    } else {
      cp->next = temp;
      cp = cp->next;
    }
  }
  return sum;
}

int main() {
  int n1, n2, row, col;
  NODE *sp_mat1 = NULL;
  NODE *sp_mat2 = NULL;

  cout << "Enter the number of rows: ";
  cin >> row;
  cout << "Enter the number of columns: ";
  cin >> col;

  cout << "No. of Elements in sparse matrix [1]: ";
  cin >> n1;
  if (n1 > 0) {
    cout << "Sparse Matrix 1:" << endl;
    sp_mat1 = read_sparse_mat(sp_mat1, n1);
  }

  cout << "No. of Elements in sparse matrix [2]: ";
  cin >> n2;
  if (n2 > 0) {
    cout << "Sparse Matrix 2:" << endl;
    sp_mat2 = read_sparse_mat(sp_mat2, n2);
  }

  cout << "Sparse Matrix 1:" << endl;
  display_sparse_mat(sp_mat1, row, col);

  cout << "Sparse Matrix 2:" << endl;
  display_sparse_mat(sp_mat2, row, col);

  NODE *sum = sum_mat(sp_mat1, sp_mat2);
  cout << "Sum:" << endl;
  display_sparse_mat(sum, row, col);

  return 0;
}
