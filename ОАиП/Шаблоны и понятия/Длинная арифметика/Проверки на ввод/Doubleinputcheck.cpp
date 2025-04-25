#include <iostream>
#include <string>


bool isValidLongDouble(const std::string& str) {
    size_t i = 0;
    size_t n = str.length();

    // Пропускаем начальные пробелы
    while (i < n && std::isspace(str[i])) {
        i++;
    }

    // Проверяем на наличие знака '+' или '-'
    if (i < n && (str[i] == '+' || str[i] == '-')) {
        i++;
    }

    bool hasDigits = false;

    // Числа перед десятичной точкой
    while (i < n && std::isdigit(str[i])) {
        i++;
        hasDigits = true;
    }

    // Десятичная точка и числа после нее
    if (i < n && str[i] == '.') {
        i++;
        // Должна быть хотя бы одна цифра после точки, если не было цифр до нее
        if (!hasDigits && (i >= n || !std::isdigit(str[i]))) {
            return false;
        }
        while (i < n && std::isdigit(str[i])) {
            i++;
            hasDigits = true;
        }
    }

    // Проверяем на экспоненциальную часть
    if (i < n && (str[i] == 'e' || str[i] == 'E')) {
        i++;
        // Возможный знак '+' или '-'
        if (i < n && (str[i] == '+' || str[i] == '-')) {
            i++;
        }
        bool hasExpDigits = false;
        // Цифры в экспоненциальной части
        if (i >= n || !std::isdigit(str[i])) {
            return false;
        }
        while (i < n && std::isdigit(str[i])) {
            i++;
            hasExpDigits = true;
        }
        if (!hasExpDigits) {
            return false;
        }
    }

    // Пропускаем конечные пробелы
    while (i < n && std::isspace(str[i])) {
        i++;
    }

    // Проверяем, что достигли конца строки
    return i == n && hasDigits;
}

int main() {
    std::string input;
    std::cout << "Введите число: ";
    std::getline(std::cin, input);

    if (isValidLongDouble(input)) {
        std::cout << "Корректное число типа long double." << std::endl;
    } else {
        std::cout << "Некорректный ввод." << std::endl;
    }

    return 0;
}