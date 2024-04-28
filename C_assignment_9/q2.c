// Q2- WAP in c to store comple x numbers and design functions to calculate sum,subtraction and multiplication of two complex numbers.

#include<stdio.h>
    int
    complexSum(int complexNum1[2], int complexNum2[2], int sum[2]){
    sum[0] = complexNum1[0] + complexNum2[0];
    sum[1] = complexNum1[1] + complexNum2[1];
    return 0;
}
int complexSub(int complexNum1[2], int complexNum2[2], int difference[2]){
    difference[0] = complexNum1[0] - complexNum2[0];
    difference[1] = complexNum1[1] - complexNum2[1];
    return 0;
}
int complexProd(int complexNum1[2], int complexNum2[2], int product[2]){
    // (a+bi)(c+di)=(ac-bd)+(ad+bc)i
    product[0] = complexNum1[0]*complexNum2[0] - complexNum1[1]*complexNum2[1];
    product[1] = complexNum1[0]*complexNum2[1] + complexNum1[1]*complexNum2[0];
    return 0;
}

int main(){
    int complexNum1[2];
    int complexNum2[2];
    int sum[2];
    int difference[2];
    int product[2];
    printf("Enter the real part of the first complex number: ");
    scanf("%d", &complexNum1[0]);
    printf("Enter the imaginary part of first the complex number: ");
    scanf("%d", &complexNum1[1]);
    printf("The first complex number is: %d + i%d\n", complexNum1[0], complexNum1[1]);

    printf("Enter the real part of the second complex number: ");
    scanf("%d", &complexNum2[0]);
    printf("Enter the imaginary part of the second complex number: ");
    scanf("%d", &complexNum2[1]);
    printf("The second complex number is: %d + i%d\n", complexNum2[0], complexNum2[1]);

    complexSum(complexNum1, complexNum2, sum);
    printf("The sum of the two complex numbers is: %d + i%d\n", sum[0], sum[1]);

    complexSub(complexNum1, complexNum2, difference);
    printf("The difference of the two complex numbers is: %d + i%d\n", difference[0], difference[1]);

    complexProd(complexNum1, complexNum2, product);
    printf("The product of the two complex numbers is: %d + i%d\n", product[0], product[1]);

    return 0;
}