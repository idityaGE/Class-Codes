// Q4. Write a C program to create dynamic arrays using callac() and malloc() library functions.

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Using calloc()
    // syntax: ptr = (cast-type*)calloc(n, size);
    // 'n' is the number of blocks to be allocated and 'size' is the size of each block. The function returns a pointer to the first byte of the allocated space if successful, or NULL if the function did not succeed.
    // it initializes each block with a default value of zero.
    int *arr1 = (int *)calloc(n, sizeof(int)); 
    if (arr1 == NULL) {
        printf("Memory allocation failed\n");
        exit(1); // exit the program
    }

    // Using malloc()
    // syntax: ptr = (cast-type*)malloc(n * size);
    // 'n' is the number of blocks to be allocated and 'size' is the size of each block. The function returns a pointer to the first byte of the allocated space if successful, or NULL if the function did not succeed.
    // it does not initialize the memory allocated.
    int *arr2 = (int *)malloc(n * sizeof(int));
    if (arr2 == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    printf("Memory allocated successfully\n");

    // what to do with the allocated memory?
    // you can use the allocated memory to store values, just like you would with a normal array.
    // for example, you can take input from the user and store it in the allocated memory.
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
        scanf("%d", &arr2[i]);
    }

    // you can also access and print the values stored in the allocated memory.
    printf("Elements stored in arr1:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    printf("Elements stored in arr2:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr2[i]);
    }

    // free is used to deallocate the memory allocated using calloc() and malloc().
    // syntax: free(ptr);
    // 'ptr' is the pointer to the memory block that needs to be deallocated.
    // it is a good practice to free the memory after you are done using it to avoid memory leaks.
    free(arr1);
    free(arr2);

    return 0;
}