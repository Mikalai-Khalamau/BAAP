// main.cpp
#include "prot.h"

int main() {
    displayContextMenu();

    while (true) {
        char* input = new char[MAX_LENGTH + 1]; // +1 для нулевого символа
        char* symbols = new char[MAX_SYMBOLS]; // Массив для уникальных символов
        int symbolCount = 0; // Счетчик уникальных символов

        inputString(input); // Ввод строки
        findUniqueSymbols(input, symbols, symbolCount); // Поиск уникальных символов
        displayResults(input, symbols, symbolCount); // Отображение результатов

        // Освобождаем память
        delete[] input;
        delete[] symbols;

        // Проверка на выполнение ещё одного расчёта
        if (!askToContinue()) {
            break;
        }
    }

    return 0;
}