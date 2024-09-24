/*
  Design a Data Structure in C++ to implement the Circular Queue ADT using the array.
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
  } else if((rear + 1) % size == front) {
    cout << "Queue is full" << endl;
  } else {
    rear = (rear + 1) % size;
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
    front = (front + 1) % size;
    return temp;
  }
}

void Queue::displayQueue() {
  if(front == -1 && rear == -1) {
    cout << "Queue is empty" << endl;
  } else {
    int i = front;
    while(i != rear) {
      cout << arr[i] << " ";
      i = (i + 1) % size;
    }
    cout << arr[rear] << endl;
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

  q.deQueue();
  q.deQueue();
  q.displayQueue();

  q.enQueue(6);
  q.enQueue(7);
  q.displayQueue();

  return 0;
}