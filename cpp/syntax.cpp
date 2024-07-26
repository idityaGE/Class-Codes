#include <iostream>
using namespace std;

int main()
{
  //! data types
  // int a,b;
  // bool x = true; // 1
  // float c = 3.14;
  // double d = 3.14;
  // char e = 'A';
  // string f = "Hello World";
  // cout<<f<<endl;
  // cout<<"Enter two numbers: ";
  // cin>>a>>b;
  // cout<<"Sum of two No: "<<a+b<<endl;

  //! operators
  // int a = 66;  // ASCII --> 66 = 'B'
  // char b = 'B';
  // if (a == b) {
  //   cout<<"Equal"<<endl;
  // } else {
  //   cout<<"Not Equal"<<endl;
  // }
  // cout<<b<<endl;

  //! if else
  // int package;
  // cout << "Enter the number of packages: ";
  // cin >> package;
  // if (package >= 10)
  //   cout << "Accepted" << endl;
  // else if (package > 8)
  //   cout << "Not Sure" << endl;
  // else
  //   cout << "Rejected" << endl;

  //! switch case
  // char ch = 'x';
  // switch (ch)
  // {
  // case 'a':
  //   cout << "Vowel" << endl;
  //   break;
  // case 'e':
  //   cout << "Vowel" << endl;
  //   break;
  // case 'i':
  //   cout << "Vowel" << endl;
  //   break;
  // case 'o':
  //   cout << "Vowel" << endl;
  //   break;
  // case 'u':
  //   cout << "Vowel" << endl;
  //   break;
  // default:
  //   cout << "Consonant" << endl;
  //   break;
  // }

  //! ternary operator
  // char ch = 'y';
  // cout << (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ? "Vowel" : "Consonant") << endl;

  //! loops
  // int i = 1;
  // while (i <= 10)
  // {
  //   cout << i << endl;
  //   i++;
  // }

  // for (int i = 1; i <= 10; i++)
  // {
  //   cout << "Hello" << endl;
  // }

  // int num;
  // cout << "Enter a number: ";
  // cin >> num;
  // for (int i = 1; i <= num; i++)
  // {
  //   if (i % 4 == 0)
  //     cout << i << endl;
  // }

  // for(char ch = 'Z'; ch >= 'A'; ch--) {
  //   cout<<ch<<" ";
  // }

  // for (int i = 220; i <= 730; i=i+7)
  // {
  //   cout<<i<<endl;
  // }

  // int n;
  // cout<<"Enter a number: ";
  // cin>>n;
  // int sum = 0;
  // for(int i=1; i<=n; i++){
  //   sum += i*i;
  // }
  // cout<<"Sum of squares: "<<sum<<endl;

  // int n;
  // cout << "Enter a number: ";
  // cin >> n;
  // int num = n;
  // int power;
  // cout << "Enter the power: ";
  // cin >> power;
  // for (int i = 1; i < power; i++)
  // {
  //   num = num * n;
  // }
  // cout << "Power of 5: " << num << endl;

  //! Fibonacci number
  // int n;
  // cout << "Enter a number: ";
  // cin >> n;
  // int a = 0, b = 1, c;
  // cout << a << endl << b << endl;
  // for (int i = 3; i <= n; i++)
  // {
  //   c = a + b;
  //   cout << c << endl;
  //   a = b;
  //   b = c;
  // }

  //!
  // int count = 1;
  // for (int i = 0; i <= 5; i++)
  // {
  //   for (int j = 0; j <= 5; j++)
  //   {
  //     cout << count++ << "    ";
  //   }
  //   cout << endl;
  // }

  //!
  for (int i = 1; i <= 5; i++)
  {
    for (int j = 5; j >= 5 - (i - 1); j--)
    {
      cout << j << " ";
    }
    cout << endl;
  }
}
