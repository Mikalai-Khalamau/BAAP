// Header.h
#pragma once
#define ll long long

extern "C" __declspec(dllexport) bool checkCondition(ll* array, ll start, ll end);
extern "C" __declspec(dllexport) void checkAndDisplayCondition(ll* array, ll size);

// DynamicLibrary.cpp
#include "Header.h"
#include <iostream>

extern "C" __declspec(dllexport) bool checkCondition(ll* array, ll start, ll end) {
    // �������� �� ������ ������
    if (start > end) {
        return false;
    }
    // �������� �� ������������ �������
    if (start == end) {
        return array[start] <= (start * start); // ���������� �� ���������� ������
    }

    ll mid = (start + end) / 2;

    // ��������� ��� ��������
    return checkCondition(array, start, mid) || checkCondition(array, mid + 1, end);
}

extern "C" __declspec(dllexport) void checkAndDisplayCondition(ll* array, ll size) {
    if (size <= 0) {
        std::cout << "������ ����." << '\n';
        return;
    }

    if (checkCondition(array, 0, size - 1)) {
        std::cout << "���������� ���� �� ���� ������� Ai, ��� �������� Ai <= i^2." << '\n';
    }
    else {
        std::cout << "��� ��������� Ai, ��� ������� Ai <= i^2." << '\n';
    }
}