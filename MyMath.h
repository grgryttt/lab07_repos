#pragma once

// Формування рядка rowNo матриці (рекурсія по стовпчиках)
void CreateRow(int** a, const int rowNo, const int colCount, const int Low,
    const int High, int colNo);
// Формування матриці (рекурсія по рядках)
void CreateRows(int** a, const int rowCount, const int colCount, const int Low,
    const int High, int rowNo);
// Виведення рядка rowNo матриці (рекурсія по стовпчиках)
void PrintRow(int** a, const int rowNo, const int colCount, int colNo);
// Виведення матриці у вигляді таблиці (рекурсія по рядках)
void PrintRows(int** a, const int rowCount, const int colCount, int rowNo);
// Перевірка: чи треба поміняти місцями рядки row та row+1 (ключі: ↓ ↑ ↓)
bool NeedChange(int** a, const int row);
// Обмін місцями двох рядків матриці (рекурсія по стовпчиках)
void Change(int** a, const int row1, const int row2, const int colCount,
    int colNo);
// Один прохід "бульбашки" по рядках матриці (рекурсія по i1)
void SortPass(int** a, const int rowCount, const int colCount, const int i0,
    int i1);
// Впорядкування рядків матриці методом "бульбашки" (рекурсія по i0)
void SortRows(int** a, const int rowCount, const int colCount, int i0);
// Обробка рядка rowNo: підрахунок суми S і кількості k, заміна нулями
void CalcRow(int** a, const int rowNo, const int colCount, int colNo,
    int& S, int& k);
// Обробка всіх рядків матриці
void CalcRows(int** a, const int rowCount, const int colCount, int rowNo,
    int& S, int& k);

