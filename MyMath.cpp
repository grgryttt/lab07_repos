#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "MyMath.h"

using namespace std;

void Create(int** a, const int n, const int Low, const int High)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

void Swap(int& x, int& y)
{
    int tmp = x;
    x = y;
    y = tmp;
}

void SortMainDiagonal(int** a, const int n)
{
    for (int i0 = 0; i0 < n - 1; i0++)              // метод "бульбашки"
        for (int i1 = 0; i1 < n - i0 - 1; i1++)
            if (a[i1][i1] > a[i1 + 1][i1 + 1])
                Swap(a[i1][i1], a[i1 + 1][i1 + 1]);
}
