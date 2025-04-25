#include "..\StaticLibrary\Header.h"
#include <iostream>
#include <iomanip> // Для std::setprecision
#define ll long long

// Функция для отображения контекстного меню
void displayContextMenu() {
    std::cout << "Лабораторная работа №5, задание №3\n";
    std::cout << "Суть задания:\n";
    std::cout << "Дан двумерный динамический массив целых чисел. Значения элементов "
        << "данного массива ввести с клавиатуры. Создать динамический массив из "
        << "элементов, расположенных на главной диагонали матрицы и имеющих "
        << "четное значение. Вычислить произведение элементов динамического массива.\n";
}

// Функция для проверки корректного ввода long long числа
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
ll** create2DArray(ll lines, ll columns) {
    ll** array = new ll * [lines];
    for (ll i = 0; i < lines; ++i) {
        array[i] = new ll[columns];
    }
    return array;
}

// Функция для ввода элементов двумерного массива
void inputArray(ll** array, ll lines, ll columns) {
    std::cout << "Введите элементы массива (целые числа):\n";
    for (ll i = 0; i < lines; i++) {
        for (ll j = 0; j < columns; j++) {
            std::cout << "Элемент [" << i << "][" << j << "]: ";
            while (true) {
                if (isLongLong(array[i][j])) {
                    break;
                }
                else {
                    std::cout << "Ошибка: введено некорректное число. Попробуйте снова.\n";
                }
            }
        }
    }
}

// Функция для освобождения памяти двумерного массива
void freeArray(ll** array, ll lines) {
    for (ll i = 0; i < lines; ++i) {
        delete[] array[i];
    }
    delete[] array;
}

// Функция для вывода массива
void printArray(const ll* array, ll size) {
    for (ll i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";
}

// Функция для вывода двумерного массива
void print2DArray(ll** array, ll lines, ll columns) {
    std::cout << "Двумерный массив:\n";
    for (ll i = 0; i < lines; i++) {
        for (ll j = 0; j < columns; j++) {
            std::cout << array[i][j] << " ";
        }
        std::cout << "\n";
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

// Главная функция
int main() {
    setlocale(LC_ALL, "Russian_Russia.1251");

    while (true) {
        displayContextMenu();
        ll lines, columns;

        // Ввод размеров массива
        inputDimensions(lines, columns);

        // Выделение памяти для двумерного массива
        ll** array = create2DArray(lines, columns);

        // Ввод элементов массива
        inputArray(array, lines, columns);

        // Вывод двумерного массива
        print2DArray(array, lines, columns);

        // Создание финального массива
        ll final_array_size = 0;
        ll* final_array = createFinalArray(array, lines, columns, final_array_size);

        // Вывод финального массива
        std::cout << "Финальный массив (четные элементы главной диагонали):\n";
        printArray(final_array, final_array_size);

        // Вычисление и вывод произведения
        ll product = calculateProduct(final_array, final_array_size);
        std::cout << "Произведение элементов динамического массива равно "
            << product << '\n';

        // Освобождение памяти
        delete[] final_array;
        freeArray(array, lines);

        // Проверка на выполнение ещё одного расчёта
        if (!askForRepeat()) {
            break;
        }
    }

    return 0;
}