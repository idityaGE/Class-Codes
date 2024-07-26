#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
  FILE* fp;
  fp = fopen("test.txt", "r");
  char name[20], branch[20];
  int age;
  while(!feof(fp)){ // feof() returns 1 if the end of file is reached, otherwise 0
    fscanf(fp, "Name: %s\nBranch: %s\nAge: %d\n", name, branch, &age); // fscanf() or fgets() reads the data from the file
    if(!strcmp(name, "") && !strcmp(branch, "") && age == 0) break; // strcmp() returns 0 if the strings are equal
    printf("%s ",name);
    printf("%s ",branch);
    printf("%d",age);
    printf("\n");
    printf("Name: %s\nBranch: %s\nAge: %d\n", name, branch, age);
  }
  // fscanf(fp, "Name: %s\nBranch: %s\nAge: %d\n", name, branch, &age);
  // printf("Name: %s\nBranch: %s\nAge: %d\n", name, branch, age);
  fclose(fp);
  return 0;
}