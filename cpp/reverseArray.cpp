#include <iostream>
using namespace std;

int main() {
  const int size = 5;
  int arr[size] = {1, 2, 3, 4, 5};
  int i = 0, j = size - 1;
  while(i < j){
    swap(arr[i], arr[j]);
    i++;
    j--;
  }
  for(int i = 0; i < size; i++){
    cout << arr[i] << " ";
  }
  return 0;
}