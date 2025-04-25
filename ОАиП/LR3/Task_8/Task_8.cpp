#include <iostream>

// Функция для отображения контекстного меню
void ContextMenu() {
    std::cout << "Лабораторная работа №3, задание №8\n";
    std::cout << "Суть задания:\n";
    std::cout << "Вычисление суммы с использованием длинной арифметики\n";
    std::cout << "Выполнил студент группы 453503 Халамов Николай\n";
}

// Функция для проверки корректности ввода long long числа
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

// Функция для удвоения числа, заданного в виде строки
void doubleNumber(std::string &number) {
    int carry = 0;
    for (int i = number.length() - 1; i >= 0; --i) {
        int digit = number[i] - '0';
        int temp = digit * 2 + carry;
        number[i] = (temp % 10) + '0';
        carry = temp / 10;
    }
    if (carry) {
        number = "1" + number;
    }
}

// Функция для вычисления степени двойки
std::string degree_two(unsigned long long n) {
    std::string result = "1";
    for (unsigned long long i = 0; i < n; ++i) {
        doubleNumber(result);
    }
    return result;
}

// Функция для сложения двух больших чисел, представленных в виде строк
std::string BigSum(const std::string &num1, const std::string &num2) {
    std::string result;
    int carry = 0;
    int n1 = num1.size();
    int n2 = num2.size();
    int maxLen = n1 > n2 ? n1 : n2;

    for (int i = 0; i < maxLen; ++i) {
        int digit1 = (i < n1) ? (num1[n1 - 1 - i] - '0') : 0;
        int digit2 = (i < n2) ? (num2[n2 - 1 - i] - '0') : 0;

        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result.push_back(sum % 10 + '0');
    }

    if (carry) {
        result.push_back(carry + '0');
    }

    // Перевод результата в правильный порядок
    std::string reversedResult;
    for (int i = result.length() - 1; i >= 0; --i) {
        reversedResult += result[i];
    }
    return reversedResult;
}

// Функция для проверки, больше ли или равно первое число второму
bool isGreaterOrEqual(const std::string &num1, const std::string &num2) {
    if (num1.length() > num2.length()) return true;
    if (num1.length() < num2.length()) return false;
    return num1 >= num2;
}

// Функция для вычитания одного большого числа из другого
std::string subtractStrings(const std::string &num1, const std::string &num2) {
    bool negative = false;
    std::string a = num1;
    std::string b = num2;

    if (!isGreaterOrEqual(a, b)) {
        std::swap(a, b);
        negative = true;
    }

    std::string result = "";
    int carry = 0;

    int n1 = a.length();
    int n2 = b.length();

    for (int i = 0; i < n1; ++i) {
        int digit_a = a[n1 - 1 - i] - '0';
        int digit_b = (i < n2) ? (b[n2 - 1 - i] - '0') : 0;

        int sub = digit_a - digit_b - carry;
        if (sub < 0) {
            sub += 10;
            carry = 1;
        } else {
            carry = 0;
        }

        result += (sub + '0');
    }

    while (result.length() > 1 && result.back() == '0') {
        result.pop_back();
    }

    std::string finalResult;
    for (int i = result.length() - 1; i >= 0; --i) {
        finalResult += result[i];
    }

    if (negative) {
        finalResult = "-" + finalResult;
    }

    return finalResult;
}

// Функция для умножения двух больших чисел
std::string multiplyStrings(const std::string &num1, const std::string &num2) {
    if (num1 == "0" || num2 == "0") return "0";

    std::string result = "0";
    int n1 = num1.size();
    int n2 = num2.size();

    for (int i = n2 - 1; i >= 0; --i) {
        std::string current = "";
        int digit2 = num2[i] - '0';
        int carry = 0;

        for (int j = 0; j < n2 - 1 - i; ++j) {
            current += '0'; // Добавляем нули для текущего разряда
        }

        for (int j = n1 - 1; j >= 0; --j) {
            int digit1 = num1[j] - '0';
            int sum = digit1 * digit2 + carry;
            carry = sum / 10;
            current += (sum % 10) + '0';
        }

        if (carry > 0) {
            current += carry + '0';
        }

        // Перевод текущего результата в правильный порядок
        std::string currentResult;
        for (int k = current.length() - 1; k >= 0; --k) {
            currentResult += current[k];
        }

        result = BigSum(result, currentResult);
    }

    return result;
}

// Главная функция программы
int main() {
    while (true) {
        ContextMenu();
        long long n, q;

        while (true) {
            std::cout << "Введите число типа long long-максимальная степень двойки в сумме+1 : ";
            if (isLongLong(n)) {
                break;
            } else {
                std::cout << "Ошибка: введено некорректное число." << std::endl;
            }
        }

        while (true) {
            std::cout << "Введите число типа long long - значение a: ";
            if (isLongLong(q)) {
                break;
            } else {
                std::cout << "Ошибка: введено некорректное число." << std::endl;
            }
        }

        std::string a = std::to_string(q);
        std::string sumchet = "0", sumnechet = "0";

        for (long long i = 0; i < n; i += 2) {
            std::string degree = degree_two(i);
            sumchet = BigSum(sumchet, degree);
        }
        for (long long i = 1; i < n; i += 2) {
            std::string degree = degree_two(i);
            sumnechet = BigSum(sumnechet, degree);
        }

        std::string b = a[0] == '-' ? a.substr(1) : a;

        sumchet = multiplyStrings(sumchet, b);
        sumnechet = multiplyStrings(sumnechet, b);
        std::string razn = subtractStrings(sumchet, sumnechet);

        if (a[0] == '-' && razn[0] != '-') {
            std::cout << '-' + razn << '\n';
        } else if (a[0] == '-' && razn[0] == '-') {
            std::cout << razn.substr(1) << '\n';
        } else {
            std::cout << razn << '\n';
        }

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
                std::cout << "Завершение программы. До свидания!\n";
                return 0;
            } else {
                std::cout << "Некорректный ввод. Пожалуйста, введите 'y' или 'n'.\n";
            }
        }
    }
    return 0;
}
