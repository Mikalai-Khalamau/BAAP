// test_magic_square.cpp
#include <gtest/gtest.h>
#include "../Main/prot.h"

// Вспомогательная функция для создания квадрата
unsigned long long** createSquare(long long n, unsigned long long data[]) {
    unsigned long long** square = (unsigned long long**)malloc(n * sizeof(unsigned long long*));
    for (long long i = 0; i < n; ++i) {
        square[i] = (unsigned long long*)malloc(n * sizeof(unsigned long long));
        for (long long j = 0; j < n; ++j) {
            square[i][j] = data[i * n + j];
        }
    }
    return square;
}

// Вспомогательная функция для освобождения памяти квадрата
void freeSquare(unsigned long long** square, long long n) {
    for (long long i = 0; i < n; ++i) {
        free(square[i]);
    }
    free(square);
}

// Тест 1: Магический квадрат 3x3
TEST(MagicSquareTest, ThreeByThreeMagicSquare) {
    long long n = 3;
    unsigned long long data[] = {
        8, 1, 6,
        3, 5, 7,
        4, 9, 2
    };
    unsigned long long** square = createSquare(n, data);
    EXPECT_TRUE(isMagicSquare(square, n));
    freeSquare(square, n);
}

// Тест 2: Не магический квадрат 3x3
TEST(MagicSquareTest, ThreeByThreeNonMagicSquare) {
    long long n = 3;
    unsigned long long data[] = {
        8, 1, 6,
        3, 5, 7,
        4, 9, 3  // Изменено последнее число с 2 на 3
    };
    unsigned long long** square = createSquare(n, data);
    EXPECT_FALSE(isMagicSquare(square, n));
    freeSquare(square, n);
}

// Тест 3: Магический квадрат 4x4
TEST(MagicSquareTest, FourByFourMagicSquare) {
    long long n = 4;
    unsigned long long data[] = {
        16, 2, 3, 13,
        5, 11, 10, 8,
        9, 7, 6, 12,
        4, 14, 15, 1
    };
    unsigned long long** square = createSquare(n, data);
    EXPECT_TRUE(isMagicSquare(square, n));
    freeSquare(square, n);
}

// Тест 4: Магический квадрат 5x5
TEST(MagicSquareTest, FiveByFiveMagicSquare) {
    long long n = 5;
    unsigned long long data[] = {
        17, 24, 1, 8, 15,
        23, 5, 7, 14, 16,
        4, 6, 13, 20, 22,
        10, 12, 19, 21, 3,
        11, 18, 25, 2, 9
    };
    unsigned long long** square = createSquare(n, data);
    EXPECT_TRUE(isMagicSquare(square, n));
    freeSquare(square, n);
}

// Тест 5: Квадрат порядка 1 (магический по определению)
TEST(MagicSquareTest, OneByOneMagicSquare) {
    long long n = 1;
    unsigned long long data[] = {1};
    unsigned long long** square = createSquare(n, data);
    EXPECT_TRUE(isMagicSquare(square, n));
    freeSquare(square, n);
}

// Основная функция для запуска тестов
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}