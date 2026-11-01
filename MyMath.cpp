#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "MyMath.h"

using namespace std;

void CreateRow(int** a, const int rowNo, const int colCount, const int Low,
    const int High, int colNo)
{
    a[rowNo][colNo] = Low + rand() % (High - Low + 1);
    if (colNo < colCount - 1)
        CreateRow(a, rowNo, colCount, Low, High, colNo + 1);
}

void CreateRows(int** a, const int rowCount, const int colCount, const int Low,
    const int High, int rowNo)
{
    CreateRow(a, rowNo, colCount, Low, High, 0);
    if (rowNo < rowCount - 1)
        CreateRows(a, rowCount, colCount, Low, High, rowNo + 1);
}

void PrintRow(int** a, const int rowNo, const int colCount, int colNo)
{
    cout << setw(4) << a[rowNo][colNo];
    if (colNo < colCount - 1)
        PrintRow(a, rowNo, colCount, colNo + 1);
    else
        cout << endl;
}

void PrintRows(int** a, const int rowCount, const int colCount, int rowNo)
{
    if (rowNo == 0)
        cout << endl;                       // відокремлюємо матриці одну від одної
    PrintRow(a, rowNo, colCount, 0);
    if (rowNo < rowCount - 1)
        PrintRows(a, rowCount, colCount, rowNo + 1);
    else
        cout << endl;
}

bool NeedChange(int** a, const int row)
{
    return (a[row][0] < a[row + 1][0])            // 1-й стовпчик: ↓
        ||
        (a[row][0] == a[row + 1][0] &&
            a[row][1] > a[row + 1][1])            // 2-й стовпчик: ↑
        ||
        (a[row][0] == a[row + 1][0] &&
            a[row][1] == a[row + 1][1] &&
            a[row][2] < a[row + 1][2]);           // 3-й стовпчик: ↓
}

void Change(int** a, const int row1, const int row2, const int colCount,
    int colNo)
{
    int tmp = a[row1][colNo];
    a[row1][colNo] = a[row2][colNo];
    a[row2][colNo] = tmp;
    if (colNo < colCount - 1)
        Change(a, row1, row2, colCount, colNo + 1);
}

void SortPass(int** a, const int rowCount, const int colCount, const int i0,
    int i1)
{
    if (NeedChange(a, i1))
        Change(a, i1, i1 + 1, colCount, 0);
    if (i1 < rowCount - i0 - 2)
        SortPass(a, rowCount, colCount, i0, i1 + 1);
}

void SortRows(int** a, const int rowCount, const int colCount, int i0)
{
    SortPass(a, rowCount, colCount, i0, 0);
    if (i0 < rowCount - 2)
        SortRows(a, rowCount, colCount, i0 + 1);
}

void CalcRow(int** a, const int rowNo, const int colCount, int colNo,
    int& S, int& k)
{
    // критерій: кратні 7 або хоча б один індекс непарний
    if (a[rowNo][colNo] % 7 == 0 || rowNo % 2 != 0 || colNo % 2 != 0)
    {
        S += a[rowNo][colNo];
        k++;
        a[rowNo][colNo] = 0;
    }
    if (colNo < colCount - 1)
        CalcRow(a, rowNo, colCount, colNo + 1, S, k);
}

void CalcRows(int** a, const int rowCount, const int colCount, int rowNo,
    int& S, int& k)
{
    CalcRow(a, rowNo, colCount, 0, S, k);
    if (rowNo < rowCount - 1)
        CalcRows(a, rowCount, colCount, rowNo + 1, S, k);
}
