#include <iostream>
using namespace std;

struct NODE {
  int data;
  NODE *next;
};

NODE *read_poly(NODE *p, int degree) {
  for (int i = 0; i <= degree; i++) {
    int data;
    cout << "Enter the coefficient of x^" << i << " : ";
    cin >> data;
    if (p == NULL) {
      p = new NODE;
      p->data = data;
      p->next = NULL;
    } else {
      NODE *temp = NULL;
      temp = p;
      while (temp->next != NULL)
        temp = temp->next;
      temp->next = new NODE;
      temp->next->data = data;
      temp->next->next = NULL;
    }
  }
  return p;
}

void display_poly(NODE *p, int degree) {
  for (int i = degree; i >= 0; i--) {
    NODE *temp = NULL;
    temp = p;
    for (int j = 0; j < i; j++) {
      temp = temp->next;
    }
    cout << temp->data << "x^" << i;
    if (i > 0) {
      cout << " + ";
    }
  }
  cout << endl;
}

NODE *sum_of_poly(NODE *p1, NODE *p2, int degree) {
  NODE *sum = NULL;
  for (int i = degree; i >= 0; i--) {
    NODE *temp1 = NULL, *temp2 = NULL;
    temp1 = p1;
    temp2 = p2;
    for (int j = 0; j < i; j++) {
      temp1 = temp1->next;
      temp2 = temp2->next;
    }
    if (sum == NULL) {
      sum = new NODE;
      sum->data = temp1->data + temp2->data;
      sum->next = NULL;
    } else {
      NODE *temp = new NODE;
      temp->data = temp1->data + temp2->data;
      temp->next = sum;
      sum = temp;
    }
  }
  return sum;
}

int main() {
  NODE *p1 = NULL, *p2 = NULL;
  int degree;
  cout << "Enter the degree of the polynomial : ";
  cin >> degree;

  cout << "Polynomial 1 : " << endl;
  p1 = read_poly(p1, degree);
  cout << "Polynomial 2 : " << endl;
  p2 = read_poly(p2, degree);

  cout << "Polynomial 1 : ";
  display_poly(p1, degree);
  cout << "Polynomial 2 : ";
  display_poly(p2, degree);

  NODE *sum = NULL;
  sum = sum_of_poly(p1,p2,degree);
  cout << "Sum of both polynomial : ";
  display_poly(sum, degree);

  return 0;
}