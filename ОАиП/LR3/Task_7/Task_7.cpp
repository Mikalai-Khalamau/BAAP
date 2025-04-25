#include <iostream>

void ContextMenu() {
    std::cout << "Лабораторная работа №3, задание №7\n";
    std::cout << "Суть задания:\n";
    std::cout << "Нахождение всех чисел Армстронга, меньше введённого пользователем числа\n";
    std::cout << "Выполнил студент группы 453503 Халамов Николай\n";
}

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
    return true;
}

int pow(int a, int b) {
    int result = 1;
    for (int i = 0; i < b; i++) {
        result *= a;
    }
    return result;
}

void armstrong(int n) {
    int f = n, digitnum = 0;
    while (f >= 1) {
        f /= 10;
        digitnum++;
    }

    int w = n;
    int s = 0;
    for (int i = 0; i < digitnum; i++) {
        s += pow(w % 10, digitnum);
        w /= 10;
    }

    if (s == n) {
        std::cout << s << "\n";
    }
}

int main() {
    while (true) {
        ContextMenu();
        long double h;
        while (true) {
            std::cout << "Введите число типа long double (h) 16-byte: ";
            if (isLongDouble(h)) {
                break;
            } else {
                std::cout << "Ошибка: введено некорректное число." << std::endl;
            }
        }

        if (h <= 1) {
            std::cout << "Чисел Армстронга меньше заданного числа не существует";
        } else {
            std::cout << "Все числа Армстронга, меньшие чем заданное вами число " << h << ": " << '\n';
            for (int i = 1; i < h; i++) {
                armstrong(i);
            }
        }

        std::string choice;
        while (true) {
            std::cout << "Хотите выполнить ещё один расчёт? (y/n): ";
            std::cin >> choice;
            std::cin.clear();
            std::cin.ignore(10000, '\n');

            if (choice == "y" || choice == "Y" || choice == "да" || choice == "ДА" ||
                choice == "yes" || choice == "YES") {
                std::cout << "\n----------------------------------------\n\n";
                break;
            } else if (choice == "n" || choice == "N" || choice == "нет" || choice == "НЕТ" ||
                       choice == "no" || choice == "NO") {
                std::cout << "Завершение программы. До свидания!\n";
                return 0;
            } else {
                std::cout << "Некорректный ввод. Пожалуйста, введите 'y' или 'n'.\n";
            }
        }

        std::cout << "\n";
    }
}
