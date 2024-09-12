#include <iostream>
using namespace std;

struct NODE {
  char data;
  NODE *next;
};

struct stack {
 private:
  NODE *top;

 public:
  stack() {
    top = nullptr;
  }

  void push(char data) {
    NODE *t = new NODE;
    t->data = data;
    t->next = top;
    top = t;
  }

  char pop() {
    if (top == nullptr) {
      cout << "stack is empty" << endl;
    } else {
      char topdata;
      NODE *t = top;
      top = top->next;
      topdata = t->data;
      delete t;
      return topdata;
    }
  }

  bool isEmpty() {
    return top == nullptr;
  }
};

bool syntax_check(string str) {
  stack st;
  int i = 0;
  while (str[i] != '\0') {
    if (str[i] == '(')
      st.push(str[i]);
    else if (str[i] == ')')
      if (!st.isEmpty())
        st.pop();
      else
        return false;
    i++;
  }
  return st.isEmpty();
}

int main() {
  string str = "a + b ( a / b ) + ( c + ( d + f ) + 2 ) )";
  if (syntax_check(str))
    cout << "Correct" << endl;
  else
    cout << "Not Correct" << endl;
  return 0;
}