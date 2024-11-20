/*
?  Design a data structure in C++ to implement the Stack using array.
?  Implement all stack operations.
*/

#include <iostream>
using namespace std;

struct Stack {
 private:
  int size;
  int top;
  int *s;

 public:
  Stack(int size) {
    this->size = size;
    top = -1;
    s = new int[size];
  }

  void push(int x) {
    if (top == size - 1)
      cout << "Stack is Full" << endl;
    else
      s[++top] = x;
  }

  int pop() {
    int x = -1;
    if (top == -1)
      cout << "Stack is empty" << endl;
    else
      x = s[top--];
    return x;
  }

  int peek(int index) {
    if (index < 0 || index > top) {
      cout << "Invalid Index" << endl;
      return -1;
    } else
      return s[index];
  }

  int stackTop() {
    if (top == -1)
      return -1;

    return s[top];
  }

  bool isEmpty() {
    return top == -1;
  }

  bool isFull() {
    return top == size - 1;
  }

  void display() {
    for (int i = top; i >= 0; i--)
      cout << s[i] << " | ";

    cout << endl;
  }

  ~Stack() {
    delete[] s;
  }
};

int main() {
  Stack stk(5);

  stk.push(1);
  stk.push(2);
  stk.push(3);
  stk.push(4);
  stk.push(5);

  stk.display();

  cout << "Element at position 1: " << stk.peek(1) << endl;
  cout << "Element at position 2: " << stk.peek(2) << endl;

  cout << "Popped: " << stk.pop() << endl;

  stk.display();

  cout << "Stack top: " << stk.stackTop() << endl;

  return 0;
}
