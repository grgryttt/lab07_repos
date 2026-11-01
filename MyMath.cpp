#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "MyMath.h"

using namespace std;

void CreateRow(int** a, const int rowNo, const int N, const int Low,
    const int High, int colNo)
{
    a[rowNo][colNo] = Low + rand() % (High - Low + 1);
    if (colNo < N - 1)
        CreateRow(a, rowNo, N, Low, High, colNo + 1);
}

void CreateRows(int** a, const int N, const int Low, const int High,
    int rowNo)
{
    CreateRow(a, rowNo, N, Low, High, 0);
    if (rowNo < N - 1)
        CreateRows(a, N, Low, High, rowNo + 1);
}

void PrintRow(int** a, const int rowNo, const int N, int colNo)
{
    cout << setw(4) << a[rowNo][colNo];
    if (colNo < N - 1)
        PrintRow(a, rowNo, N, colNo + 1);
    else
        cout << endl;
}

void PrintRows(int** a, const int N, int rowNo)
{
    PrintRow(a, rowNo, N, 0);
    if (rowNo < N - 1)
        PrintRows(a, N, rowNo + 1);
    else
        cout << endl;
}

void Swap(int& x, int& y)
{
    int tmp = x;
    x = y;
    y = tmp;
}

void SortPass(int** a, const int N, const int i0, int i1)
{
    if (a[i1][i1] > a[i1 + 1][i1 + 1])
        Swap(a[i1][i1], a[i1 + 1][i1 + 1]);
    if (i1 < N - i0 - 2)
        SortPass(a, N, i0, i1 + 1);
}

void SortMainDiagonal(int** a, const int N, int i0)
{
    SortPass(a, N, i0, 0);
    if (i0 < N - 2)
        SortMainDiagonal(a, N, i0 + 1);
}
