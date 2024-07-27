#include <iostream>
#include <cmath> // Use <cmath> for C++ standard math functions
using namespace std;

int countDigit(int n)
{
  int count = 0;
  while (n)
  {
    n /= 10;
    count++;
  }
  return count;
}

bool isArmstrong(int n)
{
  int digit = countDigit(n);
  int num = n;
  int ans = 0, rem;
  while (num)
  {
    rem = num % 10;
    ans += pow(rem, digit);
    num /= 10;
  }
  return n == ans;
}

int main()
{
  int n;
  cout << "Enter the Number : ";
  cin >> n;
  cout << (isArmstrong(n) ? "Yes" : "No") << endl;
  return 0;
}
