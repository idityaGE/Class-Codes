// q1. WAP in c to develop a function to compute the factorial of any number.

#include<stdio.h>
int Factorial(int n){
    if(n==0){
        return 1;
    }
    return n*Factorial(n-1);
}
int main(){
    int n;
    printf("Enter the number: ");
    scanf("%d",&n);
    printf("Factorial of %d is %d\n",n,Factorial(n));
    return 0;
}