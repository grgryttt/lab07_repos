// Lab_7_2_2.cpp
// Шиманова Ю.О.
// Лабораторна робота № 7.2.2)
// Опрацювання багатовимірних масивів рекурсивним способом.
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

    int N;                  // розмірність квадратної матриці
    cout << "N = "; cin >> N;

    int** a = new int* [N];
    for (int i = 0; i < N; i++)
        a[i] = new int[N];

    CreateRows(a, N, Low, High, 0);
    cout << endl;
    PrintRows(a, N, 0);

    if (N > 1)              // для N = 1 впорядковувати нічого
        SortMainDiagonal(a, N, 0);
    PrintRows(a, N, 0);

    for (int i = 0; i < N; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}
