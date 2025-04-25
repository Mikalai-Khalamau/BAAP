#include <iostream>
#include <string>


// Функция для проверки, является ли строка корректным положительным числом
bool isPositiveNumber(const std::string& str) {
    int len = str.length();
    int i = 0;

    // Пустая строка не является числом
    if (len == 0) return false;

    // Проверка на наличие знака '+'
    if (str[i] == '+') {
        i++;
        if (i == len) return false; // Строка не должна состоять только из '+'
    }

    bool hasDigits = false;    // Флаг наличия цифр перед экспонентой
    bool hasDecimal = false;   // Флаг наличия десятичной точки
    bool hasExponent = false;  // Флаг наличия экспоненты

    // Обработка основной части числа (до 'e' или 'E')
    while (i < len) {
        char c = str[i];
        if (std::isdigit(c)) {
            hasDigits = true;
            i++;
        }
        else if (c == '.') {
            if (hasDecimal || hasExponent) return false; // Только одна десятичная точка и до экспоненты
            hasDecimal = true;
            i++;
        }
        else if (c == 'e' || c == 'E') {
            if (hasExponent || !hasDigits) return false; // Только одна экспонента и должны быть цифры перед ней
            hasExponent = true;
            i++;
            if (i == len) return false; // 'e' должно быть после цифр

            // Проверка на знак после 'e' или 'E'
            if (str[i] == '+' || str[i] == '-') {
                i++;
                if (i == len) return false; // После знака должны быть цифры
            }

            bool hasExpDigits = false; // Флаг наличия цифр в экспоненте
            while (i < len) {
                if (std::isdigit(str[i])) {
                    hasExpDigits = true;
                    i++;
                }
                else {
                    return false; // Недопустимые символы в экспоненте
                }
            }
            if (!hasExpDigits) return false;
            break; // Экспонента должна быть в конце строки
        }
        else {
            return false; // Недопустимый символ
        }
    }

    return hasDigits;
}

int main() {
    std::string input;
    while (true) {
        std::cout << "Введите положительное число: ";
        std::cin >> input;

        if (isPositiveNumber(input)) {
            std::cout << "Вы ввели корректное положительное число: " << input << std::endl;
            break; // Выход из цикла при корректном вводе
        }
        else {
            std::cout << "Неправильный ввод. Попробуйте снова.\n";
        }
    }
    return 0;
}
