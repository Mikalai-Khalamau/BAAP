#ifndef FUNCTIONS_H
#define FUNCTIONS_H

const int MAX_LENGTH = 80;
const int MAX_WORDS = 26; // Максимальное количество слов
const int MAX_WORD_LENGTH = 80; // Максимальная длина одного слова

// Объявления функций с использованием динамических массивов
void dfs(int currentIndex, int currentLength, const char** words,
         const char* firstLetters, const char* lastLetters, int wordCount,
         int* currentChain, bool* used, int* bestChain, int& bestLength);

void findLongestChain(const char** words, const char* firstLetters,
                      const char* lastLetters, int wordCount, int* bestChain, int& bestLength);

void processResults(const char** words, const char* firstLetters,
                    const char* lastLetters, int wordCount);

#endif // FUNCTIONS_H