#include <iostream>
using namespace std;

struct NODE {
  int data;
  NODE *next;
};

struct POLY {
  int degree;
  int *coefficients;
};

void read_poly(POLY *p) {
  for (int i = 0; i <= p->degree; i++) {
    cout << "Enter the coefficient of x^" << i << " : ";
    cin >> p->coefficients[i];
  }
}

void display_poly(POLY p) {
  for (int i = p.degree; i >= 0; i--) {
    cout << p.coefficients[i] << "x^" << i;
    if (i > 0) {
      cout << " + ";
    }
  }
  cout << endl;
}

int main() {
  POLY p1, p2;
  cout << "Enter the degree of the polynomial [p1] : ";
  cin >> p1.degree;
  cout << "Enter the degree of the polynomial [p2] : ";
  cin >> p2.degree;
  p1.coefficients = new int[p1.degree + 1];
  p2.coefficients = new int[p2.degree + 1];
  cout << "Enter the coefficients of the polynomial [p1] : " << endl;
  read_poly(&p1);
  cout << "Enter the coefficients of the polynomial [p2] : " << endl;
  read_poly(&p2);
  cout << "p1 : ";
  display_poly(p1);
  cout << "p2 : ";
  display_poly(p2);

  return 0;
}