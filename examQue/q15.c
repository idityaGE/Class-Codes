#include <stdio.h>

int main()
{
  int a = 5;
  int b = 4;
  int arr1[] = {1, 2, 3, 4, 5};
  int arr2[] = {6, 7, 8, 9};
  int mergedArr[a + b];
  int i, j, k;
  i = j = k = 0;
  while (i < a)
  {
    mergedArr[k++] = arr1[i++];
  }
  while (j < b)
  {
    mergedArr[k++] = arr2[j++];
  }
  for (int i = 0; i < a + b; i++)
  {
    printf("%d ", mergedArr[i]);
  }
  return 0;
}