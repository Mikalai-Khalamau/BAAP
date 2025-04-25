#include <iostream>
#include "prot.h"

// Функция для проверки корректного ввода long long числа
bool isLongLong(long long& number) {
    std::cin >> number;
    if (std::cin.fail())
    
     {
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

// Функция для отображения контекстного меню
void displayContextMenu() {
    std::cout << "Лабораторная работа №4, задание №3\n";
    std::cout << "Суть задания:\n";
    std::cout << "Дана действительная квадратная матрица порядка N. "
              << "Найти сумму и произведение элементов, расположенных в "
              << "заштрихованной части матрицы\n";
    std::cout << "Выполнил студент группы 453503 Халамов Николай\n";
}

// Функция для вычисления суммы и произведения заштрихованных элементов
void MainQuestion(long double** matrix, long long N, long double& sum, long double& product) {
    sum = 0.0;     // Сумма элементов
    product = 1.0; // Произведение элементов
    int k = 0, l = N;

    if (N % 2 == 1) {
        for (int i = 0; i < N; i++) {
            for (int j = k; j < l; j++) {
                product *= matrix[i][j];
                sum += matrix[i][j];
            }
            if (i <= N / 2 - 1) {
                k++;
                l--;
            } else {
                k--;
                l++;
            }
        }
    } else {
        for (int i = 0; i < N; i++) {
            for (int j = k; j < l; j++) {
                product *= matrix[i][j];
                sum += matrix[i][j];
            }
            if (i < N / 2 - 1) {
                k++;
                l--;
            }
            if (i >= N / 2) {
                k--;
                l++;
            }
        }
    }
}

int main() {
    while (true) { 
        long long N;

        displayContextMenu();

        // Ввод порядка матрицы
        std::cout << "Введите порядок матрицы N (целое число): " << '\n';
        while (true) {
            if (isLongLong(N) && N > 0) {
                break;
            } else {
                std::cout << "Ошибка: введено некорректное число. Попробуйте снова." << '\n';
            }
        }

        // Динамическое выделение памяти для матрицы
        auto** matrix = new long double*[N];
        for (long long i = 0; i < N; i++) {
            matrix[i] = new long double[N];
        }

        // Ввод элементов матрицы
        std::cout << "Введите элементы матрицы (действительные числа):" << '\n';
        for (long long i = 0; i < N; i++) {
            for (long long j = 0; j < N; j++) {
                std::cout << "Элемент [" << i + 1 << "][" << j + 1 << "]: ";
                while (true) {
                    if (isLongDouble(matrix[i][j])) {
                        break;
                    } else {
                        std::cout << "Ошибка: введено некорректное число. Попробуйте снова." << '\n';
                    }
                }
            }
        }

        long double sum = 0.0;     // Сумма элементов
        long double product = 1.0; // Произведение элементов

        // Вычисление суммы и произведения заштрихованных элементов
        MainQuestion(matrix, N, sum, product);

        // Вывод матрицы
        std::cout << "Введённая матрица:" << '\n';
        for (long long i = 0; i < N; i++) {
            for (long long j = 0; j < N; j++) {
                std::cout << matrix[i][j] << ' ';
            }
            std::cout << '\n';
        }

        std::cout << "Произведение: " << product << '\n' << "Сумма: " << sum << '\n';

        // Освобождение памяти
        for (long long i = 0; i < N; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;

        // Проверка на выполнение ещё одного расчёта
        std::string choice;
        while (true) {
            std::cout << "Хотите выполнить ещё один расчёт? (y/n): ";
            std::cin >> choice;
            std::cin.clear();
            std::cin.ignore(10000, '\n');

            if (choice == "y" || choice == "Y" || choice == "да" || choice == "ДА" || choice == "yes" || choice == "YES") {
                std::cout << "\n----------------------------------------\n\n";
                break;
            } else if (choice == "n" || choice == "N" || choice == "нет" || choice == "НЕТ" || choice == "no" || choice == "NO") {
                std::cout << "Завершение программы. До свидания!" << '\n';
                return 0;
            } else {
                std::cout << "Некорректный ввод. Пожалуйста, введите 'y' или 'n'." << '\n';
            }
        }
    }
    return 0;
}