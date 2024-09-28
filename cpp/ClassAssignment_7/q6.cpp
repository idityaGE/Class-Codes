/*
  Design the ADT for priority queues in C++. Consider the integer number for priority i.e.
  higher the number higher the priority and lower the number then lower the priority.
*/

#include <iostream>
using namespace std;

struct Node {
  int data;
  int priority;
  Node* next;
};

class PriorityQueue {
  Node* front;
  Node* rear;

 public:
  PriorityQueue() {
    front = rear = NULL;
  }

  void enqueue(int data, int priority) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;

    if (front == NULL) {
      front = rear = newNode;
    } else {
      if (front->priority < priority) {
        newNode->next = front;
        front = newNode;
      } else {
        Node* temp = front;
        while (temp->next != NULL && temp->next->priority >= priority) {
          temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
      }
    }
  }

  int dequeue() {
    if (front == NULL) {
      cout << "Queue is empty" << endl;
      return -1;
    } else {
      Node* temp = front;
      front = front->next;
      int data = temp->data;
      delete temp;
      return data;
    }
  }

  void display() {
    if (front == NULL) {
      cout << "Queue is empty" << endl;
    } else {
      Node* temp = front;
      while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
      }
      cout << endl;
    }
  }
};

int main() {
  PriorityQueue pq;
  pq.enqueue(10, 2);
  pq.enqueue(20, 1);
  pq.enqueue(30, 3);
  pq.enqueue(40, 2);
  pq.enqueue(50, 1);
  pq.display();
  cout << pq.dequeue() << endl;
  cout << pq.dequeue() << endl;
  cout << pq.dequeue() << endl;

  return 0;
}
