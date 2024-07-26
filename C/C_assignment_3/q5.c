#include <stdio.h>

int main()
{
    int math, phy, chem;
    printf("Enter marks in Maths: ");
    scanf("%d", &math);
    printf("Enter marks in Physics: ");
    scanf("%d", &phy);
    printf("Enter marks in Chemistry: ");
    scanf("%d", &chem);

    if (math >= 65 && phy >= 55 && chem >= 50 && (math + phy + chem) >= 190)
    {
        printf("Eligible");
    }
    else if ((math + phy) >= 140)
    {
        printf("Eligible");
    }
    else
    {
        if (math < 65)
        {
            printf("Not eligible as marks in Maths are less than 65");
        }
        else if (phy < 55)
        {
            printf("Not eligible as marks in Physics are less than 55");
        }
        else if (chem < 50)
        {
            printf("Not eligible as marks in Chemistry are less than 50");
        }
        else if ((math + phy + chem) < 190)
        {
            printf("Not eligible as total marks are less than 190");
        }
    }

    return 0;
}