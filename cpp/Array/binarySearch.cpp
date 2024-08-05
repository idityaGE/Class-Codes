#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int target) {
  int low = 0, high = n - 1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] == target)
      return mid;
    else if (arr[mid] < target)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return -1;
}

int main() {
  int target;
  cout << "Enter the target value: ";
  cin >> target;
  int n;
  cout << "Enter the size of the array: ";
  cin >> n;
  int arr[100];
  cout << "Enter the elements of the array: ";
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int index = binarySearch(arr, n, target);
  if (index == -1)
    cout << "Element not found" << endl;
  else
    cout << "Element found at index " << index << endl;
  return 0;
}