#include <iostream>

// Функция для проверки корректности ввода long long числа
bool isLongLong(long long& number) {
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
    std::cout << "Лабораторная работа №4, задание №2\n";
    std::cout << "Суть задания:\n";
    std::cout << "Найти сумму элементов, расположенных в чётных (по номеру) строках матрицы.\n";
    std::cout << "Выполнил студент группы 453503 Халамов Николай\n";
}

int main() {
    while (true) {
        displayContextMenu();
        
        long long m; // количество строк
        long long n; // количество столбцов

        // Ввод числа строк
        while (true) {
            std::cout << "Введите число типа long long - количество строк в матрице (положительное число): ";
            if (isLongLong(m) && m > 0) {
                break;
            } else {
                std::cout << "Ошибка: введено некорректное или неположительное число." << '\n';
            }
        }

        // Ввод числа столбцов
        while (true) {
            std::cout << "Введите число типа long long - количество столбцов в матрице (положительное число): ";
            if (isLongLong(n) && n > 0) {
                break;
            } else {
                std::cout << "Ошибка: введено некорректное или неположительное число." << '\n';
            }
        }

        long long matrix[m][n];
        long long evenSum = 0;

        // Ввод элементов матрицы
        for (long long i = 0; i < m; ++i) {
            for (long long j = 0; j < n; ++j) {
                long long element;
                while (true) {
                    std::cout << "Введите число, расположенное в " << i + 1 << " строке на " << j + 1 << " месте: ";
                    if (isLongLong(element)) {
                        matrix[i][j] = element;
                        if (i % 2 == 0) {
                            evenSum += element;
                        }
                        break;
                    } else {
                        std::cout << "Ошибка: введено некорректное число." << '\n';
                    }
                }
            }
        }

        // Вывод матрицы
        std::cout << "Матрица:" << '\n';
        for (long long i = 0; i < m; ++i) {
            for (long long j = 0; j < n; ++j) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << '\n';
        }

        std::cout << "Сумма элементов, расположенных в чётных (по номеру) строках матрицы: " << evenSum << '\n';

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