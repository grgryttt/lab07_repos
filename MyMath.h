#pragma once

// Формування рядка rowNo матриці (рекурсія по стовпчиках)
void CreateRow(int** a, const int rowNo, const int N, const int Low,
    const int High, int colNo);
// Формування матриці (рекурсія по рядках)
void CreateRows(int** a, const int N, const int Low, const int High,
    int rowNo);
// Виведення рядка rowNo матриці (рекурсія по стовпчиках)
void PrintRow(int** a, const int rowNo, const int N, int colNo);
// Виведення матриці у вигляді таблиці (рекурсія по рядках)
void PrintRows(int** a, const int N, int rowNo);
// Обмін значень двох змінних
void Swap(int& x, int& y);
// Один прохід "бульбашки" по головній діагоналі (рекурсія по i1)
void SortPass(int** a, const int N, const int i0, int i1);
// Впорядкування за зростанням елементів головної діагоналі (рекурсія по i0)
void SortMainDiagonal(int** a, const int N, int i0);
