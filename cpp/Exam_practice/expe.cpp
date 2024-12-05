#include <iostream>
using namespace std;

void redMatrix(int **mat, int r) {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < r; j++) {
      cout << "Enter the element of (" << i << "," << j << ") :";
      cin >> mat[i][j];
    }
  }
}


// Node *reverseLL(Node *head) {
//   if(!head || !head->next) return head;
//   Node *newNode = reverseLL(head->next);
//   head->next->next = head;
//   head->next = NULL;
//   return newNode;
// }


int main() {
  int n = 4;
  int x = n * (n + 1) / 2;
  cout << x;
  return 0;
}