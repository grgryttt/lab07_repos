#include "pch.h"
#include "CppUnitTest.h"
#include "../PR.7.1.2.rek/MyMath.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest7_1_2
{
    TEST_CLASS(UnitTest7_1_2)
    {
    public:
        // Створює динамічну матрицю rows x cols із значень масиву data
        int** Make(int rows, int cols, const int* data)
        {
            int** a = new int* [rows];
            for (int i = 0; i < rows; i++)
            {
                a[i] = new int[cols];
                for (int j = 0; j < cols; j++)
                    a[i][j] = data[i * cols + j];
            }
            return a;
        }

        void Free(int** a, int rows)
        {
            for (int i = 0; i < rows; i++)
                delete[] a[i];
            delete[] a;
        }

        // Перевіряє, що рядок i матриці дорівнює очікуваним значенням
        void CheckRow(int** a, int i, int cols, const int* expected)
        {
            for (int j = 0; j < cols; j++)
                Assert::AreEqual(expected[i * cols + j], a[i][j]);
        }

        TEST_METHOD(TestCalc_2x2)
        {
            int d[] = { 16, 18,
                        20, 22 };
            int** a = Make(2, 2, d);
            int S, k;
            S = 0; k = 0;
            CalcRows(a, 2, 2, 0, S, k);
            Assert::AreEqual(60, S);            // 18 + 20 + 22
            Assert::AreEqual(3, k);
            Assert::AreEqual(16, a[0][0]);      // не задовольняє критерію
            Assert::AreEqual(0, a[0][1]);
            Assert::AreEqual(0, a[1][0]);
            Assert::AreEqual(0, a[1][1]);
            Free(a, 2);
        }

        TEST_METHOD(TestCalc_MultiplesOf7)
        {
            int d[] = { 14, 16,
                        18, 20 };
            int** a = Make(2, 2, d);
            int S, k;
            S = 0; k = 0;
            CalcRows(a, 2, 2, 0, S, k);
            Assert::AreEqual(68, S);            // 14 кратне 7 -> теж береться
            Assert::AreEqual(4, k);
            Free(a, 2);
        }

        TEST_METHOD(TestCalc_3x3)
        {
            int d[] = { 16, 17, 18,
                        19, 20, 21,
                        22, 23, 24 };
            int** a = Make(3, 3, d);
            int S, k;
            S = 0; k = 0;
            CalcRows(a, 3, 3, 0, S, k);
            Assert::AreEqual(100, S);           // 17+19+20+21+23
            Assert::AreEqual(5, k);
            Free(a, 3);
        }

        TEST_METHOD(TestCalc_Accumulates)
        {
            int d[] = { 16, 18,
                        20, 22 };
            int** a = Make(2, 2, d);
            int S = 100, k = 10;                // рекурсивна версія накопичує
            CalcRows(a, 2, 2, 0, S, k);
            Assert::AreEqual(160, S);           // 100 + 60
            Assert::AreEqual(13, k);            // 10 + 3
            Free(a, 2);
        }

        TEST_METHOD(TestSort_WithTies)
        {
            int d[] = { 10, 5, 1,
                        20, 5, 1,
                        20, 3, 2,
                        20, 3, 9 };
            int e[] = { 20, 3, 9,               // 1-й ↓, 2-й ↑, 3-й ↓
                        20, 3, 2,
                        20, 5, 1,
                        10, 5, 1 };
            int** a = Make(4, 3, d);
            SortRows(a, 4, 3, 0);
            for (int i = 0; i < 4; i++)
                CheckRow(a, i, 3, e);
            Free(a, 4);
        }

        TEST_METHOD(TestSort_AlreadySorted)
        {
            int d[] = { 30, 1, 5,
                        20, 1, 5,
                        10, 1, 5 };
            int** a = Make(3, 3, d);
            SortRows(a, 3, 3, 0);
            for (int i = 0; i < 3; i++)
                CheckRow(a, i, 3, d);
            Free(a, 3);
        }

        TEST_METHOD(TestNeedChange)
        {
            int d[] = { 10, 5, 1,
                        20, 5, 1,       // 10 < 20 -> міняти
                        20, 3, 2,       // 5 > 3   -> міняти
                        20, 3, 9,       // 2 < 9   -> міняти
                        20, 3, 9 };     // однакові -> не міняти
            int** a = Make(5, 3, d);
            Assert::IsTrue(NeedChange(a, 0));
            Assert::IsTrue(NeedChange(a, 1));
            Assert::IsTrue(NeedChange(a, 2));
            Assert::IsFalse(NeedChange(a, 3));
            Free(a, 5);
        }

        TEST_METHOD(TestChange)
        {
            int d[] = { 1, 2, 3,
                        4, 5, 6 };
            int e[] = { 4, 5, 6,
                        1, 2, 3 };
            int** a = Make(2, 3, d);
            Change(a, 0, 1, 3, 0);
            for (int i = 0; i < 2; i++)
                CheckRow(a, i, 3, e);
            Free(a, 2);
        }
    };
}
