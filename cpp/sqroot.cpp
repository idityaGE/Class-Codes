#include <iostream>
using namespace std;
#include <climits>

int main()
{
  int num;
  cout << "Enter the Number:";
  cin >> num;
  int i = 1;
  while (i <= num)
  {
    int sqr = i * i;
    if (sqr > INT_MAX)
    {
      cout << i - 1 << endl;
      return 1;
    }
    if (sqr == num)
    {
      cout << i << endl;
      return 1;
    }
    if (sqr > num)
    {
      cout << i - 1 << endl;
      return 1;
    }
    i++;
  }
  return 0;
}