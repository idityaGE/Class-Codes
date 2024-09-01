#include <iostream>
using namespace std;

struct Stack {
 private:
  int size;
  int top;
  int *S;

 public:
  void create(int s);
  void push(int x);
  int pop();
  int peek(int index);
  int isFull();
  int isEmpty();
  void display();
};

void Stack::create(int s) {
  S = new int[s];
  size = s;
  top = -1;
}

void Stack::push(int x) {
  
}

int Stack::pop(){
  
}

int main() {
  return 0;
}