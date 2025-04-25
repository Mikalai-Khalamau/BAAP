// Fun.c
#include "prot.h"

// Функция для вычисления суммы конкретной строки
unsigned long long computeRowSum(unsigned long long **square, long long n, long long row) {
    unsigned long long sum = 0;
    for (long long j = 0; j < n; ++j) {
        sum += square[row][j];
    }
    return sum;
}

// Функция для вычисления суммы конкретного столбца
unsigned long long computeColumnSum(unsigned long long **square, long long n, long long col) {
    unsigned long long sum = 0;
    for (long long i = 0; i < n; ++i) {
        sum += square[i][col];
    }
    return sum;
}

// Функция для вычисления суммы главной диагонали
unsigned long long computeMainDiagonalSum(unsigned long long **square, long long n) {
    unsigned long long sum = 0;
    for (long long i = 0; i < n; ++i) {
        sum += square[i][i];
    }
    return sum;
}

// Функция для вычисления суммы побочной диагонали
unsigned long long computeAntiDiagonalSum(unsigned long long **square, long long n) {
    unsigned long long sum = 0;
    for (long long i = 0; i < n; ++i) {
        sum += square[i][n - 1 - i];
    }
    return sum;
}

// Функция для проверки, является ли квадрат магическим
int isMagicSquare(unsigned long long **square, long long n) {
    if (n == 0) return 0;

    unsigned long long magicConstant = ((unsigned long long)n * (n * n + 1)) / 2;

    // Проверка всех строк
    for (long long i = 0; i < n; ++i) {
        if (computeRowSum(square, n, i) != magicConstant) {
            return 0;
        }
    }

    // Проверка всех столбцов
    for (long long j = 0; j < n; ++j) {
        if (computeColumnSum(square, n, j) != magicConstant) {
            return 0;
        }
    }

    // Проверка главной диагонали
    if (computeMainDiagonalSum(square, n) != magicConstant) {
        return 0;
    }

    // Проверка побочной диагонали
    if (computeAntiDiagonalSum(square, n) != magicConstant) {
        return 0;
    }

    return 1; // Квадрат магический
}
