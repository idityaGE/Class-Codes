#include <stdio.h>
#include "arrFun.c"

float medianArr(int arr[], int n)
{
  bubbleShort(arr, n);
  if (n % 2 == 0)
  {
    return (float)(arr[n / 2 - 1] + arr[n / 2]) / 2;
  }
  else
  {
    return (float)arr[n / 2];
  }
}

int main()
{
  int n;

  printf("Enter the number of elements in the array: ");
  scanf("%d", &n);

  int arr[n];

  readArr(arr, n);

  float median = medianArr(arr, n);

  printf("Median of Arr = %.2f", median);
  return 0;
}