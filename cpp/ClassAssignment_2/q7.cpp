#include <iostream>
using namespace std;

// Fibonacci series -->  0 1 1 2 3 5 8 13 ....
int fibonacciSeries(int n)
{
  if (n == 2)
    return 1;
  if (n == 1)
    return 0;
  return fibonacciSeries(n - 1) + fibonacciSeries(n - 2);
}

int main()
{
  int n;
  cout << "Enter the number : ";
  cin >> n;
  cout << "Fibonacci series to " << n << " number : " << fibonacciSeries(n) << endl;
  return 0;
}