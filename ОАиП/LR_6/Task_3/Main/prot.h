// functions.h
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>


const int MAX_LENGTH = 80; // Максимальная длина ввода
const int MAX_SYMBOLS = 256; // Максимальное количество уникальных символов

void displayContextMenu();
void inputString(char* input);
void findUniqueSymbols(const char* input, char* symbols, int& symbolCount);
void displayResults(const char* input, const char* symbols, int symbolCount);
bool askToContinue();

#endif // FUNCTIONS_H