#include <iostream>
using namespace std;

char upperCase(char name)
{
  int ans = name;
  if (ans >= 97 && ans <= 122)
  {
    ans -= 32;
  }
  return char(ans);
}

int main()
{
  char name;
  cout << "Enter the character : ";
  cin >> name;
  cout << "UpperCase : " << upperCase(name);
  return 0;
}