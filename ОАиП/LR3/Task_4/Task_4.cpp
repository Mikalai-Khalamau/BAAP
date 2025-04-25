#include <iostream>
#include <cmath>

double power(double base, int exponent) {
    // Обработка отрицательной степени
    if (exponent < 0) {
        base = 1.0 / base; // Инвертируем основание
        exponent = -exponent; // Делаем степень положительной
    }

    double result = 1.0;

    // Возведение в степень
    for (int i = 0; i < exponent; i++) {
        result *= base; // Умножаем результат на основание
    }

    return result;
}

// Функция для вычисления S(x)
long double MyFunction(long long n, long double x) {
    long double sum = 0.0;
    for (long long i = 1; i <= n; i++) {
        sum += power(-1, i ) * power(x  + 1, 2 * i) / i; // Вычисляем члены ряда
    }
    return sum;
}

// Функция для проверки, является ли ввод допустимым целым числом типа long long
bool isLongLong(long long &number) {
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

// Функция для проверки, является ли ввод допустимым положительным числом
bool isPositiveDouble(double &number) {
    std::cin >> number;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return false;
    }

    if (std::cin.peek() != '\n' || number < 0.1 || number > 1.0) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return false;
    }

    return true;
}

int main() {
    std::cout << "Программа для вычисления Y(x) = ln(1/(2 + 2x + x^2))\n";
    std::cout << "С помощью ряда S(x) и стандартных функций.\n\n";

    while (true) {
        long long n = 0;

        // Ввод количества членов ряда
        while (true) {
            std::cout << "Введите количество членов ряда (n > 0): ";
            if (isLongLong(n) && n > 0) {
                break;
            }
            std::cout << "Некорректный ввод. Пожалуйста, введите целое число больше 0.\n";
        }

        long long m = 0;

        // Ввод количества значений x
        while (true) {
            std::cout << "Введите количество значений x для вычисления функции (m > 0): ";
            if (isLongLong(m) && m > 0) {
                break;
            }
            std::cout << "Некорректный ввод. Пожалуйста, введите целое число больше 0.\n";
        }

        // Ввод и обработка каждого значения x
        for (long long i = 1; i <= m; ++i) {
            double x = 0.0;

            while (true) {
                std::cout << "Введите значение x" << i << " (0.1 <= x <= 1): ";
                if (isPositiveDouble(x)) {
                    // Вывод результатов
                    long double cm = log(1 / (2 + 2 * x + x * x));
                    std::cout << "Результаты для x = " << x << ":\n";
                    std::cout << "S(x) = " << MyFunction(n, x) << "\n"; // Результат ряда
                    std::cout << "Y(x) стандартная функция = " << cm << "\n\n"; // Стандартный логарифм
                    break; // Выход из внутреннего цикла после успешного ввода
                }       
                std::cout << "Некорректный ввод. Пожалуйста, введите число в диапазоне от 0.1 до 1.\n";
            }   
        }

        // Запрос на выполнение ещё одного расчёта
        std::string choice;
        while (true) {
            std::cout << "Хотите выполнить ещё один расчёт? (y/n): ";
            std::cin >> choice;
            std::cin.ignore(10000, '\n'); // Очистка ввода после чтения выбора

            if (choice == "y" || choice == "Y" || choice == "да" || choice == "ДА" ||
                choice == "yes" || choice == "YES") {
                std::cout << "\n----------------------------------------\n\n";
                break;
            } else if (choice == "n" || choice == "N" || choice == "нет" || choice == "НЕТ" ||
                       choice == "no" || choice == "NO") {
                std::cout << "Завершение программы. До свидания!\n";
                return 0;
            } else {
                std::cout << "Некорректный ввод. Пожалуйста, введите 'y' или 'n'.\n";
            }
        }
    }

    return 0;
}
