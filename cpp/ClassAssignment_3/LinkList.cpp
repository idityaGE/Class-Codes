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
    if (pos == 1) {
      p = insert_at_beg(p, data);
    } else {
      NODE *temp, *temp1;
      temp = p;
      for (int i = 1; i < pos - 1; i++) {
        if (temp->next != NULL)
          temp = temp->next;
        else {
          cout << "Position not found" << endl;
          delete temp, temp1;
          return p;
        }
      }
      temp1 = new NODE;
      temp1->data = data;
      temp1->next = temp->next;
      temp->next = temp1;
    }
  }
  return p;
}

NODE *insert_at_sorted_pos(NODE *p, int data) {
  if (p == NULL)
    p = create(p, data);
  else {
    sort(p);
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
      temp = temp->next;
    }
    temp1 = temp->next;
    temp->next = NULL;
    delete temp1;
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
    if (pos == 1) {
      p = delete_at_beg(p);
    } else {
      NODE *temp, *temp1;
      temp = p;
      for (int i = 1; i < pos - 1; i++) {
        if (temp->next != NULL)
          temp = temp->next;
        else {
          cout << "Position not found" << endl;
          delete temp, temp1;
          return p;
        }
      }
      temp1 = temp->next;
      temp->next = temp1->next;
      delete temp1;
    }
  }
  return p;
}

NODE *delete_at_data(NODE *p, int data) {
  if (p == NULL)
    cout << "List is empty" << endl;
  else {
    NODE *temp, *temp1;
    temp = p;
    while (temp->next != NULL && temp->next->data != data)
      temp = temp->next;
    if (temp->next == NULL)
      cout << "Data not found" << endl;
    else {
      temp1 = temp->next;
      temp->next = temp1->next;
      delete temp1;
    }
  }
  return p;
}

NODE *sort(NODE *p) {
  if (p == NULL)
    cout << "List is empty" << endl;
  else {
    NODE *temp1, *temp2;
    temp1 = p;
    while (temp1 != NULL) {
      temp2 = temp1->next;
      while (temp2 != NULL) {
        if (temp1->data > temp2->data) {
          int temp = temp1->data;
          temp1->data = temp2->data;
          temp2->data = temp;
        }
        temp2 = temp2->next;
      }
      temp1 = temp1->next;
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
    p1 = merge(p1, p2);
    p1 = sort(p1);
  }
  return p1;
}

int main() {
  NODE *Head_1;
  Head_1 = NULL;
  Head_1 = create(Head_1, 10);
  Head_1 = insert_at_end(Head_1, 20);
  Head_1 = insert_at_end(Head_1, 40);
  Head_1 = insert_at_end(Head_1, 30);
  Head_1 = insert_at_end(Head_1, 5);

  display(Head_1);

  Head_1 = sort(Head_1);

  display(Head_1);

  return 0;
}