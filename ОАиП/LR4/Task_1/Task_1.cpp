#include <iostream>

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
    std::cout << "Лабораторная работа №4, задание №1\n";
    std::cout << "Суть задания:\n";
    std::cout << "Определить количество элементов, значение которых больше среднего значения всех элементов массива.\n";
    std::cout << "Выполнил студент группы 453503 Халамов Николай\n";
}

// Функция для подсчета суммы элементов массива
long double calculateSum(const long double* array, long long size) {
    long double sum = 0;
    for (long long i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum;
}

// Функция для вычисления среднего значения
long double calculateAverage(const long double* array, long long size) {
    if (size == 0) return 0; // Предотвращаем деление на ноль
    return calculateSum(array, size) / size;
}

// Функция для подсчета элементов больше среднего
long long countGreaterThanAverage(const long double* array, long long size, long double average) {
    long long count = 0;
    for (long long i = 0; i < size; i++) {
        if (array[i] > average) {
            count++;
        }
    }
    return count;
}

int main() {
    while (true) {
        displayContextMenu();

        long long k;

        // Ввод количества элементов в массиве
        std::cout << "Введите количество элементов в массиве: " << '\n';
        while (true) {
            if (isLongLong(k) && k > 0) {
                break;
            } else {
                std::cout << "Ошибка: введено некорректное число. Попробуйте снова." << '\n';
            }
        }

        long double array[k]; // Статический массив
        // Ввод элементов массива
        std::cout << "Введите массив: " << '\n';
        for (long long i = 0; i < k; i++) {
            long double g;
            while (true) {
                std::cout << "Элемент " << i + 1 << ": ";
                if (isLongDouble(g)) {
                    array[i] = g;
                    break;
                } else {
                    std::cout << "Ошибка: введено некорректное число. Попробуйте снова." << '\n';
                }
            }
        }

        long double average = calculateAverage(array, k); // Среднее значение
        
        // Подсчет элементов больше среднего
        long long countGreater = countGreaterThanAverage(array, k, average);

        // Вывод исходного массива
        std::cout << "Исходный массив: " << '\n';
        for (long long i = 0; i < k; i++) {
            std::cout << array[i] << ' ';
        }
        std::cout << '\n' << "Количество элементов больше среднего равно " << countGreater << '\n';

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