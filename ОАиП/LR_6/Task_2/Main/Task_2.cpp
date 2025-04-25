#include <iostream>
#include "prot.h"

// Функция для отображения контекстного меню
void displayContextMenu() {
    std::cout << "Лабораторная работа №6, задание №2\n";
    std::cout << "Суть задания:\n";
    std::cout << "В тексте нет слов, начинающихся одинаковыми буквами. ";
    std::cout << "Напечатать слова текста в таком порядке, чтобы последняя буква каждого слова совпадала с первой буквой последующего слова. ";
    std::cout << "Если все слова нельзя напечатать в таком порядке, найти такую цепочку, состоящую из наибольшего количества слов.\n";
    std::cout << "Выполнил студент группы 453503 Халамов Николай\n";
}

// Функция для проверки, что строка содержит только английские буквы и пробелы
bool isValidInput(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!((str[i] >= 'A' && str[i] <= 'Z') ||
              (str[i] >= 'a' && str[i] <= 'z') ||
              str[i] == ' ')) {
            return false; // Если есть недопустимый символ
        }
    }
    return true; // Все символы допустимы
}

// Функция для проверки уникальности первых букв слов
bool hasUniqueFirstLetters(const char* str) {
    bool firstLetters[26] = {false}; // Массив для хранения первых букв

    bool inWord = false;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            inWord = false; // Вышли из слова
        } else {
            if (!inWord) {
                char firstChar = (str[i] >= 'A' && str[i] <= 'Z') ? str[i] + 32 : str[i]; // Приводим к нижнему регистру
                int index = firstChar - 'a'; // Индекс для массива
                if (index < 0 || index >= 26) {
                    return false; // Некорректная буква
                }
                if (firstLetters[index]) {
                    return false; // Найдена повторяющаяся первая буква
                }
                firstLetters[index] = true; // Сохраняем первую букву
                inWord = true; // Начали новое слово
            }
        }
    }
    return true; // Все первые буквы уникальны
}

// Функция для разбора строки на слова
int parseWords(const char* str, char** words, char* firstLetters, char* lastLetters, int maxWords, int maxWordLength) {
    int wordCount = 0;
    int i = 0;
    while (str[i] != '\0' && wordCount < maxWords) {
        // Пропускаем начальные пробелы
        while (str[i] == ' ') i++;
        if (str[i] == '\0') break;

        // Начало слова
        int start = i;
        // Найти конец слова
        while (str[i] != ' ' && str[i] != '\0') i++;
        int end = i;

        // Копируем слово
        int length = end - start;
        if (length > maxWordLength) length = maxWordLength;
        for (int j = 0; j < length; j++) {
            words[wordCount][j] = str[start + j];
        }
        words[wordCount][length] = '\0'; // Завершающий нулевой символ

        // Устанавливаем первую и последнюю буквы
        char first = words[wordCount][0];
        char last = words[wordCount][length - 1];
        firstLetters[wordCount] = (first >= 'A' && first <= 'Z') ? first + 32 : first;
        lastLetters[wordCount] = (last >= 'A' && last <= 'Z') ? last + 32 : last;

        wordCount++;
    }
    return wordCount;
}

// Рекурсивная функция для поиска самой длинной цепочки слов
void dfs(int currentIndex, int currentLength, char** words,
         const char* firstLetters, const char* lastLetters, int wordCount,
         int* currentChain, bool* used, int* bestChain, int& bestLength) {
    currentChain[currentLength] = currentIndex;
    currentLength++;
    if (currentLength > bestLength) {
        bestLength = currentLength;
        for (int i = 0; i < currentLength; i++) {
            bestChain[i] = currentChain[i];
        }
    }

    // Ищем следующие слова, которые можно добавить к цепочке
    for (int i = 0; i < wordCount; i++) {
        if (!used[i] && lastLetters[currentIndex] == firstLetters[i]) {
            used[i] = true;
            dfs(i, currentLength, words, firstLetters, lastLetters, wordCount, currentChain, used, bestChain, bestLength);
            used[i] = false;
        }
    }
}

// Функция для поиска самой длинной цепочки слов
void findLongestChain(char** words, const char* firstLetters,
                      const char* lastLetters, int wordCount, int* bestChain, int& bestLength) {
    bestLength = 0;

    int* currentChain = new int[MAX_WORDS]; // Динамический массив для текущей цепочки
    bool* used = new bool[MAX_WORDS](); // Динамический массив для отслеживания использованных слов

    // Перебираем все слова как возможные начальные
    for (int i = 0; i < wordCount; i++) {
        used[i] = true;
        dfs(i, 0, words, firstLetters, lastLetters, wordCount, currentChain, used, bestChain, bestLength);
        used[i] = false;
    }

    delete[] currentChain; // Освобождаем память
    delete[] used; // Освобождаем память
}

// Функция для получения пользовательского ввода
void getUserInput(char* input) {
    while (true) {
        std::cout << "Введите строку длиной не более 80 символов (состоящую только из букв английского алфавита любого регистра): " << '\n';
        int index = 0;

        // Считываем строку
        while (index < MAX_LENGTH) {
            char c = getchar();
            if (c == '\n' || c == EOF) {
                break; // Конец ввода
            }
            input[index++] = c;
        }

        // Проверка на превышение длины
        if (index == MAX_LENGTH) {
            char c = getchar();
            if (c != '\n' && c != EOF) {
                std::cout << "Длина строки превышает 80 символов, пожалуйста, введите корректную строку." << '\n';
                // Очищаем буфер
                while (c != '\n' && c != EOF) {
                    c = getchar();
                }
                continue; // Запрашиваем ввод заново
            }
        }

        input[index] = '\0'; // Завершаем строку нулевым символом

        // Проверка на пустую строку
        if (index == 0) {
            std::cout << "Вы ввели пустую строку. Попробуйте снова." << '\n';
            continue;
        }

        // Проверка на допустимые символы
        if (!isValidInput(input)) {
            std::cout << "Ошибка: строка должна содержать только английские буквы и пробелы. Попробуйте снова." << std::endl;
            continue; // Запрашиваем ввод заново
        }

        // Проверка на уникальность первых букв слов
        if (!hasUniqueFirstLetters(input)) {
            std::cout << "Ошибка: все слова должны начинаться с разных букв. Попробуйте снова." << std::endl;
            continue; // Запрашиваем ввод заново
        }

        // Если все проверки пройдены, выводим успешное сообщение
        std::cout << "Ввод корректен: " << input << std::endl;
        break; // Выходим из цикла
    }
}

// Функция для обработки результатов
void processResults(char** words, const char* firstLetters,
                    const char* lastLetters, int wordCount) {
    if (wordCount == 0) {
        std::cout << "Нет слов для обработки.\n";
    } else {
        // Находим самую длинную цепочку
        int* bestChain = new int[MAX_WORDS]; // Динамический массив для лучшей цепочки
        int bestLength = 0;
        findLongestChain(words, firstLetters, lastLetters, wordCount, bestChain, bestLength);

        // Выводим результат
        std::cout << "Самая длинная цепочка из " << bestLength << " слов(а):\n";
        for (int i = 0; i < bestLength; i++) {
            std::cout << words[bestChain[i]];
            if (i != bestLength - 1) {
                std::cout << " -> ";
            }
        }
        std::cout << "\n";

        delete[] bestChain; // Освобождаем память
    }
}

// Функция для проверки, хочет ли пользователь продолжить
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

int main() {
    displayContextMenu();

    while (true) {
        char input[MAX_LENGTH + 1]; // +1 для нулевого символа
        getUserInput(input); // Получаем пользовательский ввод

        // Динамическое выделение памяти для слов
        char** words = new char*[MAX_WORDS];
        for (int i = 0; i < MAX_WORDS; i++) {
            words[i] = new char[MAX_WORD_LENGTH + 1]; // +1 для нулевого символа
        }

        // Динамические массивы для первых и последних букв
        char* firstLetters = new char[MAX_WORDS];
        char* lastLetters = new char[MAX_WORDS];

        // Разбираем слова
        int wordCount = parseWords(input, words, firstLetters, lastLetters, MAX_WORDS, MAX_WORD_LENGTH);

        // Обрабатываем результаты
        processResults(words, firstLetters, lastLetters, wordCount);

        // Освобождаем память для слов и букв
        for (int i = 0; i < MAX_WORDS; i++) {
            delete[] words[i];
        }
        delete[] words;
        delete[] firstLetters;
        delete[] lastLetters;

        // Проверка на выполнение ещё одного расчёта
        if (!askToContinue()) {
            break; // Завершаем программу
        }
    }

    return 0;
}