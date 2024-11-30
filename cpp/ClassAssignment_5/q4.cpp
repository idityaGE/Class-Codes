/*
?  Write a program in C++ to check whether the given expression 
?  have balanced parenthesis (consider all types of brackets).
*/

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

  char peek_top() {
    if (top == nullptr) {
      cout << "stack is empty" << endl;
    } else {
      return top->data;
    }
  }
};

bool syntax_check(string str) {
  stack st;
  int i = 0;
  while (str[i] != '\0') {
    if (str[i] == '(' || str[i] == '[' || str[i] == '{')
      st.push(str[i]);
    else if (str[i] == ')' || str[i] == ']' || str[i] == '}')
      if (!st.isEmpty()) {
        char c = st.pop();
        if (c == '(' && str[i] != ')' || c == '[' && str[i] != ']' || c == '{' && str[i] != '}')
          return false;
      } else
        return false;
    i++;
  }
  return st.isEmpty();
}

// int main() {
//   string str = "[ { a + b + ( a / b ) + ( c + ( d + f ) + 2 ) } ]";
//   if (syntax_check(str))
//     cout << "Syntax is correct" << endl;
//   else
//     cout << "Syntax is incorrect" << endl;
//   return 0;
// }