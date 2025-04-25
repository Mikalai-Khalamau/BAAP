#include <iostream>

// Функция для дополнения двоичного числа до ближайшей степени двойки
std::string PadToNextPowerOfTwo(const std::string& binary) {
    int length = binary.length();
    int nextPowerOfTwo = 1;

    // Находим следующую степень двойки, большую или равную длине
    while (nextPowerOfTwo < length) {
        nextPowerOfTwo *= 2; // O(log n), где n — длина двоичной строки
    }
    // Увеличиваем на одну степень двойки, чтобы перейти к следующей
    nextPowerOfTwo *= 2; // O(1)

    return std::string(nextPowerOfTwo - length, '0') + binary; // O(n), где n — длина двоичной строки
}

// Функция для удвоения числа, заданного в виде строки
void doubleNumber(std::string &number) {
    int carry = 0;
    for (int i = number.length() - 1; i >= 0; --i) {
        int digit = number[i] - '0';
        int temp = digit * 2 + carry;
        number[i] = (temp % 10) + '0'; // O(1)
        carry = temp / 10; // O(1)
    }

    if (carry) {
        number = "1" + number; // O(n), где n — длина числа
    }
}

// Функция для вычисления степени двойки
std::string degree_two(unsigned long long n) {
    std::string result = "1";
    for (unsigned long long i = 0; i < n; ++i) {
        doubleNumber(result); // O(n), где n — длина числа
    }
    return result; // O(1)
}

// Функция для сложения двух больших чисел, представленных в виде строк
std::string BigSum(const std::string &num1, const std::string &num2) {
    std::string result;
    int carry = 0;
    int n1 = num1.size();
    int n2 = num2.size();
    int maxLen = std::max(n1, n2); // O(1)

    for (int i = 0; i < maxLen; ++i) {
        int digit1 = (i < n1) ? (num1[n1 - 1 - i] - '0') : 0; // O(1)
        int digit2 = (i < n2) ? (num2[n2 - 1 - i] - '0') : 0; // O(1)

        int sum = digit1 + digit2 + carry; // O(1)
        carry = sum / 10; // O(1)
        result.push_back(sum % 10 + '0'); // O(1)
    }

    if (carry) {
        result.push_back(carry + '0'); // O(1)
    }

    // Перевод результата в правильный порядок
    std::string reversedResult; // O(1)
    for (int i = result.length() - 1; i >= 0; --i) {
        reversedResult += result[i]; // O(n), где n — длина результата
    }
    return reversedResult; // O(1)
}

// Функция для отображения контекстного меню
void displayContextMenu() {
    std::cout << "Лабораторная работа №7, задание №2\n"; // O(1)
    std::cout << "Суть задания:\n"; // O(1)
    std::cout << "Найдите сумму двоичных чисел, заданных в естественной форме. "
              << "Сложение выполните в дополнительном коде. "
              << "Ответ выразите в естественной форме. "
              << "Предусмотреть ввод положительных и отрицательных чисел. "
              << "Длина числа не ограничена.\n"; // O(1)
    std::cout << "Выполнил студент группы 453503 Халамов Николай\n"; // O(1)
}

// Функция для проверки, хочет ли пользователь продолжить
bool askToContinue() {
    std::string choice; // Используем std::string для хранения выбора

    while (true) {
        std::cout << "Хотите выполнить ещё один расчёт? (y/n): "; // O(1)
        std::cin >> choice; // O(1)

        std::cin.clear(); // O(1)
        std::cin.ignore(10000, '\n'); // O(1)

        // Сравниваем с полными строками
        if (choice == "y" || choice == "Y" || choice == "да" || choice == "ДА" || 
            choice == "yes" || choice == "YES") {
            std::cout << "\n----------------------------------------\n\n"; // O(1)
            return true; // Возвращаем true, чтобы продолжить
        } else if (choice == "n" || choice == "N" || choice == "нет" || choice == "НЕТ" || 
                   choice == "no" || choice == "NO") {
            std::cout << "Завершение программы. До свидания!" << '\n'; // O(1)
            return false; // Возвращаем false, чтобы завершить
        } else {
            std::cout << "Некорректный ввод. Пожалуйста, введите 'y' или 'n'.\n"; // O(1)
        }
    }
}

// Функция для преобразования десятичного числа в двоичную строку
std::string DecimalToBinary(const std::string& decimalStr) {
    bool isNegative = (decimalStr[0] == '-'); // O(1)
    std::string binary; // O(1)

    // Обрабатываем абсолютное значение
    std::string decimal = isNegative ? decimalStr.substr(1) : decimalStr; // O(n), где n — длина строки decimalStr

    // Если число равно 0
    if (decimal == "0") {
        return "0"; // Всегда возвращаем "0" независимо от знака
    }

    // Преобразуем десятичное число в двоичное
    unsigned long long number = 0; // O(1)
    for (char c : decimal) {
        number = number * 10 + (c - '0'); // O(n), где n — длина строки decimal
    }

    // Переводим число в двоичную систему
    while (number > 0) {
        binary = char((number % 2) + '0') + binary; // O(n), где n — длина двоичной строки
        number /= 2; // O(1)
    }

    return binary; // O(1)
}

// Функция для добавления единицы к двоичному числу
std::string AddOne(const std::string &binary) {
    std::string result = binary; // O(n), где n — длина двоичной строки
    bool carry = true; // Перенос

    for (int i = result.size() - 1; i >= 0 && carry; --i) {
        if (result[i] == '0') {
            result[i] = '1'; // Если находим 0, меняем его на 1 и заканчиваем
            carry = false; // O(1)
        } else {
            result[i] = '0'; // Меняем 1 на 0 и продолжаем
        }
    }

    return result; // O(1)
}

// Функция для получения корректного ввода числа
std::string GetValidNumberInput() {
    std::string input; // O(1)
    bool isValid = false; // O(1)

    while (!isValid) {
        std::cout << "Введите число: "; // O(1)
        std::getline(std::cin, input); // Используем getline для получения строки // O(n), где n — длина ввода

        // Проверка на корректность числа
        isValid = true; // Предполагаем, что ввод корректный
        if (input.empty()) {
            isValid = false; // O(1)
        } else if (input[0] == '-') {
            // Проверяем остальные символы для отрицательного числа
            if (input.size() == 1) {
                isValid = false; // O(1)
            } else {
                for (size_t i = 1; i < input.size(); ++i) {
                    if (!isdigit(input[i])) {
                        isValid = false; // O(n), где n — длина ввода
                        break; // O(1)
                    }
                }
            }
        } else {
            // Проверяем все символы для положительного числа
            for (char c : input) {
                if (!isdigit(c)) {
                    isValid = false; // O(n), где n — длина ввода
                    break; // O(1)
                }
            }
        }

        if (!isValid) {
            std::cout << "Ошибка: неверное значение, попробуйте еще раз." << std::endl; // O(1)
            // Очищаем поток ввода, если был некорректный ввод
            std::cin.clear(); // O(1)
            std::cin.ignore(1000, '\n'); // O(1)
        }
    }

    return input; // Возвращаем корректный ввод
}

// Функция для инвертирования битов (кроме первого)
std::string InvertBits(const std::string &code) {
    std::string inverted = ""; // O(1)

    // Инвертируем остальные биты
    for (size_t i = 0; i < code.length(); i++) {
        inverted += (code[i] == '0') ? '1' : '0'; // O(n), где n — длина кода
    }
    return inverted; // O(1)
}

// Функция для сложения двоичных чисел в строковом виде
std::string BinarySum(const std::string& a, const std::string& b) {
    std::string result; // O(1)
    int carry = 0; // Перенос

    // Определяем длины строк
    int maxLength = std::max(a.size(), b.size()); // O(1)
    std::string aPadded = std::string(maxLength - a.size(), '0') + a; // O(n), где n — длина a
    std::string bPadded = std::string(maxLength - b.size(), '0') + b; // O(n), где n — длина b

    // Сложение с конца строк
    for (int i = maxLength - 1; i >= 0; --i) {
        int sum = carry; // Начинаем с переноса

        sum += aPadded[i] - '0'; // O(1)
        sum += bPadded[i] - '0'; // O(1)

        // Определяем текущий бит и перенос
        result = char((sum % 2) + '0') + result; // O(n), где n — длина результата
        carry = sum / 2; // O(1)
    }

    return result; // O(1)
}

// Функция для преобразования двоичного числа в десятичную строку
std::string BinaryToDecimal(const std::string& binary) {
    std::string result = "0"; // O(1)
    std::string powerOfTwo = "1"; // Степень двойки // O(1)

    for (size_t i = 0; i < binary.length(); ++i) {
        if (binary[binary.length() - 1 - i] == '1') {
            result = BigSum(result, powerOfTwo); // O(n), где n — длина результата
        }
        powerOfTwo = BigSum(powerOfTwo, powerOfTwo); // O(n), где n — длина powerOfTwo
    }

    return result; // O(1)
}

// Основная функция для инкапсуляции логики
void MainFunction() {
    std::string a = GetValidNumberInput(); // Получаем первое число
    std::string b = GetValidNumberInput(); // Получаем второе число

    std::string binary_a = DecimalToBinary(a[0] == '-' ? a.substr(1) : a); // O(n), где n — длина a
    std::string binary_b = DecimalToBinary(b[0] == '-' ? b.substr(1) : b); // O(n), где n — длина b

    // Дополняем двоичные числа до следующей степени двойки
    binary_a = PadToNextPowerOfTwo(binary_a); // O(n), где n — длина binary_a
    binary_b = PadToNextPowerOfTwo(binary_b); // O(n), где n — длина binary_b

    // Уравниваем длины, добавляя нули
    while (binary_a.length() != binary_b.length()) { // O(m), где m — максимальная длина
        if (binary_a.length() < binary_b.length()) {
            binary_a = "0" + binary_a; // O(n), где n — длина binary_a
        } else {
            binary_b = "0" + binary_b; // O(n), где n — длина binary_b
        }
    }

    // Обработка дополнительного кода для отрицательных чисел
    std::string dop_code_a = (a[0] == '-') ? AddOne(InvertBits(binary_a)) : binary_a; // O(n), где n — длина binary_a
    std::string dop_code_b = (b[0] == '-') ? AddOne(InvertBits(binary_b)) : binary_b; // O(n), где n — длина binary_b

    // Суммирование двух двоичных чисел в дополнительном коде
    std::string sum = BinarySum(dop_code_a, dop_code_b); // O(n), где n — длина dop_code_a или dop_code_b
    std::cout << "Сумма чисел в дополнительном коде: " << sum << '\n'; // O(1)

    // Обработка суммы для перевода обратно в десятичную форму
    std::string result; // O(1)
    if (sum[0] == '1') { // Если сумма отрицательная
        std::string direct_code_sum = BinaryToDecimal(AddOne(InvertBits(sum))); // O(n), где n — длина sum
        result = "-" + direct_code_sum; // O(n), где n — длина direct_code_sum
    } else { // Если сумма положительная
        result = BinaryToDecimal(sum); // O(n), где n — длина sum
    }

    std::cout << "Сумма равна " << result << '\n'; // O(1)
}

int main() {
    displayContextMenu(); // О(1), отображаем контекстное меню

    do {
        MainFunction(); // О(1), выполняем основной расчет
    } while (askToContinue()); // O(1), спрашиваем, хочет ли пользователь продолжить

    return 0; // O(1)
}