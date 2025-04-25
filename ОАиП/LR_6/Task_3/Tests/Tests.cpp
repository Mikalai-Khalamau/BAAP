#include <gtest/gtest.h>
#include <iostream>
#include "../Main/prot.h"

// Тесты для findUniqueSymbols
TEST(FindUniqueSymbolsTests, EmptyString) {
    char* symbols = new char[MAX_SYMBOLS]; // Выделяем память для уникальных символов
    int symbolCount = 0;

    findUniqueSymbols("", symbols, symbolCount);

    EXPECT_EQ(symbolCount, 0);

    // Освобождение памяти
    delete[] symbols;
}

TEST(FindUniqueSymbolsTests, SingleCharacter) {
    char* symbols = new char[MAX_SYMBOLS];
    int symbolCount = 0;

    findUniqueSymbols("a", symbols, symbolCount);

    EXPECT_EQ(symbolCount, 1);
    EXPECT_EQ(symbols[0], 'a');

    delete[] symbols;
}

TEST(FindUniqueSymbolsTests, MultipleSameCharacters) {
    char* symbols = new char[MAX_SYMBOLS];
    int symbolCount = 0;

    findUniqueSymbols("aaaaa", symbols, symbolCount);

    EXPECT_EQ(symbolCount, 1);
    EXPECT_EQ(symbols[0], 'a');

    delete[] symbols;
}

TEST(FindUniqueSymbolsTests, DifferentCharacters) {
    char* symbols = new char[MAX_SYMBOLS];
    int symbolCount = 0;

    findUniqueSymbols("abcde", symbols, symbolCount);

    EXPECT_EQ(symbolCount, 5);
    EXPECT_EQ(symbols[0], 'a');
    EXPECT_EQ(symbols[1], 'b');
    EXPECT_EQ(symbols[2], 'c');
    EXPECT_EQ(symbols[3], 'd');
    EXPECT_EQ(symbols[4], 'e');

    delete[] symbols;
}

TEST(FindUniqueSymbolsTests, MixedCharacters) {
    char* symbols = new char[MAX_SYMBOLS];
    int symbolCount = 0;

    findUniqueSymbols("aabbccddeeff", symbols, symbolCount);

    EXPECT_EQ(symbolCount, 6);
    EXPECT_EQ(symbols[0], 'a');
    EXPECT_EQ(symbols[1], 'b');
    EXPECT_EQ(symbols[2], 'c');
    EXPECT_EQ(symbols[3], 'd');
    EXPECT_EQ(symbols[4], 'e');
    EXPECT_EQ(symbols[5], 'f');

    delete[] symbols;
}

TEST(FindUniqueSymbolsTests, SpecialCharacters) {
    char* symbols = new char[MAX_SYMBOLS];
    int symbolCount = 0;

    findUniqueSymbols("!@#$%^&*()", symbols, symbolCount);

    EXPECT_EQ(symbolCount, 10);
    EXPECT_EQ(symbols[0], '!');
    EXPECT_EQ(symbols[1], '@');
    EXPECT_EQ(symbols[2], '#');
    EXPECT_EQ(symbols[3], '$');
    EXPECT_EQ(symbols[4], '%');
    EXPECT_EQ(symbols[5], '^');
    EXPECT_EQ(symbols[6], '&');
    EXPECT_EQ(symbols[7], '*');
    EXPECT_EQ(symbols[8], '(');
    EXPECT_EQ(symbols[9], ')');

    delete[] symbols;
}

TEST(FindUniqueSymbolsTests, AlphanumericCharacters) {
    char* symbols = new char[MAX_SYMBOLS];
    int symbolCount = 0;

    findUniqueSymbols("abc123abc", symbols, symbolCount);

    EXPECT_EQ(symbolCount, 6);
    EXPECT_EQ(symbols[0], 'a');
    EXPECT_EQ(symbols[1], 'b');
    EXPECT_EQ(symbols[2], 'c');
    EXPECT_EQ(symbols[3], '1');
    EXPECT_EQ(symbols[4], '2');
    EXPECT_EQ(symbols[5], '3');

    delete[] symbols;
}

TEST(FindUniqueSymbolsTests, CaseSensitivity) {
    char* symbols = new char[MAX_SYMBOLS];
    int symbolCount = 0;

    findUniqueSymbols("AaBbCc", symbols, symbolCount);

    EXPECT_EQ(symbolCount, 6);
    EXPECT_EQ(symbols[0], 'A');
    EXPECT_EQ(symbols[1], 'a');
    EXPECT_EQ(symbols[2], 'B');
    EXPECT_EQ(symbols[3], 'b');
    EXPECT_EQ(symbols[4], 'C');
    EXPECT_EQ(symbols[5], 'c');

    delete[] symbols;
}

TEST(FindUniqueSymbolsTests, LargeInput) {
    char* symbols = new char[MAX_SYMBOLS];
    int symbolCount = 0;

    const char* input = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    findUniqueSymbols(input, symbols, symbolCount);

    EXPECT_EQ(symbolCount, 62); 

    delete[] symbols;
}

// Основная функция для запуска тестов
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}