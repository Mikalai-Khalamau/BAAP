#include <iostream>

void ContextMenu() {
    std::cout << "Лабораторная работа №3, задание №6\n";
    std::cout << "Суть задания:\n";
    std::cout << "Из величин, определяемых выражениями a = sinx, b = cosx, c = ln|x| при заданном х, "
                 "определить и вывести на экран дисплея минимальное значение.\n";
    std::cout << "Выполнил студент группы 453503 Халамов Николай\n";
}

long double kPi = 3.14159265358979323846264338327950288419716939937510 * 2;

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

    return true; // Ввод корректен
}

long double my_abs(long double x) {
    return (x < 0) ? -x : x;
}

long double normalization(long double x) {
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
        
       while (x < kPi) {
            long double k = 1;
            while (x + k * 2 * kPi < 0) {
                k = k * 2;
            }
            x = x + k * kPi;
        }
        return x;
    }
}

long double my_sin(long double y) {
    long double x = normalization(y);
    long double term = x; 
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
    if (y<0) y=-y;
    long double x = normalization(y);
    long double term = 1.0; 
    long double sum = term;
    int n = 1;
    const int TERMS = 10;

    for (int i = 1; i < TERMS; ++i) {
        term *= -x * x / ((2 * i - 1) * (2 * i));
        sum += term;
    }
    return sum;
}

long double ln(long double x) {
    x = my_abs(x);
    int k = 0;
    while (x > 1.5) {
        x /= 2.0;
        k++;
    }
    while (x < 0.5) {
        x *= 2.0;
        k--;
    }

    x = x - 1.0;
    double term = x;
    double sum = term;
    const int TERMS = 100;

    for (int n = 2; n <= TERMS; ++n) {
        term *= -x * (n - 1) / n;
        sum += term;
    }

    const double LN2 = 0.6931471805599453;
    sum += k * LN2;
    return sum;
}

int main() {
    ContextMenu();
    while (true) {
        long double x;
        while (true) { 
            std::cout << "Введите число типа long double (x, не равное нулю): ";
            if (isLongDouble(x) && x != 0) break;
            std::cout << "Ошибка: введено некорректное число или ноль." << std::endl;
        }

        long double a = my_sin(x);
        long double b = my_cos(x);
        long double c = ln(my_abs(x)); // Логарифм по модулю

        std::cout << "Значение sin(x) равно " << a << "\n";
        std::cout << "Значение cos(x) равно " << b << "\n";
        std::cout << "Значение ln(|x|) равно " << c << "\n";
std::cout<<normalization(x)<<'\n';
        // Определение минимального значения
        long double min_value = a; // Предположим, что a минимальное
        if (b < min_value) min_value = b;
        if (c < min_value) min_value = c;

        std::cout << "Минимальное значение среди a = sin(x), b = cos(x), c = ln|x|: " << min_value << "\n";

        // Запрос на повторный ввод или выход
        char choice;
        std::cout << "\nХотите выполнить ещё одно вычисление? (y/n): ";
        std::cin >> choice;
        std::cin.ignore(1000, '\n'); // Очистка буфера ввода

        if (choice != 'y' && choice != 'Y') {
            std::cout << "Выход из программы.\n";
            break;
        }

        std::cout << "\n";
    }
    return 0;
}
