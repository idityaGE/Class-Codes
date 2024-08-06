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

int avg(Array *a) {
  if (a->cp == -1)
    cout << "Array is empty" << endl;
  else {
    int sum = 0;
    for (int i = 0; i <= a->cp; i++)
      sum += a->arr[i];
    return sum/(a->cp+1);
  }
}



int main() {
  int size;
  cout << "Enter the size of Array : ";
  cin >> size;
  Array a;
  createArr(&a, size);
  readArr(&a);
  printArr(&a);
  cout << len(&a) << endl;
  unshift(&a);
  printArr(&a);
  pop(&a);
  printArr(&a);
  cout << len(&a);

  return 0;
}