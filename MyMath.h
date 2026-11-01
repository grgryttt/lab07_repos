#pragma once

// Формування матриці випадковими числами з діапазону [Low; High]
void Create(int** a, const int rowCount, const int colCount, const int Low,
    const int High);
// Виведення матриці у вигляді таблиці
void Print(int** a, const int rowCount, const int colCount);
// Впорядкування рядків матриці за ключами: ↓ ↑ ↓
void Sort(int** a, const int rowCount, const int colCount);
// Обмін місцями двох рядків матриці
void Change(int** a, const int row1, const int row2, const int colCount);
// Обчислення кількості k та суми S елементів, що задовольняють критерію,
// та заміна цих елементів нулями
void Calc(int** a, const int rowCount, const int colCount, int& S, int& k);

