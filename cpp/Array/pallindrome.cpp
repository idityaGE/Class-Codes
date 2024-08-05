#include <iostream>
using namespace std;
int main()
{
  int x;
  cout << "Enter the number : ";
  cin >> x;
  if (x < 0)
    return 0;
  int n = x, rev = 0, rem;
  while (n)
  {
    rem = n % 10;
    rev = rev * 10 + rem;
    n /= 10;
  }
  if (x = rev)
    cout << "pallindrome";
  else
    cout << "not pallindrome";
}