#include <iostream>

void DisplayContextMenu() {
    std::cout << "Лабораторная работа №3, задание №3\n";
    std::cout << "Суть задания:\n";
    std::cout << "Вычисление значений функции y = sin(x) - cos(x) на отрезке [A, B].\n";
    std::cout << "Выполнил студент группы 453503 Халамов Николай\n";
}

bool isLongDouble(long double &number) {
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

constexpr long double kPi = 3.14159265358979323846264338327950288419716939937510;

long double Normalize(long double x) {
    if (x >= 0) {
        while (x > kPi) {
            long double k = 1;
            while (x - k * 2 * kPi > 0) {
                k = k * 2;
            }
            x = x - k * kPi;
        }
        return x;
    } else {
        x = -x;
        while (x > kPi) {
            long double k = 1;
            while (x - k * kPi > 0) {
                k = k * kPi;
            }
            x = x - k;
        }
        return -x;
    }
}

long double Factorial(int n) {
    if (n == 0 || n == 1) {
        return 1.0;
    }
    long double result = 1.0;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

long double Power(long double x, int n) {
    long double result = 1.0;
    for (int i = 0; i < n; ++i) {
        result *= x;
    }
    return result;
}

inline long double MySin(long double x) {
    x = Normalize(x);
    long double term = x;
    long double sum = term;
    for (int i = 1; i < 10; ++i) {
        term *= -1.0 * x * x / ((2 * i) * (2 * i + 1));
        sum += term;
    }
    return sum;
}

long double MyCos(long double x) {
    long double term = 1.0;
    long double sum = term;
    for (int i = 1; i < 10; ++i) {
        term *= -1.0 * x * x / ((2 * i - 1) * (2 * i));
        sum += term;
    }
    return sum;
}

int main() {
    DisplayContextMenu();

    while (true) {
        long double a, b;

        while (true) {
            std::cout << "Введите число типа long double (a) - начало отрезка: ";
            if (isLongDouble(a)) {
                break;
            } else {
                std::cout << "Ошибка: введено некорректное число." << std::endl;
            }
        }

        while (true) {
            std::cout << "Введите число типа long double (b) - конец отрезка: ";
            if (isLongDouble(b)) {
                break;
            } else {
                std::cout << "Ошибка: введено некорректное число." << std::endl;
            }
        }

        const int m = 20;
 a=0;
 b=kPi/2;
        if (a >= b) {
            std::cout << "Значение A должно быть меньше значения B. Введите значения снова.\n\n";
            continue;
        }

        long double h = (b - a) / m;

        std::cout << "\nВычисляем значения функции y = sin(x) - cos(x) на отрезке ["
                  << a << ", " << b << "]:\n";

        for (int i = 0; i <= m; ++i) {
            long double x = a + i * h;
            long double y = MySin(x) - MyCos(x);
            std::cout << "При i=" << i << ", X=" << x
                      << " значение выражения равно " << y << "\n";
        }

        std::string choice;
        while (true) {
            std::cout << "Хотите выполнить ещё один расчёт? (y/n): ";
            std::cin >> choice;
            std::cin.clear();
            std::cin.ignore(10000, '\n');

            if (choice == "y" || choice == "Y" || 
                choice == "да" || choice == "ДА" ||
                choice == "yes" || choice == "YES") {
                std::cout << "\n----------------------------------------\n\n";
                break;
            } else if (choice == "n" || choice == "N" || 
                       choice == "нет" || choice == "НЕТ" ||
                       choice == "no" || choice == "NO") {
                std::cout << "Завершение программы.\n";
                return 0;
            } else {
                std::cout << "Некорректный ввод. Пожалуйста, введите 'y' или 'n'.\n";
            }
        }

        std::cout << "\n";
    }

    return 0;
}