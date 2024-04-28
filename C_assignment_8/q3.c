// q3. WAP in c to swap two numbers using the functions

#include <stdio.h>
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(){
    int a,b;
    printf("Enter the first number : ");
    scanf("%d",&a);
    printf("Enter the second number : ");
    scanf("%d",&b);
    printf("Before swapping a = %d and b = %d\n",a,b);
    swap(&a,&b);
    printf("After swapping a = %d and b = %d\n",a,b);
    return 0;
}