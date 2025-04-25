#include "pch.h"
#include <gtest/gtest.h>
#include <iostream>
#include <clocale> // ��� setlocale


// ����� ��� ������� createFinalArray
TEST(CreateFinalArrayTests, AllEvenDiagonal) {
    ll lines = 3, columns = 3;
    ll** array = new ll * [lines];
    for (ll i = 0; i < lines; i++) {
        array[i] = new ll[columns];
    }

    array[0][0] = 2; array[0][1] = 1; array[0][2] = 3;
    array[1][0] = 4; array[1][1] = 6; array[1][2] = 1;
    array[2][0] = 1; array[2][1] = 2; array[2][2] = 8;

    ll final_array_size;
    ll* final_array = createFinalArray(array, lines, columns, final_array_size);

    EXPECT_EQ(final_array_size, 3);
    EXPECT_EQ(final_array[0], 2);
    EXPECT_EQ(final_array[1], 6);
    EXPECT_EQ(final_array[2], 8);

    // ������������ ������
    delete[] final_array;
    for (ll i = 0; i < lines; i++) {
        delete[] array[i];
    }
    delete[] array;
}

TEST(CreateFinalArrayTests, NoEvenDiagonal) {
    ll lines = 3, columns = 3;
    ll** array = new ll * [lines];
    for (ll i = 0; i < lines; i++) {
        array[i] = new ll[columns];
    }

    array[0][0] = 1; array[0][1] = 1; array[0][2] = 3;
    array[1][0] = 3; array[1][1] = 5; array[1][2] = 1;
    array[2][0] = 1; array[2][1] = 1; array[2][2] = 1;

    ll final_array_size;
    ll* final_array = createFinalArray(array, lines, columns, final_array_size);

    EXPECT_EQ(final_array_size, 0); // �������, ��� ������ ���������� ������� ����� 0

    // ������������ ������
    delete[] final_array; // �� �������� ���������� ������, ���� ���� ��� �������
    for (ll i = 0; i < lines; i++) {
        delete[] array[i];
    }
    delete[] array;
}

TEST(CreateFinalArrayTests, MixedDiagonal) {
    ll lines = 3, columns = 3;
    ll** array = new ll * [lines];
    for (ll i = 0; i < lines; i++) {
        array[i] = new ll[columns];
    }

    array[0][0] = 1; array[0][1] = 2; array[0][2] = 3;
    array[1][0] = 2; array[1][1] = 3; array[1][2] = 4;
    array[2][0] = 5; array[2][1] = 6; array[2][2] = 0;

    ll final_array_size;
    ll* final_array = createFinalArray(array, lines, columns, final_array_size);

    EXPECT_EQ(final_array_size, 1);
    EXPECT_EQ(final_array[0], 0);
   

    // ������������ ������
    delete[] final_array;
    for (ll i = 0; i < lines; i++) {
        delete[] array[i];
    }
    delete[] array;
}

// ����� ��� ������� calculateProduct
TEST(CalculateProductTests, ProductWithZero) {
    ll array[] = { 1, 0, 3, 4 }; // ������������ 0
    ll size = sizeof(array) / sizeof(array[0]);

    EXPECT_EQ(calculateProduct(array, size), 0); // �������, ��� ������������ ����� 0
}

TEST(CalculateProductTests, ProductWithOne) {
    ll array[] = { 1, 2, 3, 4 }; // ��� 0, ��� �������������
    ll size = sizeof(array) / sizeof(array[0]);

    EXPECT_EQ(calculateProduct(array, size), 24); // �������, ��� ������������ ����� 24
}

TEST(CalculateProductTests, EmptyArray) {
    ll* array = nullptr; // ������ ������
    ll size = 0;

    EXPECT_EQ(calculateProduct(array, size), 1); // �������, ��� ������������ ����� 1
}

// �������� ������� ��� ������� ������
int main(int argc, char** argv) {
    setlocale(LC_ALL, "Russian"); // ������������� ������ �� �������
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}