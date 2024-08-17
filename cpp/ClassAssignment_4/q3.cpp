//! Q3. Write a c++ program to reverse the linked list.

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

NODE *reverse(NODE *p) {
  if (p == NULL)
    cout << "List is empty" << endl;
  else if (p->next == NULL)
    cout << "List has only one element" << endl;
  else {
    NODE *prev, *curr, *fut;
    prev = NULL;
    curr = p;
    fut = p->next;
    while (fut != NULL) {
      curr->next = prev;
      prev = curr;
      curr = fut;
      fut = fut->next;
    }
    curr->next = prev;
    p = curr;
  }
  return p;
}

int main() {
  NODE *p;
  p = NULL;
  p = create(p, 5);
  for (int i = 0; i < 5; i++) {
    p = push(p, i);
  }
  p = push(p, 10);
  p = push(p, 9);
  display(p);
  p = reverse(p);
  display(p);
  return 0;
}