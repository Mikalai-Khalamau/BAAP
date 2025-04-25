#include <iostream>

// Функция для отображения контекстного меню
void displayContextMenu() {
    std::cout << "Лабораторная работа №7, задание №3\n"; // O(1)
    std::cout << "Суть задания:\n"; // O(1)
    std::cout << "Пользователь вводит основание системы счисления. "
              << "Осуществить сложение и вычитание чисел в заданной системе счисления. "
              << "Разработать функции для выполнения операции сложения и функции для выполнения операции вычитания. "
              << "В другую систему счисления не переводить. "
              << "Предусмотреть ввод положительных и отрицательных чисел. "
              << "В системах счисления больших десятичной использовать буквы по аналогии с шестнадцатеричной системой.\n"; // O(1)
    std::cout << "Выполнил студент группы 453503 Халамов Николай\n"; // O(1)
}

// Функция для проверки, хочет ли пользователь продолжить
bool askToContinue() {
    std::string choice;

    while (true) {
        std::cout << "Хотите выполнить ещё один расчёт? (y/n): "; // O(1)
        std::cin >> choice; // O(1)

        std::cin.clear(); // O(1)
        std::cin.ignore(10000, '\n'); // O(1)

        // Проверяем ввод пользователя
        if (choice == "y" || choice == "Y" || choice == "да" || choice == "ДА" || 
            choice == "yes" || choice == "YES") { // O(1)
            std::cout << "\n----------------------------------------\n\n"; // O(1)
            return true; // O(1)
        } else if (choice == "n" || choice == "N" || choice == "нет" || choice == "НЕТ" || 
                   choice == "no" || choice == "NO") { // O(1)
            std::cout << "Завершение программы. До свидания!" << '\n'; // O(1)
            return false; // O(1)
        } else {
            std::cout << "Некорректный ввод. Пожалуйста, введите 'y' или 'n'.\n"; // O(1)
        }
    }
}

// Функция для преобразования символа в его числовое значение
int charToVal(char c) {
    if (c >= '0' && c <= '9') // O(1)
        return c - '0'; // O(1)
    else if (c >= 'A' && c <= 'Z') // O(1)
        return c - 'A' + 10; // O(1)
    else if (c >= 'a' && c <= 'z') // O(1)
        return c - 'a' + 10; // O(1)
    else
        return -1; // O(1)
}

// Функция для преобразования числового значения в символ
char valToChar(int val) {
    if (val >= 0 && val <= 9) // O(1)
        return '0' + val; // O(1)
    else if (val >= 10 && val <= 35) // O(1)
        return 'A' + (val - 10); // O(1)
    else
        return '?'; // O(1)
}

// Структура для представления числа с его знаковым значением
struct Number {
    std::string digits; // Цифры числа
    int sign; // Знак числа: 1 - положительное, -1 - отрицательное

    // Конструктор для инициализации структуры
    Number(std::string s) {
        if (s[0] == '-') { // O(1)
            sign = -1; // O(1)
            digits = s.substr(1); // O(n) - n = длина строки
        } else if (s[0] == '+') { // O(1)
            sign = 1; // O(1)
            digits = s.substr(1); // O(n) - n = длина строки
        } else { // O(1)
            sign = 1; // O(1)
            digits = s; // O(n) - n = длина строки
        }
    }
};

// Функция для удаления ведущих нулей из числа
void removeLeadingZeros(std::string &num) {
    num.erase(0, std::min(num.find_first_not_of('0'), num.size() - 1)); // O(n) - n = длина строки
}

// Сравнивает абсолютные значения двух чисел
int compareAbs(std::string num1, std::string num2, int base) {
    removeLeadingZeros(num1); // O(n)
    removeLeadingZeros(num2); // O(n)

    // Сравниваем длину строк
    if (num1.length() < num2.length()) // O(1)
        return -1; // O(1)
    if (num1.length() > num2.length()) // O(1)
        return 1; // O(1)

    // Длины равны, сравниваем символы
    for (size_t i = 0; i < num1.length(); ++i) { // O(n) - n = длина строки
        int val1 = charToVal(num1[i]); // O(1)
        int val2 = charToVal(num2[i]); // O(1)
        if (val1 < val2) // O(1)
            return -1; // O(1)
        if (val1 > val2) // O(1)
            return 1; // O(1)
    }
    return 0; // O(1)
}

// Функция для сложения двух положительных чисел
std::string addPositive(std::string num1, std::string num2, int base) {
    // Убедимся, что num1 длиннее или равно num2
    if (num1.length() < num2.length()) // O(1)
        std::swap(num1, num2); // O(n) - n = длина строки

    int n1 = num1.length(); // O(1)
    int n2 = num2.length(); // O(1)

    std::string result = ""; // O(1)
    int carry = 0; // O(1)

    // Сложение чисел поразрядно
    for (int i = 0; i < n1; ++i) { // O(n1) - n1 = длина num1
        int idx1 = n1 - 1 - i; // O(1)
        int idx2 = n2 - 1 - i; // O(1)
        int val1 = charToVal(num1[idx1]); // O(1)
        int val2 = idx2 >= 0 ? charToVal(num2[idx2]) : 0; // O(1)
        int sum = val1 + val2 + carry; // O(1)
        carry = sum / base; // O(1)
        sum = sum % base; // O(1)
        result = valToChar(sum) + result; // O(n) - n = длина результата
    }
    if (carry > 0) // O(1)
        result = valToChar(carry) + result; // O(n) - n = длина результата
    return result; // O(1)
}

// Функция для вычитания двух положительных чисел
std::string subtractPositive(std::string num1, std::string num2, int base) {
    removeLeadingZeros(num1); // O(n)
    removeLeadingZeros(num2); // O(n)

    int n1 = num1.length(); // O(1)
    int n2 = num2.length(); // O(1)

    std::string result = ""; // O(1)
    int borrow = 0; // O(1)

    // Вычитание чисел поразрядно
    for (int i = 0; i < n1; ++i) { // O(n1) - n1 = длина num1
        int idx1 = n1 - 1 - i; // O(1)
        int idx2 = n2 - 1 - i; // O(1)
        int val1 = charToVal(num1[idx1]) - borrow; // O(1)
        int val2 = idx2 >= 0 ? charToVal(num2[idx2]) : 0; // O(1)

        // Если val1 меньше val2, занимаем
        if (val1 < val2) { // O(1)
            val1 += base; // O(1)
            borrow = 1; // O(1)
        } else {
            borrow = 0; // O(1)
        }

        int diff = val1 - val2; // O(1)
        result = valToChar(diff) + result; // O(n) - n = длина результата
    }
    removeLeadingZeros(result); // O(n)
    if (result == "") // O(1)
        result = "0"; // O(1)
    return result; // O(1)
}

// Функция для сложения двух чисел с учётом их знаков
std::string add(std::string s1, std::string s2, int base) {
    Number num1(s1); // O(n1) - n1 = длина s1
    Number num2(s2); // O(n2) - n2 = длина s2
    std::string result; // O(1)
    int res_sign = 1; // O(1)

    if (num1.sign == num2.sign) { // O(1)
        // Оба числа имеют одинаковый знак
        result = addPositive(num1.digits, num2.digits, base); // O(n) - n = длина результата
        res_sign = num1.sign; // O(1)
    } else { // O(1)
        // Числа имеют разные знаки
        int cmp = compareAbs(num1.digits, num2.digits, base); // O(n) - n = длина чисел
        if (cmp == 0) { // O(1)
            result = "0"; // O(1)
            res_sign = 1; // O(1)
        } else if (cmp > 0) { // O(1)
            result = subtractPositive(num1.digits, num2.digits, base); // O(n) - n = длина результата
            res_sign = num1.sign; // O(1)
        } else { // O(1)
            result = subtractPositive(num2.digits, num1.digits, base); // O(n) - n = длина результата
            res_sign = num2.sign; // O(1)
        }
    }
    if (res_sign == -1 && result != "0") // O(1)
        result = "-" + result; // O(n) - n = длина результата
    return result; // O(1)
}

// Функция для вычитания двух чисел с учётом их знаков
std::string subtract(std::string s1, std::string s2, int base) {
    Number num1(s1); // O(n1) - n1 = длина s1
    Number num2(s2); // O(n2) - n2 = длина s2
    std::string result; // O(1)
    int res_sign = 1; // O(1)

    if (num1.sign == num2.sign) { // O(1)
        // Оба числа имеют одинаковый знак
        int cmp = compareAbs(num1.digits, num2.digits, base); // O(n) - n = длина чисел
        if (cmp == 0) { // O(1)
            result = "0"; // O(1)
            res_sign = 1; // O(1)
        } else if (cmp > 0) { // O(1)
            result = subtractPositive(num1.digits, num2.digits, base); // O(n) - n = длина результата
            res_sign = num1.sign; // O(1)
        } else { // O(1)
            result = subtractPositive(num2.digits, num1.digits, base); // O(n) - n = длина результата
            res_sign = -num1.sign; // O(1)
        }
    } else { // O(1)
        // Числа имеют разные знаки
        result = addPositive(num1.digits, num2.digits, base); // O(n) - n = длина результата
        res_sign = num1.sign; // O(1)
    }

    if (res_sign == -1 && result != "0") // O(1)
        result = "-" + result; // O(n) - n = длина результата
    return result; // O(1)
}

// Функция для проверки, является ли строка допустимым числом в данной системе счисления
bool isValidNumber(std::string s, int base) {
    Number num(s); // O(n) - n = длина строки

    // Проверяем каждую цифру на допустимость
    for (char c : num.digits) { // O(n) - n = длина digits
        int val = charToVal(c); // O(1)
        if (val == -1 || val >= base) // O(1)
            return false; // O(1)
    }
    return true; // O(1)
}

// Функция для преобразования строки в верхний регистр
void toUpperCase(std::string &s) {
    for (char &c : s) { // O(n) - n = длина строки
        if (c >= 'a' && c <= 'z') { // O(1)
            c = c - 'a' + 'A'; // O(1)
        }
    }
}

// Основная функция
int main() {
    displayContextMenu(); // O(1)
    do {
        int base; // Основание системы счисления
        while (true) {
            std::cout << "Введите основание системы счисления (от 2 до 36): "; // O(1)
            std::cin >> base; // O(1)

            // Проверка на допустимость основания
            if (base >= 2 && base <= 36) { // O(1)
                break; // O(1)
            } else {
                std::cout << "Недопустимое основание." << '\n'; // O(1)
                std::cin.clear(); // O(1)
                std::cin.ignore(10000, '\n'); // O(1)
            }
        }

        std::string num1, num2; // Переменные для двух чисел

        // Ввод первого числа с проверкой
        while (true) {
            std::cout << "Введите первое число: "; // O(1)
            std::cin >> num1; // O(1)
            toUpperCase(num1); // O(n) - n = длина num1

            // Проверка на допустимость введённого числа
            if (isValidNumber(num1, base)) { // O(n) - n = длина num1
                break; // O(1)
            } else {
                std::cout << "Число недействительно в заданной системе счисления." << '\n'; // O(1)
                std::cin.clear(); // O(1)
                std::cin.ignore(10000, '\n'); // O(1)
            }
        }

        // Ввод второго числа с проверкой
        while (true) {
            std::cout << "Введите второе число: "; // O(1)
            std::cin >> num2; // O(1)
            toUpperCase(num2); // O(n) - n = длина num2

            // Проверка на допустимость введённого числа
            if (isValidNumber(num2, base)) { // O(n) - n = длина num2
                break; // O(1)
            } else {
                std::cout << "Число недействительно в заданной системе счисления." << '\n'; // O(1)
                std::cin.clear(); // O(1)
                std::cin.ignore(10000, '\n'); // O(1)
            }
        }

        // Выполняем сложение и вычитание
        std::string sum = add(num1, num2, base); // O(n) - n = длина результата
        std::string diff = subtract(num1, num2, base); // O(n) - n = длина результата

        // Выводим результаты
        std::cout << "Сумма: " << sum << '\n'; // O(1)
        std::cout << "Разность: " << diff << '\n'; // O(1)
    } while (askToContinue()); // O(1)

    return 0; // O(1)
}