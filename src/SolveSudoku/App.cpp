#include <iostream>

using namespace std;

#define N 9

bool isSafe(int Grid[N][N], int row, int column, int number)
{
  int start = row - row % 3, end = column - column % 3;

  for (int i = 0; i <= (N - 1); i++)
  {
    if (Grid[row][i] == number)
    {
      return false;
    }
    if (Grid[i][column] == number)
    {
      return false;
    }
  }

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (Grid[i + start][j + end] == number)
      {
        return false;
      }
    }
  }

  return true;
}

bool solve(int Grid[N][N], int row, int column)
{
  if (row == N - 1 && column == N)
  {
    return true;
  }

  if (column == N)
  {
    row++;
    column = 0;
  }

  if (Grid[row][column] > 0)
  {
    return solve(Grid, row, column + 1);
  }

  for (int number = 1; number <= N; number++)
  {
    if (isSafe(Grid, row, column, number))
    {
      Grid[row][column] = number;

      if (solve(Grid, row, column + 1))
      {
        return true;
      }
    }
    Grid[row][column] = 0;
  }

  return false;
}

int main()
{
  int Grid[N][N] = {{0, 0, 0, 7, 3, 0, 0, 4, 5},
                    {0, 0, 0, 0, 1, 4, 0, 2, 0},
                    {0, 2, 1, 0, 5, 6, 0, 0, 8},
                    {3, 6, 8, 0, 0, 0, 2, 0, 4},
                    {1, 9, 0, 4, 0, 5, 0, 0, 0},
                    {7, 0, 5, 0, 6, 0, 0, 1, 0},
                    {0, 0, 4, 3, 9, 7, 0, 6, 0},
                    {0, 0, 0, 0, 0, 8, 0, 0, 0},
                    {0, 0, 7, 0, 0, 0, 0, 0, 0}};

  cout << endl;

  if (solve(Grid, 0, 0))
  {
    for (int i = 0; i < N; i++)
    {
      if (i % 3 == 0 && i != 0)
      {
        cout << "---------|---------|---------" << endl;
      }
      for (int j = 0; j < N; j++)
      {
        if (j % 3 == 0 && j != 0)
        {
          cout << "|";
        }

        cout << " " << Grid[i][j] << " ";
      }
      cout << endl;
    }
  }
  else
  {
    cout << "Solusi tidak ditemukan." << endl;
  }
}