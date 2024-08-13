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
    if (p == NULL) {
      p = new NODE;
      p->ele = ele;
      p->row = row;
      p->col = col;
      p->next = NULL;
    } else {
      NODE *temp = NULL;
      temp = p;
      while (temp->next != NULL)
        temp = temp->next;
      temp->next = new NODE;
      temp->next->ele = ele;
      temp->next->row = row;
      temp->next->col = col;
      temp->next->next = NULL;
    }
  }
  return p;
}

void display_sparse_mat(NODE *p, int n, int r, int c) {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      int ele = 0;
      NODE *temp = p;
      while (temp != NULL) {
        if (temp->row = r && temp->col == c)
          ele = temp->ele;
        else
          temp = temp->next;
      }
      cout << 0 << "  ";
    }
    cout << endl;
  }
}

int main() {
  int n, row, col;
  NODE *sp_mat1 = NULL;
  cout << "Enter the number of rows: ";
  cin >> row;
  cout << "Enter the number of columns: ";
  cin >> col;
  cout << "No. of Element in sparse matrix :";
  cin >> n;

  cout << "Sparse Matrix :" << endl;
  sp_mat1 = read_sparse_mat(sp_mat1, n);
  cout << "Sparse Matrix :" << endl;
  display_sparse_mat(sp_mat1, n, row, col);

  return 0;
}