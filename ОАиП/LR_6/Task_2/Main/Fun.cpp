#include "prot.h"
#include <iostream>

// Рекурсивная функция для поиска самой длинной цепочки слов
void dfs(int currentIndex, int currentLength, const char** words,
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
void findLongestChain(const char** words, const char* firstLetters,
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

// Функция для обработки результатов
void processResults(const char** words, const char* firstLetters,
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