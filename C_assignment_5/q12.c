#include <stdio.h>
#include <math.h>
#define MAX_DEGREE 100

void readPolynomial(int degree, int poly[])
{
    printf("Enter the coefficients of the polynomial from (x^%d to x^0):\n", degree);
    for (int i = degree; i >= 0; i--)
    {
        printf("Enter the coefficient of x^%d: ", i);
        scanf("%d", &poly[i]);
    }
}

void displayPolynomial(int degree, int poly[])
{
    printf("The polynomial is: ");
    for (int i = degree; i >= 0; i--)
    {
        printf("%dx^%d", poly[i], i);
        if (i > 0)
        {
            printf(" + ");
        }
    }
}

void addPolynomials(int degree, int poly1[], int poly2[], int result[])
{
    for (int i = 0; i <= degree; i++)
    {
        result[i] = poly1[i] + poly2[i];
    }
}

int evaluatePolynomial(int degree, int poly[], int x)
{
    int result = 0;
    for (int i = degree; i >= 0; i--)
    {
        result += poly[i] * pow(x, i);
    }
    return result;
}

void comparePolynomials(int degree, int poly1[], int poly2[], int x)
{
    int value1 = evaluatePolynomial(degree, poly1, x);
    int value2 = evaluatePolynomial(degree, poly2, x);
    if (value1 == value2)
    {
        printf("Both polynomial equations are equal at x = %d\n", x);
    }
    else
    {
        printf("Polynomial equations is not equal at x = %d\n", x);
    }
}

int main()
{
    int degree;
    int poly1[MAX_DEGREE], poly2[MAX_DEGREE], result[MAX_DEGREE], x;

    printf("Enter the degree of the polynomial: ");
    scanf("%d", &degree);

    readPolynomial(degree, poly1);
    readPolynomial(degree, poly2);

    printf("First polynomial: ");
    displayPolynomial(degree, poly1);
    printf("\n");
    printf("Second polynomial: ");
    displayPolynomial(degree, poly2);

    printf("\nEnter the value of x for comparison: ");
    scanf("%d", &x);

    comparePolynomials(degree, poly1, poly2, x);

    addPolynomials(degree, poly1, poly2, result);
    printf("\nResult of addition: ");
    displayPolynomial(degree, result);

    return 0;
}