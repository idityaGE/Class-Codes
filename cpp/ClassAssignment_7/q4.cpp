/*
  Design a Data Structure in C++ to implement the Queue ADT using the linked list.
*/

#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *next;
};

class Queue {
  Node *front, *rear;

 public:
  Queue() {
    front = rear = NULL;
  }

  void enQueue(int value);
  int deQueue();
  void displayQueue();
};

void Queue::enQueue(int value) {
  Node *newNode = new Node;
  newNode->data = value;
  newNode->next = NULL;
  if (rear == NULL) {
    front = rear = newNode;
  } else {
    rear->next = newNode;
    rear = newNode;
  }
}

int Queue::deQueue() {
  int temp;
  if (front == NULL) {
    cout << "Queue is empty" << endl;
    return -1;
  } else {
    Node *tempNode = front;
    temp = tempNode->data;
    front = front->next;
    delete tempNode;
    return temp;
  }
}

void Queue::displayQueue() {
  if (front == NULL) {
    cout << "Queue is empty" << endl;
  } else {
    Node *tempNode = front;
    while (tempNode != NULL) {
      cout << tempNode->data << " ";
      tempNode = tempNode->next;
    }
    cout << endl;
  }
}

int main() {
  Queue q;

  q.enQueue(1);
  q.enQueue(2);
  q.enQueue(3);
  q.enQueue(4);
  q.enQueue(5);

  q.displayQueue();

  cout << q.deQueue() << " dequeued from queue" << endl;
  cout << q.deQueue() << " dequeued from queue" << endl;

  q.displayQueue();

  return 0;
}

/* **Output**

  1 2 3 4 5 
  1 dequeued from queue
  2 dequeued from queue
  3 4 5

*/