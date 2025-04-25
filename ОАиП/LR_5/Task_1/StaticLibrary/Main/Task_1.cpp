#include <iostream>
#include "..\StaticLibrary\Header.h"
#define ll long long

// Функция для отображения контекстного меню
void displayContextMenu() {
    std::cout << "Лабораторная работа №5, задание №1\n";
    std::cout << "Суть задания:\n";
    std::cout << "Составить матрицу, в которой элементы будут равны максимуму из 2 элементов заданных матриц на соответствующей позиции.\n";
}

// Функция для проверки корректного ввода long long числа
bool isLongLong(ll& number) {
    std::cin >> number;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return false;
    }
    if (std::cin.peek() != '\n') {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return false;
    }
    return true;
}

// Функция для выделения памяти под двумерный массив
long double** createMatrix(ll n) {
    long double** matrix = new long double* [n];
    for (ll i = 0; i < n; i++) {
        matrix[i] = new long double[n];
    }
    return matrix;
}

// Функция для освобождения памяти двумерного массива
void freeMatrix(long double** matrix, ll n) {
    for (ll i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

// Функция для проверки корректного ввода long double числа
bool isLongDouble(long double& number) {
    std::cin >> number;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return false;
    }
    if (std::cin.peek() != '\n') {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return false;
    }
    return true;
}

// Функция для ввода элементов матрицы
void inputMatrix(long double** matrix, ll n, char name) {
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            while (true) {
                std::cout << "Введите элемент матрицы " << name << " на позиции " << i << "," << j << ":\n";
                if (isLongDouble(matrix[i][j])) {
                    break;
                }
                else {
                    std::cout << "Ошибка: введено некорректное число. Попробуйте снова.\n";
                }
            }
        }
    }
}

// Функция для вывода матрицы
void printMatrix(long double** matrix, ll n, char name) {
    std::cout << "Матрица " << name << ":\n";
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << '\n';
    }
}

// Функция для повторного запроса расчета
bool askForRepeat() {
    std::string choice;
    while (true) {
        std::cout << "Хотите выполнить ещё один расчёт? (y/n): ";
        std::cin >> choice;
        std::cin.clear();
        std::cin.ignore(10000, '\n');

        if (choice == "y" || choice == "Y" || choice == "да" || choice == "ДА" || choice == "yes" || choice == "YES") {
            std::cout << "\n----------------------------------------\n\n";
            return true;
        }
        else if (choice == "n" || choice == "N" || choice == "нет" || choice == "НЕТ" || choice == "no" || choice == "NO") {
            std::cout << "Завершение программы. До свидания!" << '\n';
            return false;
        }
        else {
            std::cout << "Некорректный ввод. Пожалуйста, введите 'y' или 'n'.\n";
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian_Russia.1251");

    while (true) {
        displayContextMenu();
        ll n;
        std::cout << "Введите размерность массивов (целое положительное число):\n";
        while (true) {
            if (isLongLong(n) && n > 0) {
                break;
            }
            else {
                std::cout << "Ошибка: введено некорректное число. Попробуйте снова.\n";
            }
        }

        // Выделение памяти для матриц
        long double** b = createMatrix(n);
        long double** c = createMatrix(n);
        long double** a = createMatrix(n);

        // Ввод элементов для матрицы b
        inputMatrix(b, n, 'b');

        // Ввод элементов для матрицы c
        inputMatrix(c, n, 'c');

        // Заполнение матрицы a
        fillMatrixA(a, b, c, n);

        // Вывод матрицы a
        printMatrix(a, n, 'a');

        // Освобождение памяти
        freeMatrix(a, n);
        freeMatrix(b, n);
        freeMatrix(c, n);

        // Проверка на повторный ввод
        if (!askForRepeat()) {
            break;
        }
    }

    return 0;
}