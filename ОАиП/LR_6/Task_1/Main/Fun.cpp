#include <iostream>
#include "prot.h"

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