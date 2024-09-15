#include <string.h>

#include <iostream>

#include "q4.cpp"
#include "q5.cpp"
using namespace std;

bool isOperand(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

string inf_to_postf(string inf) {
  stack st;
  Table t(10);
  push_table(t);
  t.display();
  string postf;
  int i = 0;
  while (inf[i] != '\0') {
    if (isOperand(inf[i])) postf.push_back(inf[i]);
    else {
      if (inf[i] == '(') st.push(inf[i]);
      else if (inf[i] == ')') {
        while (!st.isEmpty() && st.peek_top() != '(') postf.push_back(st.pop());
        st.pop();  // pop '('
      } else {
        row r1 = t.getOper(inf[i]);
        while (!st.isEmpty() && st.peek_top() != '(') {
          row r2 = t.getOper(st.peek_top());
          if ((r1.prec < r2.prec) || (r1.prec == r2.prec && r1.asso == 0)) postf.push_back(st.pop());
          else break;
        }
        st.push(inf[i]);
      }
    }
    i++;
  }
  while (!st.isEmpty()) postf.push_back(st.pop());
  return postf;
}

int main() {
  string infix = "a+b*c-(d/e+f*g*h)-i+j^k^a+l";
  string postfix = inf_to_postf(infix);
  cout << "Postfix: " << postfix << endl;
  return 0;
}