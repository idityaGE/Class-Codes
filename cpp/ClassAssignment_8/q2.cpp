/*
  Write a program to implement the Hash Table ADT with collision handling mechanism
  using chaining method.
*/

#include <iostream>
using namespace std;

class HashTable {
  int *arr;
  int size;

 public:
  HashTable(int size) {
    this->size = size;
    arr = new int[size];
    for (int i = 0; i < size; i++)
      arr[i] = -1;
  }

  void insert(int value) {
    int key = value % size;
    if (arr[key] == -1)
      arr[key] = value;
    else {
      int i = 1;
      while (arr[(key + i) % size] != -1)
        i++;
      arr[(key + i) % size] = value;
    }
  }

  void search(int value) {
    int key = value % size;
    if (arr[key] == value)
      cout << "Value " << value << " found at index " << key << endl;
    else {
      int i = 1;
      while (arr[(key + i) % size] != value)
        i++;
      if (arr[(key + i) % size] == value)
        cout << "Value " << value << " found at index " << (key + i) % size << endl;
      else
        cout << "Value " << value << " not found" << endl;
    }
  }

  void remove(int value) {
    int key = value % size;
    if (arr[key] == value)
      arr[key] = -1;
    else {
      int i = 1;
      while (arr[(key + i) % size] != value)
        i++;
      if (arr[(key + i) % size] == value)
        arr[(key + i) % size] = -1;
      else
        cout << "Value " << value << " not found" << endl;
    }
  }

  void display() {
    for (int i = 0; i < size; i++) {
      if (arr[i] != -1)
        cout << i << " --> " << arr[i] << endl;
      else
        cout << i << " --> " << "empty" << endl;
    }
    cout << endl;
  }
};

int main() {
  HashTable ht(10);

  ht.insert(12);
  ht.insert(23);
  ht.insert(47);
  ht.display();

  ht.search(23);
  ht.remove(23);
  ht.display();

  ht.insert(32); // collision --> 32 % 10 = 2 --> 2 + 1 --> 3 index
  ht.insert(42); // collision --> 42 % 10 = 2 --> 2 + 2 --> 4 index
  ht.display();
  return 0;
}

// Output
/*
0 --> empty
1 --> empty
2 --> 12
3 --> 23
4 --> empty
5 --> empty
6 --> empty
7 --> 47
8 --> empty
9 --> empty

Value 23 found at index 3
0 --> empty
1 --> empty
2 --> 12
3 --> empty
4 --> empty
5 --> empty
6 --> empty
7 --> 47
8 --> empty
9 --> empty

0 --> empty
1 --> empty
2 --> 12
3 --> 32
4 --> 42
5 --> empty
6 --> empty
7 --> 47
8 --> empty
9 --> empty
*/