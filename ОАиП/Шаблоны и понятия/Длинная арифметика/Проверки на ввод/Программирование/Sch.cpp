#include <iostream>
#include <string>

using namespace std;

void ContextMenu() {
    std::cout << "Лабораторная работа №3, задание №8\n";
    std::cout << "Суть задания:\n";
    std::cout << "Вычисление суммы с использованием длинной арифметики\n";
    std::cout << "Выполнил студент группы 453503 Халамов Николай\n";
}

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

void doubleNumber(string &number) {
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

string degree_two(unsigned long long n) {
    string result = "1";
    for (unsigned long long i = 0; i < n; ++i) {
        doubleNumber(result);
    }
    return result;
}

void reverseString(string &s) {
    int n = s.length();
    for (int i = 0; i < n / 2; ++i) {
        swap(s[i], s[n - i - 1]);
    }
}

std::string BigSum(const std::string &num1, const std::string &num2) {
    std::string result;
    int carry = 0;
    int n1 = num1.size();
    int n2 = num2.size();
    int maxLen = (n1 > n2) ? n1 : n2;

    for (int i = 0; i < maxLen; ++i) {
        int digit1 = (i < n1) ? (num1[n1 - 1 - i] - '0') : 0;
        int digit2 = (i < n2) ? (num2[n2 - 1 - i] - '0') : 0;

        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result += (sum % 10) + '0';
    }

    if (carry) {
        result += carry + '0';
    }

    reverseString(result); // Используем собственную функцию реверса
    return result;
}

bool isGreaterOrEqual(const std::string &num1, const std::string &num2) {
    if (num1.length() > num2.length()) return true;
    if (num1.length() < num2.length()) return false;
    return num1 >= num2;
}

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

    // Убираем ведущие нули
    while (result.length() > 1 && result.back() == '0') {
        result.pop_back();
    }

    reverseString(result); // Используем собственную функцию реверса

    if (negative) {
        result = "-" + result;
    }

    return result;
}

std::string multiplyStrings(const std::string &num1, const std::string &num2) {
    if (num1 == "0" || num2 == "0") return "0";

    int n1 = num1.size();
    int n2 = num2.size();
    string result(n1 + n2, '0');

    for (int i = n1 - 1; i >= 0; --i) {
        int carry = 0;
        int digit1 = num1[i] - '0';

        for (int j = n2 - 1; j >= 0; --j) {
            int digit2 = num2[j] - '0';
            int sum = (digit1 * digit2) + (result[i + j + 1] - '0') + carry;
            carry = sum / 10;
            result[i + j + 1] = (sum % 10) + '0';
        }

        result[i] += carry; // добавляем оставшийся перенос
    }

    // Убираем ведущие нули
    size_t startpos = result.find_first_not_of('0');
    if (startpos != std::string::npos) {
        return result.substr(startpos); // Возвращаем строку без ведущих нулей
    }
    
    return "0"; // Если все нули
}

int main() {
    while (true) {
        ContextMenu();
        long long n, q;

        while (true) {
            std::cout << "Введите число типа long long - степень двойки: ";
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

        string a = std::to_string(q);
        string sumchet = "0", sumnechet = "0";

        for (long long i = 0; i < n; i += 2) {
            string degree = degree_two(i);
            sumchet = BigSum(sumchet, degree);
        }
        for (long long i = 1; i < n; i += 2) {
            string degree = degree_two(i);
            sumnechet = BigSum(sumnechet, degree);
        }

        string b = a[0] == '-' ? a.substr(1) : a;

        sumchet = multiplyStrings(sumchet, b);
        sumnechet = multiplyStrings(sumnechet, b);
        string razn = subtractStrings(sumchet, sumnechet);
std::cout<<"Итоговое значение выражения: ";
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