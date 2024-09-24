/*
  Design a Data Structure in C++ to implement the Queue ADT using an Array [Note: use
  only one variable to point either on front or rear to implement].
*/
#include <iostream>
using namespace std;

class Queue {
  int rear, size;
  int *arr;

 public:
  Queue(int s) {
    rear = -1;
    size = s;
    arr = new int[s];
  }

  void enQueue(int value);
  int deQueue();
  void displayQueue();
};

void Queue::enQueue(int value) {
  if (rear == size - 1) {
    cout << "Queue is full" << endl;
  } else {
    rear++;
    arr[rear] = value;
  }
}

int Queue::deQueue() {
  int temp;
  if (rear == -1) {
    cout << "Queue is empty" << endl;
    return -1;
  } else {
    temp = arr[0];
    for (int i = 0; i < rear; i++) {
      arr[i] = arr[i + 1];
    }
    rear--;
    return temp;
  }
}

void Queue::displayQueue() {
  if (rear == -1) {
    cout << "Queue is empty" << endl;
  } else {
    for (int i = 0; i <= rear; i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
  }
}

int main() {
  Queue q(5);

  q.enQueue(1);
  q.enQueue(2);
  q.enQueue(3);
  q.enQueue(4);
  q.enQueue(5);
  q.displayQueue();
  q.enQueue(6);
  q.displayQueue();
  q.deQueue();
  q.displayQueue();
  q.deQueue();
  return 0;
}