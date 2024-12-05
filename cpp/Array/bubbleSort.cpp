#include <iostream>
using namespace std;

int main() {
  const int n = 5;
  int arr[n] = {7, 4, 8, 5, 3};
  for (int i = n - 2; i >= 0; i--) {
    bool isSwapped = 0;  // best case senario
    for (int j = 0; j <= i; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
        isSwapped = 1;
      }
    }
    if (!isSwapped) break;
  }
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  return 0;
}