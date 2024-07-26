//? PROBLEM: Write a program in C++ that computes the total GST on any given purchase price. Assume the state GST is 4 percent and the county GST is 2 percent.Display the purchase price, state tax, county tax, and total tax amounts on the screen.

#include <iostream>
using namespace std;
int main()
{
  const double STATE_GST_RATE = 0.04;
  const double COUNTY_GST_RATE = 0.02;

  double purchasePrice;

  cout << "Enter the purchase price: ";
  cin >> purchasePrice;

  double stateTax = purchasePrice * STATE_GST_RATE;

  double countyTax = purchasePrice * COUNTY_GST_RATE;

  double totalTax = stateTax + countyTax;

  cout << "Purchase Price: $" << purchasePrice << endl;
  cout << "State Tax (4%): $" << stateTax << endl;
  cout << "County Tax (2%): $" << countyTax << endl;
  cout << "Total Tax: $" << totalTax << endl;
}
