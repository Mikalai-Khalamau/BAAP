#include <gtest/gtest.h>
#include <iostream>
#include "../Main/prot.h"

// Тест для функции MainQuestion
TEST(MainQuestionTest, Matrix3) {
    long long N = 3;
    long double** matrix = new long double*[N];
    for (long long i = 0; i < N; i++) {
        matrix[i] = new long double[N];
    }

    // Инициализация матрицы
    matrix[0][0] = 1.0; matrix[0][1] = 2.0; matrix[0][2] = 3.0;
    matrix[1][0] = 4.0; matrix[1][1] = 5.0; matrix[1][2] = 6.0;
    matrix[2][0] = 1.0; matrix[2][1] = 0.0; matrix[2][2] = 3.0;

    long double sum = 0.0;
    long double product = 1.0;

    // Вызов функции
    MainQuestion(matrix, N, sum, product);

    // Проверка результатов
    EXPECT_DOUBLE_EQ(sum, 15.0);         // Ожидаемая сумма
    EXPECT_DOUBLE_EQ(product, 0.0);     // Ожидаемое произведение

    // Освобождение памяти
    for (long long i = 0; i < N; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

// Тест для функции MainQuestion
TEST(MainQuestionTest, Matrix2) {
    long long N = 2;
    long double** matrix = new long double*[N];
    for (long long i = 0; i < N; i++) {
        matrix[i] = new long double[N];
    }

    // Инициализация матрицы
    matrix[0][0] = 1.0; matrix[0][1] = 2.0; 
    matrix[1][0] = 4.0; matrix[1][1] = 54.0;

    long double sum = 0.0;
    long double product = 1.0;

    // Вызов функции
    MainQuestion(matrix, N, sum, product);

    // Проверка результатов
    EXPECT_DOUBLE_EQ(sum, 61.0);         // Ожидаемая сумма
    EXPECT_DOUBLE_EQ(product, 432.0);     // Ожидаемое произведение

    // Освобождение памяти
    for (long long i = 0; i < N; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

// Тест для функции MainQuestion
TEST(MainQuestionTest, Matrix1) {
    long long N = 1;
    long double** matrix = new long double*[N];
    for (long long i = 0; i < N; i++) {
        matrix[i] = new long double[N];
    }

    // Инициализация матрицы
    matrix[0][0] = 1.0; 

    long double sum = 0.0;
    long double product = 1.0;

    // Вызов функции
    MainQuestion(matrix, N, sum, product);

    // Проверка результатов
    EXPECT_DOUBLE_EQ(sum, 1.0);         // Ожидаемая сумма
    EXPECT_DOUBLE_EQ(product, 1.0);     // Ожидаемое произведение

    // Освобождение памяти
    for (long long i = 0; i < N; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

// Основная функция для запуска тестов
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
