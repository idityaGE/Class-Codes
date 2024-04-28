// Q1- WAP in c to swap two complex numbers using the functions

#include <stdio.h>
void swapComplex(int *num1, int *num2) {
    int temp;
    // Swap the real parts
    temp = num1[0];
    num1[0] = num2[0];
    num2[0] = temp;
    // Swap the imaginary parts
    temp = num1[1];
    num1[1] = num2[1];
    num2[1] = temp;
}

int main() {
    int complexNum1[2];
    int complexNum2[2];

    printf("Enter the real and imaginary parts of complex number 1: ");
    scanf("%d %d", &complexNum1[0], &complexNum1[1]);

    printf("Enter the real and imaginary parts of complex number 2: ");
    scanf("%d %d", &complexNum2[0], &complexNum2[1]);

    printf("Original complex numbers:\n");
    printf("Complex number 1: %d + %di\n", complexNum1[0], complexNum1[1]);
    printf("Complex number 2: %d + %di\n", complexNum2[0], complexNum2[1]);

    swapComplex(complexNum1, complexNum2);

    printf("Swapped complex numbers:\n");
    printf("Complex number 1: %d + %di\n", complexNum1[0], complexNum1[1]);
    printf("Complex number 2: %d + %di\n", complexNum2[0], complexNum2[1]);
}