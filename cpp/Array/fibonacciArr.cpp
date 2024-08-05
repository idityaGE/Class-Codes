#include <iostream>
using namespace std;

int main()
{
  const int n = 8;
  int arr[n] = {0, 1};
  for (int i = 2; i < n; i++)
  {
    arr[i] = arr[i - 1] + arr[i - 2];
  }
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << endl;
  }
  return 0;
}