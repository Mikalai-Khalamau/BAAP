#include <gtest/gtest.h>
#include <iostream>
#include "../Main/prot.h"

// Прототип вашей функции
void findMaxLengthWord(const char *input[]);

TEST(FindMaxLengthWordTest, TestQwerty) {
    const char input[] = "qwerty";
    std::string expectedOutput = 
        "Введенная строка: qwerty\n"
        "Слово максимальной длины: qwerty\n"
        "Максимальная длина слова: 6\n"
        "Позиция слова максимальной длины (нумерация стартует с единицы): 1\n"
        "Позиция начала слова максимальной длины (нумерация стартует с единицы): 1\n";

    std::streambuf* originalCout = std::cout.rdbuf();
    std::ostringstream capture;
    std::cout.rdbuf(capture.rdbuf());
    findMaxLengthWord(input);
    std::cout.rdbuf(originalCout);
    EXPECT_EQ(capture.str(), expectedOutput);
}

TEST(FindMaxLengthWordTest, TestSingleWord) {
    const char input[] = "hello";
    std::string expectedOutput = 
        "Введенная строка: hello\n"
        "Слово максимальной длины: hello\n"
        "Максимальная длина слова: 5\n"
        "Позиция слова максимальной длины (нумерация стартует с единицы): 1\n"
        "Позиция начала слова максимальной длины (нумерация стартует с единицы): 1\n";

    std::streambuf* originalCout = std::cout.rdbuf();
    std::ostringstream capture;
    std::cout.rdbuf(capture.rdbuf());
    findMaxLengthWord(input);
    std::cout.rdbuf(originalCout);
    EXPECT_EQ(capture.str(), expectedOutput);
}

TEST(FindMaxLengthWordTest, TestEmptyString) {
    const char input[] = "";
    std::string expectedOutput = 
        "Введенная строка: \n"
        "Слова не найдены.\n";

    std::streambuf* originalCout = std::cout.rdbuf();
    std::ostringstream capture;
    std::cout.rdbuf(capture.rdbuf());
    findMaxLengthWord(input);
    std::cout.rdbuf(originalCout);
    EXPECT_EQ(capture.str(), expectedOutput);
}

TEST(FindMaxLengthWordTest, TestMultipleWords) {
    const char input[] = "the quick brown fox";
    std::string expectedOutput = 
        "Введенная строка: the quick brown fox\n"
        "Слово максимальной длины: quick\n"
        "Максимальная длина слова: 5\n"
        "Позиция слова максимальной длины (нумерация стартует с единицы): 2\n"
        "Позиция начала слова максимальной длины (нумерация стартует с единицы): 5\n";

    std::streambuf* originalCout = std::cout.rdbuf();
    std::ostringstream capture;
    std::cout.rdbuf(capture.rdbuf());
    findMaxLengthWord(input);
    std::cout.rdbuf(originalCout);
    EXPECT_EQ(capture.str(), expectedOutput);
}

TEST(FindMaxLengthWordTest, TestLeadingSpaces) {
    const char input[] = "   space before";
    std::string expectedOutput = 
        "Введенная строка:    space before\n"
        "Слово максимальной длины: before\n"
        "Максимальная длина слова: 6\n"
        "Позиция слова максимальной длины (нумерация стартует с единицы): 5\n"
        "Позиция начала слова максимальной длины (нумерация стартует с единицы): 10\n";

    std::streambuf* originalCout = std::cout.rdbuf();
    std::ostringstream capture;
    std::cout.rdbuf(capture.rdbuf());
    findMaxLengthWord(input);
    std::cout.rdbuf(originalCout);
    EXPECT_EQ(capture.str(), expectedOutput);
}

TEST(FindMaxLengthWordTest, TestTrailingSpaces) {
    const char input[] = "space after   ";
    std::string expectedOutput = 
        "Введенная строка: space after   \n"
        "Слово максимальной длины: space\n"
        "Максимальная длина слова: 5\n"
        "Позиция слова максимальной длины (нумерация стартует с единицы): 1\n"
        "Позиция начала слова максимальной длины (нумерация стартует с единицы): 1\n";

    std::streambuf* originalCout = std::cout.rdbuf();
    std::ostringstream capture;
    std::cout.rdbuf(capture.rdbuf());
    findMaxLengthWord(input);
    std::cout.rdbuf(originalCout);
    EXPECT_EQ(capture.str(), expectedOutput);
}

TEST(FindMaxLengthWordTest, TestMultipleSpaces) {
    const char input[] = "this  is   a test";
    std::string expectedOutput = 
        "Введенная строка: this  is   a test\n"
        "Слово максимальной длины: this\n"
        "Максимальная длина слова: 4\n"
        "Позиция слова максимальной длины (нумерация стартует с единицы): 1\n"
        "Позиция начала слова максимальной длины (нумерация стартует с единицы): 1\n";

    std::streambuf* originalCout = std::cout.rdbuf();
    std::ostringstream capture;
    std::cout.rdbuf(capture.rdbuf());
    findMaxLengthWord(input);
    std::cout.rdbuf(originalCout);
    EXPECT_EQ(capture.str(), expectedOutput);
}

TEST(FindMaxLengthWordTest, TestSingleCharacter) {
    const char input[] = "A";
    std::string expectedOutput = 
        "Введенная строка: A\n"
        "Слово максимальной длины: A\n"
        "Максимальная длина слова: 1\n"
        "Позиция слова максимальной длины (нумерация стартует с единицы): 1\n"
        "Позиция начала слова максимальной длины (нумерация стартует с единицы): 1\n";

    std::streambuf* originalCout = std::cout.rdbuf();
    std::ostringstream capture;
    std::cout.rdbuf(capture.rdbuf());
    findMaxLengthWord(input);
    std::cout.rdbuf(originalCout);
    EXPECT_EQ(capture.str(), expectedOutput);
}

TEST(FindMaxLengthWordTest, TestAllSpaces) {
    const char input[] = "     ";
    std::string expectedOutput = 
        "Введенная строка:      \n"
        "Слова не найдены.\n";

    std::streambuf* originalCout = std::cout.rdbuf();
    std::ostringstream capture;
    std::cout.rdbuf(capture.rdbuf());
    findMaxLengthWord(input);
    std::cout.rdbuf(originalCout);
    EXPECT_EQ(capture.str(), expectedOutput);
}

TEST(FindMaxLengthWordTest, TestLongWord) {
    const char input[] = "a verylongword indeed";
    std::string expectedOutput = 
        "Введенная строка: a verylongword indeed\n"
        "Слово максимальной длины: verylongword\n"
        "Максимальная длина слова: 12\n"
        "Позиция слова максимальной длины (нумерация стартует с единицы): 2\n"
        "Позиция начала слова максимальной длины (нумерация стартует с единицы): 3\n";

    std::streambuf* originalCout = std::cout.rdbuf();
    std::ostringstream capture;
    std::cout.rdbuf(capture.rdbuf());
    findMaxLengthWord(input);
    std::cout.rdbuf(originalCout);
    EXPECT_EQ(capture.str(), expectedOutput);
}

// Основная функция для запуска тестов
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}