#include <iostream>
#include "prot.h"

const int MAX_LENGTH = 80;

// Функция для отображения контекстного меню
void displayContextMenu() {
    std::cout << "Лабораторная работа №6, задание №1\n";
    std::cout << "Суть задания:\n";
    std::cout << "Дана строка, состоящая из слов, разделенных пробелами."
              << " Вывести на экран порядковый номер слова максимальной длины "
              << "и номер позиции строки, с которой оно начинается.\n";
    std::cout << "Выполнил студент группы 453503 Халамов Николай\n";
}

// Функция для ввода строки
bool inputString(char* input) {
    int index = 0;

    while (true) {
        std::cout << "Введите строку длиной не более 80 символов (на английском языке):" << '\n';
        index = 0;
        bool validInput = true;

        // Считываем строку
        while (index < MAX_LENGTH) {
            char c = getchar();
            if (c == '\n') {
                break; // Конец ввода
            }
            input[index++] = c;
        }

        // Проверка на превышение длины
        if (index == MAX_LENGTH && getchar() != '\n') {
            validInput = false;
        }

        input[index] = '\0'; // Завершаем строку нулевым символом

        if (!validInput) {
            std::cout << "Длина строки превышает 80 символов, пожалуйста, введите корректную строку." << '\n';
            while (std::cin.get() != '\n') {} // Очищаем буфер
            continue; // Запрашиваем ввод заново
        }

        if (index == 0) { // Проверка на пустую строку
            std::cout << "Вы ввели пустую строку. Попробуйте снова." << '\n';
            continue;
        }
        
        return true; // Ввод корректен
    }
}

// Функция для поиска слова максимальной длины
void findMaxLengthWord(const char* input) {
    int currentWordLength = 0;
    int maxLength = 0;
    int maxStartPosition = -1;
    int maxPosition = -1;
    int positionNow = 1; // Позиция слова (начинается с 1)

    // Проходим по строке
    for (int i = 0; ; i++) {
        if (input[i] == ' ' || input[i] == '\0') {
            if (currentWordLength > maxLength) {
                maxLength = currentWordLength;
                maxPosition = positionNow;
                maxStartPosition = i - maxLength;
            }
            currentWordLength = 0;
            positionNow++;
        } else {
            currentWordLength++;
        }

        if (input[i] == '\0') {
            break; // Конец строки
        }
    }

    // Вывод результатов
    std::cout << "Введенная строка: " << input << '\n';
    
    if (maxLength > 0) {
        std::cout << "Слово максимальной длины: ";
        for (int l = maxStartPosition; l < maxStartPosition + maxLength; l++) {
            std::cout << input[l];
        }
        std::cout << '\n'
                  << "Максимальная длина слова: " << maxLength << '\n'
                  << "Позиция слова максимальной длины (нумерация стартует с единицы): " << maxPosition << '\n'
                  << "Позиция начала слова максимальной длины (нумерация стартует с единицы): " << maxStartPosition + 1 << '\n';
    } else {
        std::cout << "Слова не найдены." << '\n';
    }
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
            std::cout << "Некорректный ввод. Пожалуйста, введите 'y' или 'n'." << '\n';
        }
    }
}

int main() {
    displayContextMenu();

    do {
        char* input = new char[MAX_LENGTH + 1]; // Динамический массив
        if (inputString(input)) {
            findMaxLengthWord(input);
        }
        delete[] input; // Освобождаем память
    } while (askToContinue());

    return 0;
}