/*
  Design the ADT for queues by using the optimal number of stacks as underlying storage mechanism.
*/

#include <iostream>
using namespace std;

class Stack {
  int* arr;
  int top;
  int size;

 public:
  Stack(int size) {
    this->size = size;
    arr = new int[size];
    top = -1;
  }

  void push(int data) {
    if (top == size - 1) {
      cout << "Stack if Full" << endl;
    } else {
      arr[++top] = data;
    }
  }

  int pop() {
    if (top == -1) {
      cout << "Stack is empty" << endl;
      return -1;
    } else {
      return arr[top--];
    }
  }

  int peek() {
    if (top == -1) {
      cout << "Stack is empty" << endl;
      return -1;
    } else {
      return arr[top];
    }
  }

  bool isEmpty() {
    return top == -1;
  }

  bool isFull() {
    return top == size - 1;
  }

  void display() {
    for (int i = 0; i <= top; i++) {
      cout << arr[i] << " ";
    }
  }

  void displayReverse() {
    for (int i = top; i >= 0; i--) {
      cout << arr[i] << " ";
    }
  }
};

class Queue {
  Stack* s1;  // Stack for enqueue
  Stack* s2;  // Stack for dequeue

 public:
  Queue(int size) {
    s1 = new Stack(size);
    s2 = new Stack(size);
  }

  void enqueue(int data) {
    if (s1->isFull()) {
      cout << "Queue is full" << endl;
    } else {
      s1->push(data);
    }
  }

  int dequeue() {
    if (s1->isEmpty() && s2->isEmpty()) {
      cout << "Queue is empty" << endl;
      return -1;
    }
    if (s2->isEmpty()) {
      while (!s1->isEmpty()) {
        s2->push(s1->pop());
      }
    }
    return s2->pop();
  }

  void display() {
    if (s1->isEmpty() && s2->isEmpty()) {
      cout << "Queue is empty" << endl;
    } else {
      cout << "Queue: ";
      s2->displayReverse();
      s1->display();
    }
  }
};

int main() {
  Queue q(5);
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  q.enqueue(4);
  q.enqueue(5);
  q.display();
  cout << endl;

  q.dequeue();
  q.dequeue();
  q.display();
  cout << endl;

  q.enqueue(6);
  q.enqueue(7);
  q.display();
  cout << endl;
  q.dequeue();
  q.display();

  return 0;
}

/* Output:

  Queue: 1 2 3 4 5
  Queue: 3 4 5
  Queue: 3 4 5 6 7i
  Queue: 4 5 6 7

*/