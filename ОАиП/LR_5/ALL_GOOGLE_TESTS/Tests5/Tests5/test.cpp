#include "pch.h"
#include <gtest/gtest.h>
#include <iostream>
#include <clocale> // ��� setlocale
#include <cmath>   // ��� std::abs

// ����� ��� �������
TEST(ArrayTests, CreateFinalArray) {
    ll lines = 3, columns = 4;
    ll** array = new ll * [lines];
    for (ll i = 0; i < lines; i++) {
        array[i] = new ll[columns];
    }

    // ������������� �������
    array[0][0] = 1; array[0][1] = 2; array[0][2] = 3; array[0][3] = 4;
    array[1][0] = 5; array[1][1] = 6; array[1][2] = 7; array[1][3] = 8;
    array[2][0] = 9; array[2][1] = 10; array[2][2] = 11; array[2][3] = 12;

    ll final_array_size;
    ll* final_array = createFinalArray(array, lines, columns, final_array_size);

    // �������� �����������
    EXPECT_EQ(final_array_size, 6); // ������� 3 �������� �������� � ������ ��������
    EXPECT_EQ(final_array[0], 1);    // ������ �������� ����� � 0-�� �������
    EXPECT_EQ(final_array[1], 3);    // ������ �������� ����� � 0-�� �������
    EXPECT_EQ(final_array[2], 5);    // ������ �������� ����� � 0-�� �������
    EXPECT_EQ(final_array[3], 7);    
    EXPECT_EQ(final_array[4], 9);    
    EXPECT_EQ(final_array[5], 11);
    // ������������ ������
    delete[] final_array;
    for (ll i = 0; i < lines; i++) {
        delete[] array[i];
    }
    delete[] array;
}

TEST(ArrayTests, CalculateSum) {
    ll array[] = { 1, 2, 3, 4, 5 };
    ll size = sizeof(array) / sizeof(array[0]);

    EXPECT_EQ(calculateSum(array, size), 15); // �������, ��� ����� ����� 15
}

TEST(ArrayTests, CalculateAverage) {
    ll array[] = { 1, 2, 3, 4, 5 };
    ll size = sizeof(array) / sizeof(array[0]);

    EXPECT_DOUBLE_EQ(calculateAverage(array, size), 3.0); // �������, ��� ������� �������� ����� 3.0
}

TEST(ArrayTests, CalculateAverageEmptyArray) {
    ll* array = nullptr;
    ll size = 0;

    EXPECT_DOUBLE_EQ(calculateAverage(array, size), 0.0); // �������, ��� ������� �������� ����� 0.0
}

// �������� ������� ��� ������� ������
int main(int argc, char** argv) {
    setlocale(LC_ALL, "Russian"); // ������������� ������ �� �������
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}