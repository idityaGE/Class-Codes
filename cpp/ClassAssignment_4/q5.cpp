//! Q5-> Write a c++ program to find the element that is present at the mid length of the linked list.

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

int mid_element(NODE *p) {
  if (p == NULL)
    cout << "List is empty" << endl;
  else {
    NODE *slow, *fast;
    slow = p;
    fast = p;
    while (fast != NULL && fast->next != NULL) {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow->data;
  }
}

int main() {
  NODE *head = NULL;
  head = push(head, 1);
  head = push(head, 2);
  head = push(head, 3);
  head = push(head, 4);
  head = push(head, 5);
  head = push(head, 6);
  head = push(head, 7);
  head = push(head, 7);

  cout << "Linked List: ";
  display(head);

  cout << "Mid Element: " << mid_element(head) << endl;

  return 0;
}