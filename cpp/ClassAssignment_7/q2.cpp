/*
  Design a Data Structure in C++ to implement the Queue ADT using an Array.
*/
#include <iostream>
using namespace std;

class Queue {
  int front, rear, size;
  int *arr;

 public:
  Queue(int s) {
    front = rear = -1;
    size = s;
    arr = new int[s];
  }

  void enQueue(int value);
  int deQueue();
  void displayQueue();
};

void Queue::enQueue(int value) {
  if(front == -1 && rear == -1) {
    front = rear = 0;
    arr[rear] = value;
  } else if(rear == size - 1) {
    cout << "Queue is full" << endl;
  } else {
    rear++;
    arr[rear] = value;
  }
}

int Queue::deQueue() {
  int temp;
  if(front == -1 && rear == -1) {
    cout << "Queue is empty" << endl;
    return -1;
  } else if(front == rear) {
    temp = arr[front];
    front = rear = -1;
    return temp;
  } else {
    temp = arr[front];
    front++;
    return temp;
  }
}

void Queue::displayQueue() {
  if(front == -1 && rear == -1) {
    cout << "Queue is empty" << endl;
  } else {
    for(int i = front; i <= rear; i++) {
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
  q.deQueue();
  q.displayQueue();
  q.enQueue(7);
  q.enQueue(8);
  q.displayQueue();
  return 0;
}

/* **Output**

  1 2 3 4 5
  Queue is full
  1 2 3 4 5
  3 4 5
  Queue is full
  Queue is full
  3 4 5

*/