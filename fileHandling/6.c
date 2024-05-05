#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Book_data
{
  int id, isbn;
  char title[50], pub[50];
  float price;
} Book;
int main()
{
  Book b1;
  FILE *fptr = fopen("data.bin", "rb");

  fread(&b1, sizeof(Book), 1, fptr); // fread() reads the data from the file
  // syntax: fread(address_of_data, size_of_data, number_of_data, file_pointer)
  printf("ID=%d, title=%s, pub=%s, isbn=%d, price=%f", b1.id, b1.title, b1.pub, b1.isbn, b1.price);

  fclose(fptr);
}