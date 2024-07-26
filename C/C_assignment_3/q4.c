#include <stdio.h>

int main()
{
    int choice;
    float num1, num2;

    while (1)
    {
        printf("1. Add\n2. Subtract\n3. Multiply\n4. Divide\n0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter two numbers: ");
            scanf("%f %f", &num1, &num2);
            printf("Result: %.2f\n", num1 + num2);
            break;
        case 2:
            printf("Enter two numbers: ");
            scanf("%f %f", &num1, &num2);
            printf("Result: %.2f\n", num1 - num2);
            break;
        case 3:
            printf("Enter two numbers: ");
            scanf("%f %f", &num1, &num2);
            printf("Result: %.2f\n", num1 * num2);
            break;
        case 4:
            printf("Enter two numbers: ");
            scanf("%f %f", &num1, &num2);
            if (num2 == 0)
            {
                printf("Cannot divide by zero.\n");
            }
            else
            {
                printf("Result: %.2f\n", num1 / num2);
            }
            break;
        case 0:
            printf("Exiting program.\n");
            return 0;
        default:
            printf("Invalid choice. Please enter a number between 0 and 4.\n");
            break;
        }
    }

    return 0;
}