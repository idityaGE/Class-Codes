#include <iostream>
using namespace std;

void printMatrix(int **arr, int r, int c)
{
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      cout << arr[i][j] << "  ";
    }
    cout << endl;
  }
}

void addMatrix(int **arr1, int **arr2, int r, int c)
{
  int **sum;
  sum = new int *[r];
  for (int i = 0; i < r; i++)
  {
    sum[i] = new int[c];
  }
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      sum[i][j] = arr1[i][j] + arr2[i][j];
    }
  }
  cout << "Sum of Diagonal and simple Matrix :" << endl;
  printMatrix(sum, r, c);
}

void readMatrix(int **arr, int r, int c)
{
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      cout << "Enter the element of (" << i << "," << j << ") :";
      cin >> arr[i][j];
    }
  }
}

// Diagonal Matrix
int main()
{
  int r, c;
  cout << "Enter the number of rows and columns : ";
  cin >> r >> c;
  // Diagonal Matrix
  int *dArr = new int[r];
  for (int i = 0; i < r; i++)
  {
    dArr[i] = 1;
  }

  // Simple Sqaure Matrix
  int **sArr;
  int **sum;
  sArr = new int *[r];
  sum = new int *[r];
  for (int i = 0; i < r; i++)
  {
    sArr[i] = new int[c];
    sum[i] = new int[c];
  }
  readMatrix(sArr, r, c);

  cout << "Diagonal Matrix" << endl;
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < r; j++)
    {
      if (i == j)
      {
        cout << 1 << "  ";
      }
      else
      {
        cout << 0 << "  ";
      }
    }
    cout << endl;
  }

  cout << "Simple Matrix" << endl;
  printMatrix(sArr, r, c);

  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      if (i == j)
        sum[i][j] = sArr[i][j] + dArr[i];
      else
        sum[i][j] = sArr[i][j];
    }
  }

  cout << "Sum of Diagonal and Simple Matrix: " << endl;
  printMatrix(sum, r, c);

  return 0;
}