#include <iostream>
using namespace std;

struct row {
  char oper;
  int prec;
  int asso;
};

struct Table {
 private:
  int size;
  int top;
  row *s;

 public:
  Table(int size) {
    this->size = size;
    top = -1;
    s = new row[size];
  }

  void push(char oper, int prec, int asso) {
    if (top == size - 1) {
      cout << "Table is Full" << endl;
    } else {
      top++;
      s[top].oper = oper;
      s[top].prec = prec;
      s[top].asso = asso;
    }
  }

  row pop() {
    row x;
    if (top == -1) {
      cout << "Table is empty" << endl;
    } else {
      x = s[top];
      top--;
    }
    return x;
  }

  row peek(int index) {
    if (index < 0 || index > size - 1 || index > top) {
      cout << "Invalid Index" << endl;
      return s[0];
    } else {
      return s[index];
    }
  }

  row getOper(char oper) {
    for (int i = 0; i <= top; i++) {
      if (s[i].oper == oper) {
        return s[i];
      }
    }
    return s[0];
  }

  bool isEmpty() {
    return top == -1;
  }

  bool isFull() {
    return top == size - 1;
  }

  void display() {
    cout << "Operator | Precedence | Associativity" << endl;
    for (int i = top; i >= 0; i--) {
      cout << "   " << s[i].oper << "     |      " << s[i].prec << "     |     " << s[i].asso << endl;
    }
  }
};

void push_table(Table &t) {
  t.push('+', 1, 0);
  t.push('-', 1, 0);
  t.push('*', 2, 0);
  t.push('/', 2, 0);
  t.push('^', 3, 1);
}

int main() {
  // 0 --> Left to Right, 1 --> Right to Left
  Table t(10);
  push_table(t);
  t.display();
  cout << endl;

  return 0;
}