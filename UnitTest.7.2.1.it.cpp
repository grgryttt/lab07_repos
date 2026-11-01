#include "pch.h"
#include "CppUnitTest.h"
#include "../PR.7.2.1.it/MyMath.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest7_2_1
{
    TEST_CLASS(UnitTest7_2_1)
    {
    public:
        // Створює динамічну квадратну матрицю n x n із значень масиву data
        int** Make(int n, const int* data)
        {
            int** a = new int* [n];
            for (int i = 0; i < n; i++)
            {
                a[i] = new int[n];
                for (int j = 0; j < n; j++)
                    a[i][j] = data[i * n + j];
            }
            return a;
        }

        void Free(int** a, int n)
        {
            for (int i = 0; i < n; i++)
                delete[] a[i];
            delete[] a;
        }

        // Діагональ має бути відсортована, а решта елементів – не змінитись
        void CheckResult(int** a, int n, const int* expected)
        {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    Assert::AreEqual(expected[i * n + j], a[i][j]);
        }

        TEST_METHOD(TestSwap)
        {
            int x = 3, y = 7;
            Swap(x, y);
            Assert::AreEqual(7, x);
            Assert::AreEqual(3, y);
        }

        TEST_METHOD(TestSort_Unsorted4x4)
        {
            int d[] = { 40, 1, 2, 3,
                        4, 10, 5, 6,
                        7, 8, 30, 9,
                        11, 12, 13, 20 };
            int e[] = { 10, 1, 2, 3,
                        4, 20, 5, 6,
                        7, 8, 30, 9,
                        11, 12, 13, 40 };
            int** a = Make(4, d);
            SortMainDiagonal(a, 4);
            CheckResult(a, 4, e);
            Free(a, 4);
        }

        TEST_METHOD(TestSort_AlreadySorted)
        {
            int d[] = { 1, 9, 9,
                        9, 2, 9,
                        9, 9, 3 };
            int** a = Make(3, d);
            SortMainDiagonal(a, 3);
            CheckResult(a, 3, d);
            Free(a, 3);
        }

        TEST_METHOD(TestSort_Descending)
        {
            int d[] = { 30, 0, 0,
                        0, 20, 0,
                        0, 0, 10 };
            int e[] = { 10, 0, 0,
                        0, 20, 0,
                        0, 0, 30 };
            int** a = Make(3, d);
            SortMainDiagonal(a, 3);
            CheckResult(a, 3, e);
            Free(a, 3);
        }

        TEST_METHOD(TestSort_EqualElements)
        {
            int d[] = { 5, 1,
                        2, 5 };
            int** a = Make(2, d);
            SortMainDiagonal(a, 2);
            CheckResult(a, 2, d);
            Free(a, 2);
        }

        TEST_METHOD(TestSort_Size1)
        {
            int d[] = { 42 };
            int** a = Make(1, d);
            SortMainDiagonal(a, 1);
            Assert::AreEqual(42, a[0][0]);
            Free(a, 1);
        }

        TEST_METHOD(TestSort_AntiDiagonalUntouched)
        {
            int d[] = { 9, 1, 7,
                        2, 5, 3,
                        8, 4, 1 };
            int e[] = { 1, 1, 7,
                        2, 5, 3,
                        8, 4, 9 };
            int** a = Make(3, d);
            SortMainDiagonal(a, 3);
            CheckResult(a, 3, e);
            Free(a, 3);
        }
    };
}
