#include <iostream>

class Node {
public:
  int data;
  Node* next;

  Node(int val) : data(val), next(nullptr) {}
  Node(int val, Node* nextNode) : data(val), next(nextNode) {}
};

class LinkedList {
private:
  Node* head;

public:
  LinkedList() : head(nullptr) {}

  void insertAtEnd(int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
      head = newNode;
    } else {
      Node* temp = head;
      while (temp->next != nullptr) {
        temp = temp->next;
      }
      temp->next = newNode;
    }
  }

  void insertAtBeginning(int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
  }

  void deleteNode(int val) {
    if (head == nullptr) return;

    if (head->data == val) {
      Node* temp = head;
      head = head->next;
      delete temp;
      return;
    }

    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != val) {
      temp = temp->next;
    }

    if (temp->next == nullptr) return;

    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
  }

  void display() const {
    Node* temp = head;
    while (temp != nullptr) {
      std::cout << temp->data << " -> ";
      temp = temp->next;
    }
    std::cout << "nullptr" << std::endl;
  }

  ~LinkedList() {
    Node* temp;
    while (head != nullptr) {
      temp = head;
      head = head->next;
      delete temp;
    }
  }
};

int main() {
  LinkedList list;
  list.insertAtEnd(1);
  list.insertAtEnd(2);
  list.insertAtEnd(3);
  list.insertAtBeginning(0);
  list.display();

  list.deleteNode(2);
  list.display();

  return 0;
}