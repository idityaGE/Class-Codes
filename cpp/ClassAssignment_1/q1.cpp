//? PROBLEM: The Flipkart generates 62 percent of total sales. Based on that percentage, write a program in C++ that will predict how much the Flipkart will generate if the company has 46 lakhs in sales this year.Display the result on the screen.

#include <iostream>
    using namespace std;

int main()
{
  const double profit_margin = 0.62;
  double sales = 46.0;
  double profit_gen;
  profit_gen = sales * profit_margin;
  cout << "Profit generated : " << profit_gen << " lakhs";
}