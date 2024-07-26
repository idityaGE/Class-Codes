// Q1- WAP in c to develop a function to compute the sum of n natural numbers using recursion.

#include <stdio.h>
    int
    nthsum(int n) {
    if (n == 1) {
        return 1;
    }
    return n + nthsum(n - 1);
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Sum of first %d natural numbers is %d\n", n, nthsum(n));
    return 0;
}