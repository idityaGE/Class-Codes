#include <stdio.h>
int isPalindrome(int n) {
  int reversedN = 0, originalN = n;
  while (n != 0) {
    int remainder = n % 10;
    reversedN = reversedN * 10 + remainder;
    n /= 10;
  }
  return originalN == reversedN;
}
int main() {
  int n;
  printf("Enter a number: ");
  scanf("%d", &n);
  if (isPalindrome(n)) {
    printf("%d is a palindrome number\n", n);
  } else {
    printf("%d is not a palindrome number\n", n);
  }
  return 0;
}