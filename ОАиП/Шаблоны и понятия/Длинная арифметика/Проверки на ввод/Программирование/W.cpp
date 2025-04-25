#include <iostream>
#include <limits>

bool isLongDouble() {
    long double number;
    std::cin >> number;

    // Проверяем, успешно ли прошло считывание числа
    if (std::cin.fail()) {
        // Если не успешно, очищаем состояние потока и возвращаем false
        std::cin.clear(); // Сбрасываем состояние ошибки
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Игнорируем оставшийся ввод
        return false;
    }

    // Проверяем, остались ли лишние символы после ввода числа
    if (std::cin.peek() != '\n') {
        // Если следующий символ не перевод строки, значит введено что-то лишнее
        std::cin.clear(); // Сбрасываем состояние ошибки
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Игнорируем оставшийся ввод
        return false;
    }

    return true; // Ввод корректен
}

int main() {
    std::cout << "Введите число типа long double: ";

    if (isLongDouble()) {
        std::cout << "Вы ввели корректное число." << std::endl;
    } else {
        std::cout << "Ошибка: введено некорректное число." << std::endl;
    }

    return 0;
}