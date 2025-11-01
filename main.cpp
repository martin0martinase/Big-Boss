#include <iostream>

int ** make_mtx (int r,int c);
void output (const int * const * mtx, int r, int c);
void rm (int ** mtx, int r);
void input (int ** mtx, int r, int c);
int ** convert(const int * arr, size_t n, const size_t * lns, size_t rows);


int main ()
{
  /*int rows = 0;
  int cols = 0;
  std::cin >> rows >> cols;
  if (std::cin.fail())
  {
    return 1;
  }
  int ** mtx = nullptr;
  try
  {
  mtx = make_mtx (rows, cols);
  }
  catch (const std::bad_alloc &)
  {
    return 2;
  }
  input (mtx, rows, cols);
  if (std::cin.fail())
  {
    rm (mtx, rows);
    return 1;
  }
  output (mtx, rows, cols);
  rm (mtx, rows);
  return 0;*/

  // test

  const size_t n = 20;
  int arr[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
  const size_t rows = 4;
  size_t lns[rows] = {5, 5, 5, 5};

  //check

  size_t sum = 0;
  for (size_t i = 0; i < rows; ++i)
  {
    sum += lns[i];
  }
  if (sum != n)
  {
    return 1;
  }
  int ** mtx = nullptr;
  try
  {
    mtx = convert(arr, n, lns, rows);
  }
  catch (const std::bad_alloc &)
  {
    return 2;
  }
  output(mtx, rows, lns[0]);
  rm(mtx, rows);
  return 0;
}

void rm (int ** mtx, int r)
{
  for (size_t i = 0; i < r; ++i)
  {
    delete[] mtx[i];
  }
  delete[] mtx;
}

int ** make_mtx (int r, int c)
{
  int ** mtx = new int * [r];
  for (size_t i = 0; i < r; ++i)
  {
    try
    {
      mtx[i] = new int[c];
    }
    catch (const std::bad_alloc &)
    {
      rm (mtx,i);
      throw;
    }
  }
  return mtx;
}
void input (int ** mtx, int r, int c)
{
  for (size_t i = 0; i < r; ++i)
  {
    for (size_t j = 0; j < c; ++j)
    {
      std::cin >> mtx[i][j];
    }
  }
}

void output (const int * const * mtx, int r, int c )
{
  for (size_t i = 0; i < r; ++i)
  {
    for (size_t j = 0; j < c; ++j)
    {
      std::cout << mtx[i][j] << " ";
    }
    std::cout << "\n";
  }
}

int ** convert(const int * arr, size_t n, const size_t * lns, size_t rows)
{
  int ** mtx = new int * [rows];
  size_t poss = 0; //pos - possition in massive
  for (size_t i = 0; i < rows; ++i)
  {
    mtx[i] = new int [lns[i]];
    for (size_t j = 0; j < lns[i]; ++j)
    {
      if (poss < n)
      {
        mtx[i][j] = arr[poss];
        poss++;
      }
    }
  }
  return mtx;
}
