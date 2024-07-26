#include <stdio.h>
int swap(int *n1, int *n2)
{
  int temp = *n1;
  *n1 = *n2;
  *n2 = temp;
}

void bubbleShort(int arr[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        swap(&arr[j], &arr[j + 1]);
      }
    }
  }
}

void readArr(int arr[], int n)
{
  printf("Enter the elements of the array:\n");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }
}

void printArr(int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
}

int main()
{
  int n;

  printf("Enter the number of elements in the array: ");
  scanf("%d", &n);

  int arr[n];

  readArr(arr, n);

  printArr(arr, n);

  printf("\n");

  bubbleShort(arr, n);

  printArr(arr, n);

  return 0;
}