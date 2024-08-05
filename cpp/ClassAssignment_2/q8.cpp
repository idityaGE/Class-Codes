//! Q8-> Write a C++ program to compute following equation up to the n term using recursion:
//! e^x = 1 + x/1! + x^2/2! + x^3/3! + ...

#include <iostream>
using namespace std;
int fact(int n) {
  if (n == 0)
    return 1;
  return fact(n - 1) * n;
}

double expo(double x, int n) {
  if (n == 0)
    return 1;
  return expo(x, n - 1) * x;
}

double expSum(double x, int n) {
  if (n == 0)
    return 1;
  return (expo(x, n) / fact(n)) + expSum(x, n - 1);
}

int main() {
  double x;
  int n;
  cout << "Enter the value of x: ";
  cin >> x;
  cout << "Enter the number of terms n: ";
  cin >> n;

  double result = expSum(x, n);
  cout << "Result : " << result;

  return 0;
}