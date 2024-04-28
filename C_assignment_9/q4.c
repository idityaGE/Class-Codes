// Q4- WAP in c to store the details of books such as Id, ISBN, title, publisher and price.

#include <stdio.h>
#include <string.h>

struct Book {
    int id;
    char isbn[20];
    char title[100];
    char publisher[100];
    float price;
};

int main() {
    struct Book book1;
    printf("Enter the id of the book: ");
    scanf("%d", &book1.id);
    printf("Enter the ISBN of the book: ");
    scanf("%s", book1.isbn);
    printf("Enter the title of the book: ");
    scanf("%s", book1.title);
    printf("Enter the publisher of the book: ");
    scanf("%s", book1.publisher);
    printf("Enter the price of the book: ");
    scanf("%f", &book1.price);

    printf("Book details:\n");
    printf("ID: %d\n", book1.id);
    printf("ISBN: %s\n", book1.isbn);
    printf("Title: %s\n", book1.title);
    printf("Publisher: %s\n", book1.publisher);
    printf("Price: %.2f\n", book1.price);

    return 0;
}