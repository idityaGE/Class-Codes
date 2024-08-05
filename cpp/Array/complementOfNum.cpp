#include <iostream>
using namespace std;
int main()
{
  int n;
  cout << "Enter the number : ";
  cin >> n;
  int ans = 0, rem, mul = 1;
  while (n)
  {
    rem = n % 2;
    n /= 2;
    rem = rem ^ 1;
    rem *= mul;
    ans = ans + rem;
    mul *= 2;
  }
  cout << ans;
}