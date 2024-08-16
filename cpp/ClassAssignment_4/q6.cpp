//! Q6-> Write a c++ program to implement doubly linked list using two pointers front, rear pointers with following operations :
//* a.Create() to initialize the list with first element
//* b.Insert_at_end() to insert an element at the end of the list
//* c.Insert_at_beg() to insert an element at the beginning of the list
//* d.Insert_at _sorted() insert the element in sorted order
//* e.Display() print all the elements of the list
//* f.reverse() to reverse the linked list.g.Search() to search an element from the list

#include <iostream>
using namespace std;

struct NODE {
  int data;
  NODE *next;
  NODE *prev;
};

NODE *create(NODE *p, int data) {
  p = new NODE;
  p->data = data;
  p->next = NULL;
  p->prev = NULL;
  return p;
}

NODE *insert_at_end(NODE *p, int data) {
  if (p == NULL)
    p = create(p, data);
  else {
    NODE *temp;
    temp = p;
    while (temp->next != NULL)
      temp = temp->next;
    temp->next = create(temp->next, data);
    temp->next->prev = temp;
  }
  return p;
}

NODE *insert_at_beg(NODE *p, int data) {
  if (p == NULL)
    p = create(p, data);
  else {
    NODE *temp;
    temp = new NODE;
    temp->data = data;
    temp->next = p;
    p->prev = temp;
    p = temp;
  }
  return p;
}

NODE *insert_at_sorted(NODE *p, int data) {
  if (p == NULL)
    p = create(p, data);
  else {
    NODE *temp, *temp1;
    temp = p;
    while (temp->next != NULL && temp->data < data)
      temp = temp->next;
    if (temp->data < data) {
      temp->next = create(temp->next, data);
      temp->next->prev = temp;
    } else {
      temp1 = new NODE;
      temp1->data = data;
      temp1->next = temp;
      temp1->prev = temp->prev;
      temp->prev->next = temp1;
      temp->prev = temp1;
    }
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
    NODE *temp, *temp1;
    temp = p;
    while (temp->next != NULL)
      temp = temp->next;
    while (temp != NULL) {
      cout << temp->data << " ";
      temp = temp->prev;
    }
    cout << endl;
  }
  return p;
}

int main() {
  NODE *front = NULL;
  front = insert_at_end(front, 1);
  front = insert_at_end(front, 2);
  front = insert_at_end(front, 3);
  front = insert_at_end(front, 4);
  front = insert_at_end(front, 5);
  display(front);
  front = insert_at_beg(front, 0);
  display(front);

  front = insert_at_sorted(front, 6);
  display(front);

  return 0;
}