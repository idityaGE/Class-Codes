// q2. WAP in c to develop a function to compute the power of any given number.

#include <stdio.h>
int Power(int x, int n){
    if(n==0){
        return 1;
    }
    return x*Power(x,n-1);
}
int main(){
    int x,n;
    printf("Enter the number : ");
    scanf("%d",&x);
    printf("Enter the power : ");
    scanf("%d",&n);
    printf("%d raised to the power %d is %d\n",x,n,Power(x,n));
    return 0;
}