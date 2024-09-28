/*
  Design the ADT for priority queues in C++. Consider only three levels of priorities i.e.
  High, Normal and Low.
*/

#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
};

class PriorityQueue {
  Node* High;
  Node* Normal;
  Node* Low;

 public:
  PriorityQueue() {
    High = Normal = Low = NULL;
  }

  void push_back(Node*& Head, Node* newNode) {
    if (Head == NULL) {
      Head = newNode;
    } else {
      Node* temp = Head;
      while (temp->next != NULL) {
        temp = temp->next;
      }
      temp->next = newNode;
    }
  }

  void enqueue(int data, char priority) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;

    if (priority == 'H') {
      push_back(High, newNode); 
    } else if (priority == 'N') {
      push_back(Normal, newNode); 
    } else if (priority == 'L') {
      push_back(Low, newNode); 
    } else {
      cout << "Invalid priority" << endl;
    }
  }

  int remove(Node*& Head) {
    if (Head == NULL) {
      cout << "Queue is empty" << endl;
      return -1;
    } else {
      Node* temp = Head;
      Head = Head->next; 
      int data = temp->data;
      delete temp;
      return data;
    }
  }

  int dequeue(char priority) {
    if (priority == 'H') {
      return remove(High); 
    } else if (priority == 'N') {
      return remove(Normal); 
    } else if (priority == 'L') {
      return remove(Low); 
    } else {
      cout << "Invalid priority" << endl;
      return -1;
    }
  }

  void print(Node* Head) {
    if (Head == NULL) {
      cout << "Queue is empty" << endl;
    } else {
      Node* temp = Head;
      while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
      }
      cout << endl;
    }
  }

  void display(char priority) {
    if (priority == 'H') {
      cout << "High priority: ";
      print(High);
    } else if (priority == 'N') {
      cout << "Normal priority: ";
      print(Normal);
    } else if (priority == 'L') {
      cout << "Low priority: ";
      print(Low);
    } else {
      cout << "Invalid priority" << endl;
    }
  }
};

int main() {
  PriorityQueue pq;
  pq.enqueue(1, 'H');
  pq.enqueue(2, 'N');
  pq.enqueue(3, 'L');
  pq.enqueue(4, 'H');
  pq.enqueue(5, 'N');
  pq.enqueue(6, 'L');

  pq.display('H');
  pq.display('N');
  pq.display('L');

  cout << pq.dequeue('H') << endl;
  cout << pq.dequeue('N') << endl;
  cout << pq.dequeue('L') << endl;
  cout << pq.dequeue('H') << endl;
  cout << pq.dequeue('N') << endl;
  cout << pq.dequeue('L') << endl;
  cout << pq.dequeue('H') << endl; 

  return 0;
}
