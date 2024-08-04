#include <iostream>
using namespace std;
int powerOfn(int num, int power) {
  if (power == 1)
    return num;
  return powerOfn(num, power - 1) * num;
}

int main() {
  int num, power;
  cout << "Enter the Number and Power : ";
  cin >> num >> power;
  cout << num << " to the power " << power << " : " << powerOfn(num, power);
  return 0;
}