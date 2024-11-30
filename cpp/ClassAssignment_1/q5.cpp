//? Problem: Write a program in C++ to find the second smallest element from the array.
#include <climits>
#include <iostream>
using namespace std;

int secMin(int *arr, int n) {
  int min = INT_MAX;
  int sec_min = INT_MAX;
  for (int i = 0; i < n; i++) {
    if (min > arr[i]) {
      sec_min = min;
      min = arr[i];
    } else if (min < arr[i] && sec_min > arr[i]) {
      sec_min = arr[i];
    }
  }
  if (sec_min == INT_MAX)
    return -1;
  return sec_min;
}


int main() {
  const int size = 5;
  int arr[size];
  for (int i = 0; i < size; i++) {
    cout << "Enter the " << i << " index element of Array: ";
    cin >> arr[i];
  }
  cout << endl
       << "Arrary = [";
  for (int i = 0; i < size; i++) {
    cout << arr[i];
    if (!(i == size - 1))
      cout << ",";
  }
  cout << "]" << endl;
  cout << "Second Min : " << secMin(arr, size);
}