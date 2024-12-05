/*
?  Write a C++ Program to evaluate a given postfix expression using stack.
*/

// #include <bits/stdc++.h>
#include <cmath>
#include <iostream>
#include <string>
#include <unordered_map>

#include "q4.cpp"
using namespace std;

bool isOperand(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

int evaluate_postfix(string postf, unordered_map<char, int>& values) {
  stack st; // from "q4.cpp"
  for (int i = 0; i < postf.size(); i++) {
    char c = postf[i];
    if (isOperand(c)) st.push(values[c]);
    else {
      int op2 = st.pop(); 
      int op1 = st.pop(); 
      int result;
      if      (c == '+')  result = op1 + op2;
      else if (c == '-')  result = op1 - op2;
      else if (c == '*')  result = op1 * op2;
      else if (c == '/')  result = op1 / op2;
      else if (c == '^')  result = pow(op1, op2);
      else {
        cout << "Undefined operator: " << c << endl;
        return -1;
      }
      st.push(result);
    }
  }
  return int(st.peek_top());
}

int main() {
  string postfix = "abc*+";
  unordered_map<char, int> values;
  values['a'] = 5;
  values['b'] = 3;
  values['c'] = 2;
  int result = evaluate_postfix(postfix, values);
  cout << "Result : " << result << endl;
  return 0;
}
