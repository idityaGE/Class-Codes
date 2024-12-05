#include <iostream>
using namespace std;

int garbageVal = -9999;

struct Array {
  int size;
  int *arr;
  int cp;
};

void createArr(Array *a, int size) {
  a->cp = -1;
  a->size = size;
  a->arr = new int[size];
  cout << "Array created succesfully." << endl;
}

void push(Array *a, int ele) {
  if (a->cp == a->size - 1)
    cout << "Array is Full";
  else {
    a->cp++;
    a->arr[a->cp] = ele;
  }
}

void pop(Array *a) {
  if (a->cp == -1)
    cout << "Array is empty";
  else {
    a->arr[a->cp] = garbageVal;
    a->cp--;
  }
}

void shift(Array *a, int ele) {
  if (a->cp == a->size - 1)
    cout << "Array is Full";
  else {
    for (int i = a->cp; i >= 0; i--)
      a->arr[i + 1] = a->arr[i];
    a->arr[0] = ele;
    a->cp++;
  }
}

void unshift(Array *a) {
  if (a->cp == -1)
    cout << "Array is empty";
  else {
    for (int i = 1; i <= a->cp; i++)
      a->arr[i - 1] = a->arr[i];
    a->arr[a->cp] = garbageVal;
    a->cp--;
  }
}

void printArr(Array *a) {
  if (a->cp == -1)
    cout << "Array is empty" << endl;
  else {
    for (int i = 0; i <= a->cp; i++)
      cout << a->arr[i] << " ";
    cout << endl;
  }
}

void readArr(Array *a) {
  for (int i = 0; i < a->size; i++) {
    cout << "Enter the " << i << " index element : ";
    cin >> a->arr[i];
  }
  a->cp = a->size - 1;
}

int len(Array *a) {
  return (a->cp + 1);
}

int min(Array *a) {
  if (a->cp == -1)
    cout << "Array is empty" << endl;
  else {
    int min = a->arr[0];
    for (int i = 0; i <= a->cp; i++)
      if (min > a->arr[i]) min = a->arr[i];
    return min;
  }
}

int max(Array *a) {
  if (a->cp == -1)
    cout << "Array is empty" << endl;
  else {
    int max = a->arr[0];
    for (int i = 0; i <= a->cp; i++)
      if (max < a->arr[i]) max = a->arr[i];
    return max;
  }
}

float avg(Array *a) {
  if (a->cp == -1)
    cout << "Array is empty" << endl;
  else {
    float sum = 0;
    for (int i = 0; i <= a->cp; i++)
      sum += a->arr[i];
    return sum / (a->cp + 1);
  }
}

int get(Array *a, int index) {
  if (a->cp == -1)
    cout << "Array is empty" << endl;
  return -1;
  else if (index > a->cp || index < 0) {
    cout << "Wrong Index" << endl;
    return -1;
  }
  else return a->arr[index];
}

void insert(Array *a, int index, int ele) {
  if (a->cp == a->size - 1)
    cout << "Array is full" << endl;
  else if (index > a->cp + 1 || index < 0)
    cout << "Wrong Index" << endl;
  else {
    for (int i = a->cp; i >= index; i--)
      a->arr[i + 1] = a->arr[i];
    a->arr[index] = ele;
    a->cp++;
  }
}

void rem(Array *a, int index) {
  if (a->cp == -1)
    cout << "Array is empty" << endl;
  else if (0 > index || index > a->cp)
    cout << "Wrong Index" << endl;
  else {
    for (int i = index; i < a->cp; i++)
      a->arr[i] = a->arr[i + 1];
    a->arr[a->cp] = garbageVal;
    a->cp--;
  }
}

void sort(Array *a) {
  if (a->cp == -1)
    cout << "Array is empty" << endl;
  else {
    for (int i = a->cp - 1; i >= 0; i--) {
      bool isSwapped = false;
      for (int j = 0; j <= i; j++) {
        if (a->arr[j] > a->arr[j + 1]) {
          swap(a->arr[j], a->arr[j + 1]);
          isSwapped = true;
        }
      }
      if (!isSwapped) break;
    }
  }
}

void clear(Array *a) {
  delete[] a->arr;
  a->cp = -1;
  cout << "Array deleted successfully." << endl;
}

int main() {
  Array arr;
  int size;

  cout << "Enter the size of the array: ";
  cin >> size;

  createArr(&arr, size);

  cout << "Enter the elements of the array: " << endl;
  readArr(&arr);

  cout << "Array: ";
  printArr(&arr);

  cout << "Length of the array: " << len(&arr) << endl;
  cout << "Minimum element of the array: " << min(&arr) << endl;
  cout << "Maximum element of the array: " << max(&arr) << endl;
  cout << "Average of the array: " << avg(&arr) << endl;
  cout << "Enter the index of the element you want to get: ";
  int index;
  cin >> index;
  cout << "Element at index " << index << " is: " << get(&arr, index) << endl;
  cout << "Enter the index where you want to insert the element: ";
  int insIndex;
  cin >> insIndex;
  cout << "Enter the element you want to insert: ";
  int insEle;
  cin >> insEle;
  insert(&arr, insIndex, insEle);
  cout << "Array after inserting the element: ";
  printArr(&arr);
  cout << "Enter the index of the element you want to remove: ";
  int remIndex;
  cin >> remIndex;
  rem(&arr, remIndex);
  cout << "Array after removing the element: ";
  printArr(&arr);
  sort(&arr);
  cout << "Array after sorting: ";
  printArr(&arr);
  clear(&arr);
  cout << "Array cleared." << endl;
  return 0;
}