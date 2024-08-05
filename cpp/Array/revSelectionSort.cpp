#include <iostream>
using namespace std;

int main()
{
  const int n = 5;
  int arr[n] = {10, 4, 3, 2, 8};

  for (int i = n - 1; i >= 1; i--)
  {
    int index = i;
    for (int j = i - 1; j >= 0; j--)
    {
      if (arr[j] > arr[index])
      {
        index = j;
      }
    }
    swap(arr[i], arr[index]);
  }
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
}