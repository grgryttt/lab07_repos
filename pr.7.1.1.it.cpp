// Lab_7_1_1.cpp
// Шиманова Ю.О.
// Лабораторна робота № 7.1 (ітераційний спосіб).
// Пошук заданих елементів та впорядкування рядків / стовпчиків матриці.
// Варіант 30

#include <iostream>
#include <time.h>
#include "MyMath.h"

using namespace std;

int main()
{
    srand((unsigned)time(NULL));

    int Low = 16;           // нижня межа діапазону значень елементів
    int High = 97;          // верхня межа діапазону значень елементів

    int rowCount = 8;       // кількість рядків матриці
    int colCount = 6;       // кількість стовпчиків матриці

    int** R = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        R[i] = new int[colCount];

    Create(R, rowCount, colCount, Low, High);
    Print(R, rowCount, colCount);
    Sort(R, rowCount, colCount);
    Print(R, rowCount, colCount);

    int S = 0;              // сума елементів за критерієм
    int k = 0;              // кількість елементів за критерієм
    Calc(R, rowCount, colCount, S, k);
    cout << "S = " << S << endl;
    cout << "k = " << k << endl;
    Print(R, rowCount, colCount);

    for (int i = 0; i < rowCount; i++)
        delete[] R[i];
    delete[] R;

    return 0;
}
