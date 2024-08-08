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

NODE *insert_at_end(NODE *p, int data) {
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

NODE *insert_at_beg(NODE *p, int data) {
  if (p == NULL)
    p = create(p, data);
  else {
    NODE *temp;
    temp = new NODE;
    temp->data = data;
    temp->next = p;
    p = temp;
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

void display_in_reverse(NODE *p) {
  if (p == NULL)
    cout << "List is empty" << endl;
  else {
    if (p->next != NULL)
      display_in_reverse(p->next);
    cout << p->data << " ";
  }
}

bool search(NODE *p, int data) {
  if (p == NULL)
    cout << "List is empty" << endl;
  else {
    NODE *temp;
    temp = p;
    while (temp != NULL) {
      if (temp->data == data)
        return true;
      temp = temp->next;
    }
    return false;
  }
}

NODE *merge(NODE *p1, NODE *p2) {
  if (p1 == NULL)
    return p2;
  if (p2 == NULL)
    return p1;
  else {
    NODE *temp;
    temp = p1;
    while (temp->next != NULL)
      temp = temp->next;
    temp->next = p2;
    return p1;
  }
}

int main() {
  NODE *l1;
  l1 = NULL;
  l1 = create(l1, 10);
  l1 = insert_at_end(l1, 20);
  l1 = insert_at_end(l1, 30);
  l1 = insert_at_beg(l1, 0);
  display(l1);
  NODE *l2;
  l2 = NULL;
  l2 = create(l2, 40);
  l1 = merge(l1, l2);
  display(l1);
  if (search(l1, 50)) {
    cout << "found";
  } else
    cout << "Not Found";
  return 0;
}