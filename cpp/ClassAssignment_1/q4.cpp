//? PROBLEM: Write a program in C++ to create an array, input its element and display all the elements.

#include <iostream>
using namespace std;

int main() {
  int arr[5];
  for (int i = 0; i < 5; i++) {
    cout << "Enter the " << i << " index element of Array: ";
    cin >> arr[i];
  }

  cout << endl
       << "Arrary = [";
  for (int i = 0; i < 5; i++) {
    cout << arr[i];
    if (!(i == 4))
      cout << ",";
  }
  cout << "]";
}