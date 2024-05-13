#include <stdio.h>
#include <math.h>

int main() {
  int a,b,c;
  printf("Enter 3 sides of triangle: ");
  scanf("%d %d %d", &a, &b, &c);
  if(a+b>c && b+c>a && c+a>b) {
    printf("Triangle is valid\n");
  } else {
    printf("Triangle is not valid\n");
  }
  int s = (float)(a+b+c)/2;
  float area = sqrt(s*(s-a)*(s-b)*(s-c));
  printf("Area of triangle: %.2f sq. unit", area);
  
  return 0;
}