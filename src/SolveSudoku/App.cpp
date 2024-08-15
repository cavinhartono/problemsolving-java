#include <iostream>

using namespace std;

#define N 9 /* bilangan konstanta untuk ukuran `Grid` */

/*
  fungsi `isSafe` merupakan proses mengecekan,
  apakah aman untuk menempatkan angka pada sel
  di baris dan kolom yang diberikan.
*/
bool isSafe(int Grid[N][N], int row, int column, int number)
{
  int start = row - row % 3, end = column - column % 3;

  for (int i = 0; i <= (N - 1); i++)
  {
    /* apakah angka tersebut sudah ada di baris */
    if (Grid[row][i] == number)
    {
      return false;
    }
    /* apakah angka tersebut suda ada di kolom */
    if (Grid[i][column] == number)
    {
      return false;
    }
  }

  /* apakah angka tersebut sudah ada di kotak 3x3 yang berisi sel tersebut */
  for (int i = start; i < (start + 3); i++)
  {
    for (int j = end; j < (end + 3); j++)
    {
      if (Grid[i][j] == number)
      {
        return false;
      }
    }
  }

  return true;
}

/*
  fungsi tersebut merupakan algoritma backtracking,
  jika true, angka dari 1 hingga 9 dan melangkah maju.
  jika gagal tidak bisa menghasilkan solusi, maka program mundur dan mencoba lain.
  ini adalah pendekatan brute-force untuk menyelesaikan masalah
*/
bool solve(int Grid[N][N], int row, int column)
{
  /* Jika sudah mencapai akhir dari seluruh baris dan kolom telah diperiksa */
  if (row == N - 1 && column == N)
  {
    return true;
  }

  /* Jika kolom sudah mencapai akhir baris,
    maka pindah ke baris berikutnya dan mulai dari kolom pertama. */
  if (column == N)
  {
    row++;
    column = 0;
  }

  /* Jika sel sudah diisi, maka lanjut ke kolom selanjutnya. */
  if (Grid[row][column] > 0)
  {
    return solve(Grid, row, column + 1);
  }

  /* Jika sel kosong, maka angka dari 1 hingga 9. */
  for (int number = 1; number <= N; number++)
  {
    if (isSafe(Grid, row, column, number))
    {
      Grid[row][column] = number; /* Jika angka tersebut aman, masukkan angka ke dalam sel */

      /* Panggil fungsi `solve` secara rekursif untuk memeriksa angka
        tersebut di langkah berikutnya. */
      if (solve(Grid, row, column + 1))
      {
        return true;
      }
    }
    Grid[row][column] = 0; /* Jika tidak cocok, kembali angka berikutnya. */
  }

  return false; /* mengembalikan nilai asli dari `Grid` */
}

int main()
{
  int Grid[N][N] = {{0, 0, 0, /* | */ 7, 3, 0, /* | */ 0, 4, 5},
                    {0, 0, 0, /* | */ 0, 1, 4, /* | */ 0, 2, 0},
                    {0, 2, 1, /* | */ 0, 5, 6, /* | */ 0, 0, 8},
                    /* ----------+----------------+---------- */
                    {3, 6, 8, /* | */ 0, 0, 0, /* | */ 2, 0, 4},
                    {1, 9, 0, /* | */ 4, 0, 5, /* | */ 0, 0, 0},
                    {7, 0, 5, /* | */ 0, 6, 0, /* | */ 0, 1, 0},
                    /* ----------+----------------+---------- */
                    {0, 0, 4, /* | */ 3, 9, 7, /* | */ 0, 6, 0},
                    {0, 0, 0, /* | */ 0, 0, 8, /* | */ 0, 0, 0},
                    {0, 0, 7, /* | */ 0, 0, 0, /* | */ 0, 0, 0}};

  cout << endl;

  if (solve(Grid, 0, 0))
  {
    for (int i = 0; i < N; i++)
    {
      if (i % 3 == 0 && i != 0)
      {
        cout << "---------+---------+---------" << endl;
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