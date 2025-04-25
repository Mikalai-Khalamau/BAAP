#include <Windows.h>
#include <iostream>

#define ll long long

// Функция для отображения контекстного меню
void displayContextMenu() {
    std::cout << "Лабораторная работа №5, задание №3\n";
    std::cout << "Суть задания:\n";
    std::cout << "Создать одномерный динамический массив целых чисел. Проверить, "
        "существует ли хотя бы один элемент Ai, для которого Ai ≤ i^2.\n";
}

// Функция для проверки корректного ввода числа
bool isLongLong(ll& number) {
    std::cin >> number;
    if (std::cin.fail()) {
        std::cin.clear(); // Сбрасываем состояние потока
        std::cin.ignore(10000, '\n'); // Игнорируем неверный ввод
        return false;
    }
    if (std::cin.peek() != '\n') {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return false;
    }
    return true;
}

// Функция для повторного запроса расчета
bool askForRepeat() {
    std::string choice;
    while (true) {
        std::cout << "Хотите выполнить ещё один расчёт? (y/n): ";
        std::cin >> choice;
        std::cin.clear();
        std::cin.ignore(10000, '\n');

        if (choice == "y" || choice == "Y" || choice == "да" || choice == "ДА" || choice == "yes" || choice == "YES") {
            std::cout << "\n----------------------------------------\n\n";
            return true;
        }
        else if (choice == "n" || choice == "N" || choice == "нет" || choice == "НЕТ" || choice == "no" || choice == "NO") {
            std::cout << "Завершение программы. До свидания!" << '\n';
            return false;
        }
        else {
            std::cout << "Некорректный ввод. Пожалуйста, введите 'y' или 'n'.\n";
        }
    }
}

// Функция для ввода размера массива
ll inputSize() {
    ll size;
    std::cout << "Введите размер массива (положительное целое число):\n";
    while (true) {
        if (isLongLong(size) && size > 0) {
            return size;
        }
        else {
            std::cout << "Ошибка: введено некорректное число. Попробуйте снова.\n";
        }
    }
}

// Функция для ввода элементов массива
void inputArray(ll* array, ll size) {
    std::cout << "Введите элементы массива:\n";
    for (ll i = 0; i < size; ++i) {
        while (true) {
            std::cout << "Введите элемент на позиции " << i << ": "; // Показываем позицию
            if (isLongLong(array[i])) {
                break; // Выход из цикла при успешном вводе
            }
            else {
                std::cout << "Ошибка: введите целое число.\n"; // Сообщаем об ошибке
            }
        }
    }
}

// Функция для освобождения памяти
void freeArray(ll* array) {
    delete[] array;
}

int main() {
    setlocale(LC_ALL, "Russian_Russia.1251");

    do {
        // Отображение контекстного меню
        displayContextMenu();

        // Ввод размера массива
        ll size = inputSize();

        // Выделение памяти для динамического массива
        ll* array = new ll[size];

        // Ввод элементов массива
        inputArray(array, size);

        // Загрузка библиотеки
        HMODULE hModule = LoadLibrary(L"DynamicLibrary.dll");
        if (!hModule) {
            std::cerr << "Ошибка загрузки библиотеки: " << GetLastError() << '\n';
            freeArray(array);
            continue; // Переход к следующему циклу
        }

        // Получение адреса функции
        typedef void (*CheckFunction)(ll*, ll);
        CheckFunction checkAndDisplayCondition = (CheckFunction)GetProcAddress(hModule, "checkAndDisplayCondition");
        if (!checkAndDisplayCondition) {
            std::cerr << "Ошибка получения адреса функции: " << GetLastError() << '\n';
            FreeLibrary(hModule);
            freeArray(array);
            continue; // Переход к следующему циклу
        }

        // Проверка условия и вывод результата
        checkAndDisplayCondition(array, size);

        // Освобождение ресурсов
        FreeLibrary(hModule);
        freeArray(array);

    } while (askForRepeat());

    return 0;
}
