// Lab_7_2_1.cpp
// Шиманова Ю.О.
// Лабораторна робота № 7.2.1)
// Опрацювання багатовимірних масивів ітераційним способом.
// Варіант 30

#include <iostream>
#include <time.h>
#include "MyMath.h"

using namespace std;

int main()
{
    srand((unsigned)time(NULL));

    int Low = 10;           // нижня межа діапазону значень елементів
    int High = 99;          // верхня межа діапазону значень елементів

    int n;                  // розмірність квадратної матриці
    cout << "n = "; cin >> n;

    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];

    Create(a, n, Low, High);
    Print(a, n);

    SortMainDiagonal(a, n);
    Print(a, n);

    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}
