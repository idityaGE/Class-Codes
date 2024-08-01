#include "matrix_fn.h"
#include <iostream>
using namespace std;

void read_matrix(int **mat, int r)
{
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < r; j++)
    {
      cout << "Enter the element of (" << i << "," << j << ") :";
      cin >> mat[i][j];
    }
  }
}

void display_matrix(int **mat, int r)
{
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < r; j++)
    {
      cout << mat[i][j] << "  ";
    }
    cout << endl;
  }
}