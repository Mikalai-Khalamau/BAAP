#include <iostream>

void ContextMenu() {
    std::cout << "Лабораторная работа №3, задание №5\n";
    std::cout << "Суть задания:\n";
    std::cout << "Запросить у пользователя, на сколько частей разделить область поиска корня, "
                 "вычислить шаг, с которым нужно проходить значения, пройти в цикле нужные значения, "
                 "найти корень и вывести его.\n";
    std::cout << "Выполнил студент группы 453503 Халамов Николай\n";
}

constexpr long double kPi = 3.14159265358979323846264338327950288419716939937510;
long double p = kPi * 2;

long double normalization(long double x) {
    if (x >= 0) { 
        while (x > p) {
            long double k = 1;
            while (x - k * 2 * p > 0) {
                k = k * 2;
            }
            x = x - k * p;
        }
        return x;
    } else {
        x = x * (-1);
        while (x > p) {
            long double k = 1;
            while (x - k * p > 0) {
                k = k * p;
            }
            x = x - k;
        }
        return x * (-1);
    }
}

// Функция для вычисления абсолютного значения
long double my_abs(long double x) {
    return (x < 0) ? -x : x;
}

long double my_sin(long double y) {
    long double x = normalization(y);
    long double term = x; // Первый член ряда
    long double sum = term;
    int n = 1;
    const int MAX_ITERATIONS = 200;
    const long double EPSILON = 1e-10;

    while (n < MAX_ITERATIONS) {
        term *= -1 * x * x / ((2 * n) * (2 * n + 1));
        sum += term;
        if (my_abs(term) < EPSILON) break;
        n++;
    }
    
    return sum;
}

long double my_cos(long double y) {
    long double x = normalization(y);
    long double term = 1.0; // Первый член ряда
    long double sum = term;
    int n = 1;
    const int TERMS = 10; // Количество членов ряда

    for (int i = 1; i < TERMS; ++i) {
        term *= -x * x / ((2 * i - 1) * (2 * i));
        sum += term;
    }
    return sum;
}

// Реализация функции тангенса
double tang(double x) {
    double cosx = my_cos(x);
    if (my_abs(cosx) < 1e-10) { // Проверка на близость к разрыву
        return (x > 0) ? 1e10 : -1e10; // Возвращаем большое число вместо бесконечности
    }
    return my_sin(x) / cosx;
}

bool isInt(int &number) {
    std::cin >> number;

    // Проверяем, успешно ли прошло считывание числа
    if (std::cin.fail()) {
        std::cin.clear(); // Сбрасываем состояние ошибки
        std::cin.ignore(10000, '\n'); // Игнорируем оставшийся ввод до конца строки
        return false;
    }

    // Проверяем, остались ли лишние символы после ввода числа
    if (std::cin.peek() != '\n') {
        std::cin.clear(); // Сбрасываем состояние ошибки
        std::cin.ignore(10000, '\n'); // Игнорируем оставшийся ввод до конца строки
        return false;
    }

    return true; // Ввод корректен
}

int main() {
    ContextMenu();
    while (true) {
        int parts;
        
        while (true) { 
            std::cout << "Введите число типа int (на сколько частей разделить область поиска корня): ";
            if (isInt(parts)) break;
            std::cout << "Ошибка: введено некорректное число." << std::endl;
        }

        double start = -1;
        double end = 1;
        double step = (end - start) / parts;

        // Инициализация переменных для поиска корня
        double min_abs_f = 1e20;
        double root = start;

        for (double i = start; i <= end; i += step) {
            double fi = my_sin(i) + tang(i) - 1.0 / (1.0 + i * i);
            if (my_abs(fi) < min_abs_f) {
                min_abs_f = my_abs(fi);
                root = i;
            }
        }

        std::cout.precision(10);
        std::cout << "Корень равен " << root << "\n";
        std::cout << "Значение функции в корне: f(x) = " << (my_sin(root) + tang(root) - 1.0 / (1.0 + root * root)) << "\n";

        std::string choice;
        while (true) {
            std::cout << "Хотите выполнить ещё один расчёт? (y/n): ";
            std::cin >> choice;
            std::cin.clear(); // Сбрасываем флаг ошибки
            std::cin.ignore(10000, '\n'); // Игнорируем оставшийся ввод

            if (choice == "y" || choice == "Y" || 
                choice == "да" || choice == "ДА" ||
                choice == "yes" || choice == "YES") {
                std::cout << "\n----------------------------------------\n\n";
                break;
            } else if (choice == "n" || choice == "N" || 
                       choice == "нет" || choice == "НЕТ" ||
                       choice == "no" || choice == "NO") {
                std::cout << "Завершение программы. До свидания!\n";
                return 0;
            } else {
                std::cout << "Некорректный ввод. Пожалуйста, введите 'y' или 'n'.\n";
            }
        }

        std::cout << "\n";
    }

    return 0;
}
