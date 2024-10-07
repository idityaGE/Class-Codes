/*
Write a program in C++ to implement the Hash Table using array. Design the ADT for
hash table and implement.
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
    else
      cout << "Collision occurred for value " << value << " at index " << key << endl;
  }

  void search(int value) {
    int key = value % size;
    if (arr[key] == value)
      cout << "Value " << value << " found at index " << key << endl;
    else
      cout << "Value " << value << " not found" << endl;
  }

  void remove(int value) {
    int key = value % size;
    if (arr[key] == value)
      arr[key] = -1;
    else
      cout << "Value " << value << " not found" << endl;
  }

  void display() {
    for (int i = 0; i < size; i++) {
      if (arr[i] != -1)
        cout << i << " --> " << arr[i] << endl;
      else
        cout << i << " --> " << "empty" << endl;
    }
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

  ht.insert(32);  // collision
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
Collision occurred for value 32 at index 2
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
*/