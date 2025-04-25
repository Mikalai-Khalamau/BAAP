#include "..\StaticLibrary\Header.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

#define ll long long

// Функция для отображения контекстного меню
void displayContextMenu() {
    std::cout << "Лабораторная работа №5, задание №4\n";
    std::cout << "Суть задания:\n";
    std::cout << "Создать двумерный динамический массив вещественных чисел. Определить, "
        "встречаются ли среди них элементы с нулевым значением. Если встречаются "
        "такие элементы, то определить их индексы и общее количество. Переставить "
        "элементы этого массива в обратном порядке и вывести на экран.\n";
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

// Функция для ввода количества строк и столбцов
void inputDimensions(ll& lines, ll& columns) {
    std::cout << "Введите количество строк двумерного массива (целое число):\n";
    while (true) {
        if (isLongLong(lines) && lines > 0) {
            break;
        }
        else {
            std::cout << "Ошибка: введено некорректное число. Попробуйте снова.\n";
        }
    }

    std::cout << "Введите количество столбцов двумерного массива (целое число):\n";
    while (true) {
        if (isLongLong(columns) && columns > 0) {
            break;
        }
        else {
            std::cout << "Ошибка: введено некорректное число. Попробуйте снова.\n";
        }
    }
}

// Функция для выделения памяти для двумерного массива
long double** create2DArray(ll lines, ll columns) {
    long double** array = new long double* [lines];
    for (ll i = 0; i < lines; ++i) {
        array[i] = new long double[columns];
    }
    return array;
}

void inputArray(long double** array, ll lines, ll columns) {
    for (ll i = 0; i < lines; i++) {
        for (ll j = 0; j < columns; j++) {
            // С вероятностью 20% присваиваем 0
            if (rand() % 100 < 20) {
                array[i][j] = 0;
            }
            else {
                array[i][j] = static_cast<long double>(rand()) / RAND_MAX * 200.0 - 100.0;
            }
        }
    }
}


// Функция для вывода двумерного массива
void print2DArray(long double** array, ll lines, ll columns) {
    std::cout << "Двумерный массив рандомных чисел типа long double:\n";
    for (ll i = 0; i < lines; i++) {
        for (ll j = 0; j < columns; j++) {
            std::cout << array[i][j] << " ";
        }
        std::cout << "\n";
    }
}

// Функция для освобождения памяти двумерного массива
void freeArray(long double** array, ll lines) {
    for (ll i = 0; i < lines; ++i) {
        delete[] array[i];
    }
    delete[] array;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    setlocale(LC_ALL, "Russian_Russia.1251");

    do {
        ll lines, columns;

        // Отображение контекстного меню
        displayContextMenu();

        // Ввод размеров массива
        inputDimensions(lines, columns);

        // Выделение памяти для двумерного массива
        long double** array = create2DArray(lines, columns);

        // Ввод элементов массива
        inputArray(array, lines, columns);

        // Вывод двумерного массива
        print2DArray(array, lines, columns);

        // Подсчет нулевых элементов
        Zeros(array, lines, columns);

        // Перестановка элементов
        reverseMatrix(array, lines, columns);

        std::cout << "Измененный массив:\n";
        // Вывод измененного двумерного массива
        print2DArray(array, lines, columns);

        // Освобождение памяти
        freeArray(array, lines);

    } while (askForRepeat());

    return 0;
}