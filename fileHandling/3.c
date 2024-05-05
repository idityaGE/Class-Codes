#include<stdio.h>
int main(){
  FILE *fp;
  fp = fopen("test.txt", "w");
  char name[20], branch[20];
  int age;
  printf("Enter your name: ");
  scanf("%s", name);
  printf("Enter your branch: ");
  scanf("%s", branch);
  printf("Enter your age: ");
  scanf("%d", &age);
  fprintf(fp, "Name: %s\nBranch: %s\nAge: %d\n", name, branch, age); // fprintf() or fputs() writes the data to the file 
  fclose(fp);
  return 0;
}