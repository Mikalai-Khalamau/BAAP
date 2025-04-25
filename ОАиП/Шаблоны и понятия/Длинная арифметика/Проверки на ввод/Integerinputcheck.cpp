#include <iostream>
#include <string>

// Функция для проверки, является ли символ цифрой
bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

// Функция для проверки корректности ввода целого числа
bool isValidInteger(const std::string& input) {
    if (input.empty()) {
        return false; // Пустой ввод не является числом
    }

    size_t i = 0;
    size_t n = input.length();

    // Проверка на знак числа
    if (input[i] == '+' || input[i] == '-') {
        i++;
        if (i == n) {
            return false; // Ввод состоит только из знака без цифр
        }
    }

    bool hasDigits = false;

    // Проверка основной части числа (до 'e' или 'E')
    while (i < n && isDigit(input[i])) {
        hasDigits = true;
        i++;
    }

    // Проверка на наличие экспоненты
    if (i < n && (input[i] == 'e' || input[i] == 'E')) {
        i++; // Пропускаем 'e' или 'E'
        if (i == n) {
            return false; // 'e' без показателя степени
        }

        // Проверка на возможный знак показателя степени
        if (input[i] == '+' || input[i] == '-') {
            i++;
            if (i == n) {
                return false; // 'e' и знак без цифр
            }
        }

        bool hasExponentDigits = false;
        // Проверка показателя степени
        while (i < n && isDigit(input[i])) {
            hasExponentDigits = true;
            i++;
        }

        if (!hasExponentDigits) {
            return false; // После 'e' должны быть цифры
        }
    }

    // Проверка, что весь ввод был обработан и не осталось лишних символов
    return hasDigits && i == n;
}

int main() {
    std::string input;
    std::cout << "Введите целое число: ";
    std::cin >> input;

    if (isValidInteger(input)) {
        std::cout << "Ввод корректен: " << input << std::endl;
    } else {
        std::cout << "Некорректный ввод целого числа." << std::endl;
    }

    return 0;
}