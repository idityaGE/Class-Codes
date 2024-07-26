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
  FILE *fptr = fopen("data.bin", "wb");

  b1.id = 1001; 
  strcpy(b1.title, "C Programming"); // strcpy() copies the second string to the first string
  strcpy(b1.pub, "TMH"); 
  b1.isbn = 90898788;
  b1.price = 100.0;
  fwrite(&b1, sizeof(Book), 1, fptr); // fwrite() writes the data to the file
  // syntax: fwrite(address_of_data, size_of_data, number_of_data, file_pointer)
  // fwrite() returns the number of data written to the file

  fclose(fptr);
}