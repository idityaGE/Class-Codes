#include <stdio.h>
#include <string.h>

int main()
{
    char name[50];
    printf("Enter your name: ");
    // fgets(name, sizeof(name), stdin);

    int i = 0;
    while (i < 50) // this method is more efficient than fgets because it doesn't store '\n' in the string
    {
        char c = getchar();
        if (c == '\n')
        {
            name[i] = '\0';
            break;
        }
        name[i++] = c;
    }

    i = 0;
    while (name[i] != '\0')
    {
        if (name[i] >= 'a' && name[i] <= 'z')
        {
            name[i] -= 32; // Subtracting 32 converts lowercase to uppercase in ASCII
        }
        i++;
    }

    if (strlen(name) <= 0)
    {
        printf("You didn't enter any name\n");
    }
    else
    {
        printf("Your name in uppercase: %s\n", name);
    }
}