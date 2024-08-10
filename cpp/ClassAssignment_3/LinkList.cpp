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

NODE *insert_at_pos(NODE *p, int data, int pos) {
  if (p == NULL)
    p = create(p, data);
  else {
    NODE *temp, *temp1;
    temp = p;
    for (int i = 1; i < pos - 1; i++) {
      if (temp->next != NULL)
        temp = temp->next;
      else {
        cout << "Position not found" << endl;
        return p;
      }
    }
    temp1 = new NODE;
    temp1->data = data;
    temp1->next = temp->next;
    temp->next = temp1;
  }
  return p;
}

NODE *insert_at_sorted_pos(NODE *p, int data) {
  if (p == NULL)
    p = create(p, data);
  else {
    NODE *temp, *temp1;
    temp = p;
    while (temp->next != NULL && temp->next->data < data)
      temp = temp->next;
    temp1 = new NODE;
    temp1->data = data;
    temp1->next = temp->next;
    temp->next = temp1;
  }
  return p;
}

NODE *delete_at_end(NODE *p) {
  if (p == NULL)
    cout << "List is empty" << endl;
  else {
    NODE *temp, *temp1;
    temp = p;
    while (temp->next != NULL) {
      temp1 = temp;
      temp = temp->next;
    }
    temp1->next = NULL;
    delete temp;
  }
  return p;
}

NODE *delete_at_beg(NODE *p) {
  if (p == NULL)
    cout << "List is empty" << endl;
  else {
    NODE *temp;
    temp = p;
    p = p->next;
    delete temp;
  }
  return p;
}

NODE *delete_at_pos(NODE *p, int pos) {
  if (p == NULL)
    cout << "List is empty" << endl;
  else {
    NODE *temp, *temp1;
    temp = p;
    for (int i = 1; i < pos - 1; i++) {
      if (temp->next != NULL)
        temp = temp->next;
      else {
        cout << "Position not found" << endl;
        return p;
      }
    }
    temp1 = temp->next;
    temp->next = temp1->next;
    delete temp1;
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

NODE *merge_sorted(NODE *p1, NODE *p2) {
  if (p1 == NULL)
    return p2;
  if (p2 == NULL)
    return p1;
  else {
    NODE *temp1, *temp2, *temp3;
    temp1 = p1;
    temp2 = p2;
    temp3 = NULL;
    while (temp1 != NULL && temp2 != NULL) {
      if (temp1->data < temp2->data) {
        if (temp3 == NULL) {
          temp3 = temp1;
          p1 = temp3;
        } else {
          temp3->next = temp1;
          temp3 = temp3->next;
        }
        temp1 = temp1->next;
      } else {
        if (temp3 == NULL) {
          temp3 = temp2;
          p1 = temp3;
        } else {
          temp3->next = temp2;
          temp3 = temp3->next;
        }
        temp2 = temp2->next;
      }
    }
    if (temp1 == NULL)
      temp3->next = temp2;
    else
      temp3->next = temp1;
    return p1;
  }
}

int main() {
  NODE *Head_1;
  Head_1 = NULL;
  Head_1 = create(Head_1, 10);
  Head_1 = insert_at_end(Head_1, 20);
  Head_1 = insert_at_end(Head_1, 30);
  Head_1 = insert_at_beg(Head_1, 0);
  display(Head_1);
  NODE *Head_2;
  Head_2 = NULL;
  Head_2 = create(Head_2, 40);
  Head_1 = merge(Head_1, Head_2);
  display(Head_1);
  if (search(Head_1, 50)) {
    cout << "found";
  } else
    cout << "Not Found";
  return 0;
}