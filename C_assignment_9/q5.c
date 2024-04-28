// Q5- WAP in c to sort the records of books (develop in question 4) based in the price.

#include <stdio.h>
#include <string.h>
struct Book {
    int id;
    char isbn[20];
    char title[100];
    char publisher[100];
    float price;
};
void sortBooks(struct Book books[], int n) {
    struct Book temp; // Temporary variable to store the book while swapping
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (books[i].price > books[j].price) {
                temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }
}
int main() {
    int n;
    printf("Enter the number of books: ");
    scanf("%d", &n);
    struct Book books[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the id of the book: ");
        scanf("%d", &books[i].id);
        printf("Enter the ISBN of the book: ");
        scanf("%s", books[i].isbn);
        printf("Enter the title of the book: ");
        scanf("%s", books[i].title);
        printf("Enter the publisher of the book: ");
        scanf("%s", books[i].publisher);
        printf("Enter the price of the book: ");
        scanf("%f", &books[i].price);
    }
    sortBooks(books, n);
    printf("Book details:\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d\n", books[i].id);
        printf("ISBN: %s\n", books[i].isbn);
        printf("Title: %s\n", books[i].title);
        printf("Publisher: %s\n", books[i].publisher);
        printf("Price: %.2f\n", books[i].price);
    }
    return 0;
}