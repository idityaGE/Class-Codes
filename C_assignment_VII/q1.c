// Q1. Write a C program to create, initialize and use pointers.

#include <stdio.h>

int main() {
    int num = 10; // Declare and initialize an integer variable
    int *ptr; // Declare a pointer variable

    ptr = &num; // Assign the address of 'num' to the pointer

    printf("Value of num: %d\n", num);
    printf("Address of num: %p\n", &num);
    printf("Value of ptr: %p\n", ptr);
    printf("Value pointed by ptr: %d\n", *ptr);

    return 0;
}