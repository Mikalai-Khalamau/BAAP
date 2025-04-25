#include <iostream>

// Функция для отображения контекстного меню
void displayContextMenu() {
    std::cout << "Лабораторная работа №7, задание №1\n";
    std::cout << "Суть задания:\n";
    std::cout << "Перевести число из дополнительного кода в прямой код. "
              << "Предусмотреть ввод положительных и отрицательных чисел. "
              << "Длина числа не ограничена.\n";
    std::cout << "Выполнил студент группы 453503 Халамов Николай\n";
}

// Функция для проверки, хочет ли пользователь продолжить
bool askToContinue() {
    std::string choice; // Используем std::string для хранения выбора

    while (true) {
        std::cout << "Хотите выполнить ещё один расчёт? (y/n): ";
        std::cin >> choice;

        std::cin.clear();
        std::cin.ignore(10000, '\n');

        // Сравниваем с полными строками
        if (choice == "y" || choice == "Y" || choice == "да" || choice == "ДА" || 
            choice == "yes" || choice == "YES") {
            std::cout << "\n----------------------------------------\n\n";
            return true; // Возвращаем true, чтобы продолжить
        } else if (choice == "n" || choice == "N" || choice == "нет" || choice == "НЕТ" || 
                   choice == "no" || choice == "NO") {
            std::cout << "Завершение программы. До свидания!" << '\n';
            return false; // Возвращаем false, чтобы завершить
        } else {
            std::cout << "Некорректный ввод. Пожалуйста, введите 'y' или 'n'.\n";
        }
    }
}

std::string AddOne(std::string &binary) {
    std::string result = binary;
    bool checker = true;

    // Сложность O(n) - проходим по всем битам числа
    for (size_t i = result.size() - 1; i < result.size() && checker; --i) {
        if (result[i] == '0') {
            result[i] = '1';
            checker = false; // Добавление завершено
        } else {
            result[i] = '0'; // Перенос
        }
    }
    return result;
}

std::string InvertBits(std::string &dopcode) {
    std::string inverted = "1";

    // Сложность O(n) - проходим по всем битам числа (кроме первого)
    for (size_t i = 1; i < dopcode.length(); i++) {
        inverted += (dopcode[i] == '0') ? '1' : '0';
    }
    return inverted;
}

// Функция для запроса ввода числа в дополнительном коде
std::string getInputCode() {
    std::string code;

    while (true) {
        std::cout << "Введите число в виде дополнительного кода (только 0 и 1):\n";
        std::cin >> code;

        bool isValid = true; // Переменная для проверки корректности ввода
        
        // Сложность O(n) - проходим по всем символам введенного кода
        for (char bit : code) {
            if (bit != '0' && bit != '1') {
                std::cerr << "Ошибка: введены некорректные символы!\n";
                isValid = false; // Установка флага некорректности
                break; // Прерываем цикл проверки
            }
        }

        if (isValid) {
            return code; // Возвращаем корректный ввод
        } else {
            // Очищаем поток ввода, если был некорректный ввод
            std::cin.clear(); // Сбрасываем флаги ошибок
            std::cin.ignore(1000, '\n'); // Игнорируем оставшиеся неверные данные в потоке
        }
    }
}

void MainFunction(std::string &code) {
    if (code[0] == '0') {
        std::cout << "Для положительных чисел прямой код равен дополнительному\n";
        std::cout << code << '\n';
    } else {
        std::string inverted = InvertBits(code); // O(n)
        std::string direct_code = AddOne(inverted); // O(n)
        std::cout << "Прямой код:\n" << direct_code << '\n';
    }
}

int main() {
    displayContextMenu();

    do {
        std::string code = getInputCode(); // O(n)
        MainFunction(code); // O(n)
    } while (askToContinue()); // O(1) в среднем, но может быть O(n) в худшем случае из-за ввода

    return 0;
}