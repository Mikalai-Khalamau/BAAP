#include <gtest/gtest.h>
#include <iostream>
#include "../Main/prot.h"

// Тесты для processResults
TEST(ProcessResultsTests, NoWords) {
    const int wordCount = 0;
    const char* words[MAX_WORDS] = {nullptr}; // Использование массива указателей на char
    char firstLetters[MAX_WORDS] = {};
    char lastLetters[MAX_WORDS] = {};

    std::ostringstream output;
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());
    
    processResults(words, firstLetters, lastLetters, wordCount);
    
    std::cout.rdbuf(oldCout);
    EXPECT_EQ(output.str(), "Нет слов для обработки.\n");
}

TEST(ProcessResultsTests, OneWord) {
    const int wordCount = 1;
    const char* words[MAX_WORDS] = {"apple"}; // Массив указателей на char
    char firstLetters[MAX_WORDS] = {'a'};
    char lastLetters[MAX_WORDS] = {'e'};

    std::ostringstream output;
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());
    
    processResults(words, firstLetters, lastLetters, wordCount);
    
    std::cout.rdbuf(oldCout);
    EXPECT_EQ(output.str(), "Самая длинная цепочка из 1 слов(а):\napple\n");
}

TEST(ProcessResultsTests, TwoWordsChain) {
    const int wordCount = 2;
    const char* words[MAX_WORDS] = {"apple", "egg"};
    char firstLetters[MAX_WORDS] = {'a', 'e'};
    char lastLetters[MAX_WORDS] = {'e', 'g'};

    std::ostringstream output;
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());
    
    processResults(words, firstLetters, lastLetters, wordCount);
    
    std::cout.rdbuf(oldCout);
    EXPECT_EQ(output.str(), "Самая длинная цепочка из 2 слов(а):\napple -> egg\n");
}

TEST(ProcessResultsTests, ThreeWordsChain) {
    const int wordCount = 3;
    const char* words[MAX_WORDS] = {"apple", "egg", "grape"};
    char firstLetters[MAX_WORDS] = {'a', 'e', 'g'};
    char lastLetters[MAX_WORDS] = {'e', 'g', 'e'};

    std::ostringstream output;
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());
    
    processResults(words, firstLetters, lastLetters, wordCount);
    
    std::cout.rdbuf(oldCout);
    EXPECT_EQ(output.str(), "Самая длинная цепочка из 3 слов(а):\napple -> egg -> grape\n");
}

TEST(ProcessResultsTests, LongestChainExample) {
    const int wordCount = 5;
    const char* words[MAX_WORDS] = {"apple", "egg", "grape", "elephant", "tiger"};
    char firstLetters[MAX_WORDS] = {'a', 'e', 'g', 'e', 't'};
    char lastLetters[MAX_WORDS] = {'e', 'g', 'e', 't', 'r'};

    std::ostringstream output;
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());
    
    processResults(words, firstLetters, lastLetters, wordCount);
    
    std::cout.rdbuf(oldCout);
    EXPECT_EQ(output.str(), "Самая длинная цепочка из 5 слов(а):\napple -> egg -> grape -> elephant -> tiger\n");
}

TEST(ProcessResultsTests, CircularChain) {
    const int wordCount = 4;
    const char* words[MAX_WORDS] = {"ant", "tiger", "rat", "turtle"};
    char firstLetters[MAX_WORDS] = {'a', 't', 'r', 't'};
    char lastLetters[MAX_WORDS] = {'t', 'r', 't', 'e'};

    std::ostringstream output;
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());
    
    processResults(words, firstLetters, lastLetters, wordCount);
    
    std::cout.rdbuf(oldCout);
    EXPECT_EQ(output.str(), "Самая длинная цепочка из 4 слов(а):\nant -> tiger -> rat -> turtle\n");
}

TEST(ProcessResultsTests, MultipleChains) {
    const int wordCount = 4;
    const char* words[MAX_WORDS] = {"bat", "cat", "tab", "dog"};
    char firstLetters[MAX_WORDS] = {'b', 'c', 't', 'd'};
    char lastLetters[MAX_WORDS] = {'t', 't', 'b', 'g'};

    std::ostringstream output;
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());
    
    processResults(words, firstLetters, lastLetters, wordCount);
    
    std::cout.rdbuf(oldCout);
    EXPECT_EQ(output.str(), "Самая длинная цепочка из 3 слов(а):\ncat -> tab -> bat\n");
}

TEST(ProcessResultsTests, AllWordsSameLetter) {
    const int wordCount = 3;
    const char* words[MAX_WORDS] = {"aaa", "aab", "abc"};
    char firstLetters[MAX_WORDS] = {'a', 'a', 'a'};
    char lastLetters[MAX_WORDS] = {'a', 'b', 'c'};

    std::ostringstream output;
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());
    
    processResults(words, firstLetters, lastLetters, wordCount);
    
    std::cout.rdbuf(oldCout);
    EXPECT_EQ(output.str(), "Самая длинная цепочка из 2 слов(а):\naaa -> aab\n");
}

TEST(ProcessResultsTests, LongWords) {
    const int wordCount = 3;
    const char* words[MAX_WORDS] = {"abcdefgh", "hijklmnop", "qrstuvwx"};
    char firstLetters[MAX_WORDS] = {'a', 'h', 'q'};
    char lastLetters[MAX_WORDS] = {'h', 'p', 'x'};

    std::ostringstream output;
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());
    
    processResults(words, firstLetters, lastLetters, wordCount);
    
    std::cout.rdbuf(oldCout);
    EXPECT_EQ(output.str(), "Самая длинная цепочка из 2 слов(а):\nabcdefgh -> hijklmnop\n");
}

// Основная функция для запуска тестов
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}