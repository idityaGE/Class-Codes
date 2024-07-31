#include <iostream>
using namespace std;

int main()
{
  const int n = 8;
  int arr[n] = {24, 18, 38, 43, 14, 40, 1, 54};
  for (int i = 0; i <= n - 2; i++)
  {
    for (int j = n - 1; j > i; j--)
    {
      if (arr[j] < arr[j - 1])
      {
        swap(arr[j], arr[j - 1]);
      }
    }
  }
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }

  return 0;
}