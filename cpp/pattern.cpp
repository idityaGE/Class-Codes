#include <iostream>
using namespace std;

int main()
{
  int num;
  cout << "Enter the Number:";
  cin >> num;
  int ans = 0;
  while (num > 9)
  {
    int rem;
    while (num > 0)
    {
      rem = num % 10;
      ans += rem;
      num /= 10;
    }
    num = ans;
  }
  cout << num;
}