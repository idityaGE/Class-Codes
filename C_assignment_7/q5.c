// Q5. Write a C program to Create an array of pointers to store addresses of five different integer numbers.

#include <stdio.h>

int main() {
    int num1 = 10, num2 = 20, num3 = 30, num4 = 40, num5 = 50;
    int *ptr[5];
    ptr[0] = &num1;
    ptr[1] = &num2;
    ptr[2] = &num3;
    ptr[3] = &num4;
    ptr[4] = &num5;
    for (int i = 0; i < 5; i++) {
        printf("Address of num%d: %d\n", i + 1, ptr[i]);
    }
    return 0;
}