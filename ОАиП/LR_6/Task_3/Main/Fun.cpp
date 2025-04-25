// functions.cpp
#include "prot.h"

void displayContextMenu() {
    std::cout << "Лабораторная работа №6, задание №3\n";
    std::cout << "Суть задания:\n";
    std::cout << "Ввести строку и определить все входящие в неё символы. ";
    std::cout << "Выполнил студент группы 453503 Халамов Николай\n";
}

void inputString(char* input) {
    int index;

    while (true) {
        std::cout << "Введите строку длиной не более 80 символов (на английском языке): " << '\n';
        index = 0;

        while (index < MAX_LENGTH) {
            char c = getchar();
            if (c == '\n') {
                break; // Конец ввода
            }
            input[index++] = c;
        }

        if (index == MAX_LENGTH && getchar() != '\n') {
            std::cout << "Длина строки превышает 80 символов, пожалуйста, введите корректную строку." << '\n';
            while (std::cin.get() != '\n') {}
            continue; // Запрашиваем ввод заново
        }

        input[index] = '\0'; // Завершаем строку нулевым символом

        if (index == 0) { // Проверка на пустую строку
            std::cout << "Вы ввели пустую строку. Попробуйте снова." << '\n';
            continue;
        }
        
        break; // Ввод корректен, выходим из цикла
    }
}

void findUniqueSymbols(const char* input, char* symbols, int& symbolCount) {
    symbolCount = 0; // Счетчик уникальных символов

    for (int i = 0; input[i] != '\0'; i++) {
        char check = input[i];
        bool found = false;

        for (int j = 0; j < symbolCount; j++) {
            if (symbols[j] == check) {
                found = true;
                break;
            }
        }

        if (!found) {
            symbols[symbolCount++] = check;
        }
    }
}

void displayResults(const char* input, const char* symbols, int symbolCount) {
    std::cout << "Введенная строка: " << input << '\n';
    std::cout << "Все символы, входящие в строку: ";
    
    for (int i = 0; i < symbolCount; i++) {
        std::cout << symbols[i] << ' ';
    }
    std::cout << '\n';
}

bool askToContinue() {
    std::string choice;

    while (true) {
        std::cout << "Хотите выполнить ещё один расчёт? (y/n): ";
        std::cin >> choice;
        std::cin.clear();
        std::cin.ignore(10000, '\n');

        if (choice == "y" || choice == "Y" || choice == "да" || choice == "ДА" || 
            choice == "yes" || choice == "YES") {
            std::cout << "\n----------------------------------------\n\n";
            return true; // Возвращаем true, чтобы продолжить
        } else if (choice == "n" || choice == "N" || choice == "нет" || choice == "НЕТ" || 
                   choice == "no" || choice == "NO") {
            std::cout << "Завершение программы. До свидания!" << '\n';
            return false; // Возвращаем false, чтобы завершить
        } else {
            std::cout << "Некорректный ввод. Пожалуйста, введите 'y' или 'n'." << '\n';
        }
    }
}