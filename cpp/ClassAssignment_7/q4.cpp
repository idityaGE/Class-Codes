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