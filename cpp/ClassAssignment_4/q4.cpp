//! Q4-> Write a c++ program to remove duplicates in sorted linked list.

#include <iostream>
using namespace std;

struct NODE {
  int data;
  NODE *next;
};

NODE *create(NODE *p, int data) {
  p = new NODE;
  p->data = data;
  p->next = NULL;
  return p;
}

NODE *push(NODE *p, int data) {
  if (p == NULL)
    p = create(p, data);
  else {
    NODE *temp;
    temp = p;
    while (temp->next != NULL)
      temp = temp->next;
    temp->next = create(temp->next, data);
  }
  return p;
}

void display(NODE *p) {
  if (p == NULL)
    cout << "List is empty" << endl;
  else {
    NODE *temp;
    temp = p;
    while (temp != NULL) {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << endl;
  }
}

NODE *remove_duplicates(NODE *p) {
  if (p == NULL)
    cout << "List is empty" << endl;
  else if (p->next == NULL)
    cout << "List has only one element" << endl;
  else {
    NODE *temp, *temp1;
    temp = p;
    while (temp->next != NULL) {
      if (temp->data == temp->next->data) {
        temp1 = temp->next;
        temp->next = temp->next->next;
        delete temp1;
      } else {
        temp = temp->next;
      }
    }
  }
  return p;
}

int main() {
  NODE *start = NULL;
  start = push(start, 1);
  cout << "Original list: ";
  display(start);
  start = remove_duplicates(start);
  cout << "List after removing duplicates: ";
  display(start);
  return 0;
}