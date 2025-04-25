#include "pch.h"
#include <gtest/gtest.h>
#include <iostream>
#include <clocale> // ��� setlocale

// ���� ��� ������� checkCondition (��� �������� ������������� �������)
TEST(CheckConditionTests, AllElementsSatisfy) {
    ll array[] = { 0, 1, 4, 9, 16 }; // 0 <= 1^2, 1 <= 2^2, 4 <= 3^2, 9 <= 4^2, 16 <= 5^2
    ll size = sizeof(array) / sizeof(array[0]);

    EXPECT_TRUE(checkCondition(array, 0, size - 1));
}

// ���� ��� ������� checkCondition (���� ������� �� ������������� �������)
TEST(CheckConditionTests, OneElementDoesNotSatisfy) {
    ll array[] = { 0, 1, 4, 10, 16 }; // 10 > 4^2
    ll size = sizeof(array) / sizeof(array[0]);

    EXPECT_TRUE(checkCondition(array, 0, size - 1));
}

// ���� ��� ������� checkCondition (��� ���������, ��������������� �������)
TEST(CheckConditionTests, NoElementsSatisfy) {
    ll array[] = { 17, 18, 19, 20 }; // ��� �������� ������, ��� i^2 ��� ��������������� i
    ll size = sizeof(array) / sizeof(array[0]);

    EXPECT_FALSE(checkCondition(array, 0, size - 1));
}

// �������� ������� ��� ������� ������
int main(int argc, char** argv) {
    setlocale(LC_ALL, "Russian"); // ������������� ������ �� �������
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}