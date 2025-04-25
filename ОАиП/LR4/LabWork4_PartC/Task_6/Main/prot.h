
#ifndef PROT_H
#define PROT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>

// Функции для проверки магического квадрата
unsigned long long computeRowSum(unsigned long long **square, long long n, long long row);
unsigned long long computeColumnSum(unsigned long long **square, long long n, long long col);
unsigned long long computeMainDiagonalSum(unsigned long long **square, long long n);
unsigned long long computeAntiDiagonalSum(unsigned long long **square, long long n);
int isMagicSquare(unsigned long long **square, long long n);

#ifdef __cplusplus
}
#endif

#endif // PROT_H