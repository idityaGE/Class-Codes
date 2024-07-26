#include <iostream>
using namespace std;

int main()
{
  // Decimal to Binary
  // int num;
  // cout << "Enter the Num: ";
  // cin >> num;
  // int rem, ans = 0, mul = 1;
  // while (num > 0)
  // {
  // // rem = num % 2;
  //   rem = num & 1;
  //  // num /= 2;
  //   num = num >> 1;   // --> num/2**1
  //   ans += rem * mul; //
  //   mul *= 10;
  // }
  // cout << ans;

  // Binary to Decimal
  // int bin;
  // cout << "Enter the Binary Num: ";
  // cin >> bin;
  // int rem, ans = 0, mul = 1;
  // while (bin > 0)
  // {
  //   rem = bin % 10;
  //   bin /= 10;
  //   ans = rem * mul + ans;
  //   mul = mul << 1;
  // }
  // cout << ans;

  // Decimal to Ocatal
  int num;
  cout << "Enter the Num: ";
  cin >> num;
  int rem, ans = 0, mul = 1;
  while (num > 0)
  {
    rem = num % 8;
    num /= 8;
    ans += rem * mul;
    mul *= 10;
  }
  cout << ans;
}