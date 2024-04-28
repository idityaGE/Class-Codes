// Q3. Write a C program to traverse an array in reverse order using pointer.

#include <stdio.h>
void reverse(int *ptr, int n) {
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", *(ptr + i));
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Array in reverse order: ");

    reverse(arr, n);

    return 0;
}