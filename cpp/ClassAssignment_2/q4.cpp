//! Q4-> Write a C++ program to represent the polynomial equation using structure. Also, write the function to evaluate the polynomial equation for a given value of x.

#include <cmath>
#include <iostream>
using namespace std;

struct Polynomial {
  int degree;
  int *coefficients;
};

double cal_poly(Polynomial &poly, double x) {
  double result = 0;
  for (int i = 0; i <= poly.degree; i++) {
    result += poly.coefficients[i] * pow(x, i);
  }
  return result;
}

int main() {
  Polynomial poly;
  cout << "Enter the degree of the polynomial: ";
  cin >> poly.degree;

  poly.coefficients = new int[poly.degree + 1];
  cout << "Enter the coefficients of the polynomial: " << endl;
  for (int i = 0; i <= poly.degree; i++) {
    cout << "Enter the coefficient of x^" << i << " : ";
    cin >> poly.coefficients[i];
  }

  double x;
  cout << "Enter the value of x: ";
  cin >> x;

  double result = cal_poly(poly, x);
  cout << "The result of the polynomial equation for x = " << x << " is: " << result << endl;

  delete[] poly.coefficients;
  return 0;
}
