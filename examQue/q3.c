#include <stdio.h>
int valueOfy(int x, int m, int c) {
  return m*x + c;
}

int main()
{
  int y, m, x, c;
  printf("Formate of equation: y = mx + c\n");
  printf("Enter y: ");
  scanf("%d", &y);
  printf("Enter x: ");
  scanf("%d", &x);
  printf("Enter c: ");
  scanf("%d", &c);
  //slope
  m = (float)(y - c) / x;
  printf("Slope of the line: %d\n", m);

  int result = valueOfy(x, m, c);
  printf("Value of y: %d\n", result);


  return 0;
}