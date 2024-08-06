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

void display_in_reverse(NODE *p){
  if(p == NULL)
    cout << "List is empty" << endl;
  else {
    if(p->next != NULL)
      display_in_reverse(p->next);
    cout << p->data << " ";
  }
}

int main() {
  NODE *ll;
  ll = NULL;
  ll = create(ll, 10);
  ll = insert_at_end(ll, 20);
  ll = insert_at_end(ll, 30);
  ll = insert_at_beg(ll, 0);
  display(ll);
  display_in_reverse(ll);

  return 0;
}