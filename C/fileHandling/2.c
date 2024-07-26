#include<stdio.h>

int main(){
  FILE* fp;
  fp = fopen("test.txt", "r"); // types of modes: r, w, a, r+, w+, a+ (r+ -> read and write) (w+ -> write and read) (a+ -> append and read)
  char c;
  c =getc(fp);
  printf("%c\n", c);
  c =getc(fp);
  printf("%c\n", c);
  c =getc(fp);
  printf("%c\n", c);
  fclose(fp);
}