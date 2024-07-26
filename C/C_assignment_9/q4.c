// Q4- WAP in c to store the details of books such as Id, ISBN, title, publisher and price.
#include <stdio.h>
#include <string.h>
struct Book
{
    int id;
    char isbn[20];
    char title[100];
    char publisher[100];
    float price;
};

int main()
{
    struct Book books;
    printf("Enter details for book :\n");
    printf("ID: ");
    scanf("%d", &books.id);
    printf("ISBN: ");
    scanf("%s", books.isbn);
    printf("Title: ");
    scanf(" %[^\n]s", books.title); // %[^\n]s is used to take input with spaces it will take input until newline is encountered
    printf("Publisher: ");
    scanf(" %[^\n]s", books.publisher);
    printf("Price: ");
    scanf("%f", &books.price);

    printf("\nDetails of Books:\n");
    printf("Book %d:\n");
    printf("ID: %d\n", books.id);
    printf("ISBN: %s\n", books.isbn);
    printf("Title: %s\n", books.title);
    printf("Publisher: %s\n", books.publisher);
    printf("Price: %.2f\n", books.price);
    printf("\n");
    return 0;
}
