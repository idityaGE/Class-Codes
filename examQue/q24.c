#include <stdio.h>
#include <stdlib.h>

int findLargest(int *array, int size)
{
  int largest = array[0];
  for (int i = 1; i < size; i++)
  {
    if (array[i] > largest)
    {
      largest = array[i];
    }
  }
  return largest;
}

int main()
{
  int size = 20;

  // Allocate memory dynamically for the array
  int *array = (int *)malloc(size * sizeof(int));
  if (array == NULL)
  {
    printf("Memory allocation failed.\n");
    return 1;
  }

  // Input the elements of the array
  printf("Enter %d integers:\n", size);
  for (int i = 0; i < size; i++)
  {
    scanf("%d", &array[i]);
  }

  // Find the largest number in the array
  int largest = findLargest(array, size);

  // Output the result
  printf("The largest number is: %d\n", largest);

  // Free dynamically allocated memory
  free(array);

  return 0;
}
