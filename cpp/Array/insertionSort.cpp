#include <iostream>
using namespace std;

int main()
{
  const int n = 6;
  int arr[n] = {3, 5, 3, 6, 27, 87};
  for (int i = 1; i < n; i++)
  {
    for (int j = i; j > 0; j--)
    {
      if (arr[j] < arr[j - 1])
        swap(arr[j - 1], arr[j]);
      else
        break;
    }
  }
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  return 0;
}