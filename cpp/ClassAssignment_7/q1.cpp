/*
  Write a program in C++ to find all the tokens in a given string separated by space.
  Convert string to integers if any.
*/
#include <iostream>
#include <string>
using namespace std;

pair<string *, int> tokenize(string str) {
  int n = str.length();
  string *tokens = new string[n];
  int i = 0;
  int j = 0;
  while (i < str.length()) {
    if (str[i] == ' ') {
      i++;
      continue;
    }
    while (i < str.length() && str[i] != ' ') {
      tokens[j] += str[i];
      i++;
    }
    j++;
  }
  return {tokens, j};
}

bool isOperator(char c) {
  return c == '+' || c == '-' || c == '*' || c == '/';
}

int caculate(int a, int b, char op) {
  switch (op) {
    case '+':
      return a + b;
    case '-':
      return a - b;
    case '*':
      return a * b;
    case '/':
      return a / b;
    default:
      return 0;
  }
}

int postfixEvaluation(string postfix) {
  pair<string *, int> tokens = tokenize(postfix);
  cout << "Tokens: | ";
  for (int i = 0; i < tokens.second; i++)
    cout << tokens.first[i] << " | ";
  cout << endl;
  int *stack = new int[tokens.second];
  int top = -1;
  for (int i = 0; i < tokens.second; i++) {
    if (isOperator(tokens.first[i][0])) {
      int b = stack[top--];
      int a = stack[top--];
      stack[++top] = caculate(a, b, tokens.first[i][0]);
    } else
      stack[++top] = stoi(tokens.first[i]);
  }
  if (top != 0) {
    cout << "Invalid postfix expression" << endl;
    return -1;
  }
  return stack[top];
}

int main() {
  string postfix = "25 38 * 5 4 *";
  cout << "Postfix: " << postfix << endl;
  cout << "Result: " << postfixEvaluation(postfix) << endl;
  return 0;
}