//? PROBLEM: Write a program in C++ that displays the following pattern on the screen.
//?         *
//?       * * *
//?     * * * * *
//?   * * * * * * *

#include <iostream>
using namespace std;

int main() {
  for (int i = 1; i <= 4; i++) {
    for (int j = 1; j <= 4 - i; j++)
      cout << "  ";

    for (int k = 1; k <= 2 * i - 1; k++)
      cout << "* ";

    cout << endl;
  }
}
