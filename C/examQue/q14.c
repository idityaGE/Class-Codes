#include <stdio.h>
int result(int n)
{
  int num = n, last, first;
  last = num % 10;
  while (n != 0)
  {
    int rem = n % 10;
    first = rem;
    n /= 10;
  }
  return first + last;
}

int main()
{
  int n;
  printf("Enter the number : ");
  scanf("%d", &n);
  printf("%d", result(n));

  return 0;
}