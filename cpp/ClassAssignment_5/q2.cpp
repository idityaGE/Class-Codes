/*
?  Design a data structure in C++ to implement the Stack using linked list.
?  Implement all stack operations.
*/

#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *next;
};

struct Stack {
 private:
  Node *top;

 public:
  Stack() {
    top = nullptr;
  }

  void push(int x) {
    Node *t = new Node;
    t->data = x;
    t->next = top;
    top = t;
  }

  int pop() {
    int x = -1;
    if (top == nullptr) {
      cout << "Stack is empty" << endl;
    } else {
      Node *t = top;
      top = top->next;
      x = t->data;
      delete t;
    }
    return x;
  }

  int peek(int index) {
    Node *p = top;
    for (int i = 0; p != nullptr && i < index - 1; i++) {
      p = p->next;
    }
    if (p != nullptr) {
      return p->data;
    }
    return -1;
  }

  int stackTop() {
    if (top != nullptr) {
      return top->data;
    }
    return -1;
  }

  bool isEmpty() {
    return top == nullptr;
  }

  void display() {
    Node *p = top;
    while (p != nullptr) {
      cout << p->data << " | ";
      p = p->next;
    }
    cout << endl;
  }

  ~Stack() {
    Node *p = top;
    while (top) {
      top = top->next;
      delete p;
      p = top;
    }
  }
};

int main() {
  Stack stk;
  stk.push(10);
  stk.push(20);
  stk.push(30);
  stk.push(40);
  stk.push(50);
  stk.push(60);
  stk.push(70);

  cout << "Stack: ";
  stk.display();

  cout << "Peek at index 3: " << stk.peek(3) << endl;
  cout << "Stack top: " << stk.stackTop() << endl;

  cout << "Popped: " << stk.pop() << endl;
  cout << "Popped: " << stk.pop() << endl;

  cout << "Stack: ";
  stk.display();

  // delete stack
  stk.~Stack();
  return 0;
}