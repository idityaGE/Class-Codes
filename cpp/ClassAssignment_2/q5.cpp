//! Q5-> Write a C++ program to compute the sum of n natural numbers using recursion.

#include <iostream>
using namespace std;
int sumofN(int n) {
  if (n == 1)
    return 1;
  return sumofN(n - 1) + n;
}

int main() {
  int n;
  cout << "Enter the number : ";
  cin >> n;
  cout << "Sum of " << n << " natural number :" << sumofN(n) << endl;
  return 0;
}