#pragma once

// Формування квадратної матриці випадковими числами з діапазону [Low; High]
void Create(int** a, const int n, const int Low, const int High);
// Виведення матриці у вигляді таблиці
void Print(int** a, const int n);
// Обмін значень двох змінних
void Swap(int& x, int& y);
// Впорядкування за зростанням елементів головної діагоналі
void SortMainDiagonal(int** a, const int n);
