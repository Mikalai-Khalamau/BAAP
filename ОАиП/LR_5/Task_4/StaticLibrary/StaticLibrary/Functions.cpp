#include "Header.h"
#include <iostream>

// Функция для подсчета количества нулевых элементов и вывода их позиций
void Zeros(long double** array, ll lines, ll columns) {
    ll zeros = 0;
    for (ll i = 0; i < lines; i++) {
        for (ll j = 0; j < columns; j++) {
            if (array[i][j] == 0) {
                zeros++;
                std::cout << "Нулевой элемент на позиции " << i << "," << j << '\n';
            }
        }
    }
    std::cout << "Количество нулей в двумерном массиве равно " << zeros << '\n';
}

// Функция для перестановки элементов двумерного массива в обратном порядке
void reverseMatrix(long double** array, ll rows, ll cols) {
    for (ll i = 0; i < rows; i++) {
        for (ll j = 0; j < cols / 2; j++) {
            std::swap(array[i][j], array[i][cols - 1 - j]);
        }
    }
}