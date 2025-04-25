// Header.h
#pragma once
#define ll long long

extern "C" __declspec(dllexport) bool checkCondition(ll* array, ll start, ll end);
extern "C" __declspec(dllexport) void checkAndDisplayCondition(ll* array, ll size);

// DynamicLibrary.cpp
#include "Header.h"
#include <iostream>

extern "C" __declspec(dllexport) bool checkCondition(ll* array, ll start, ll end) {
    // Проверка на пустой массив
    if (start > end) {
        return false;
    }
    // Проверка на единственный элемент
    if (start == end) {
        return array[start] <= (start * start); // Исправлено на правильный индекс
    }

    ll mid = (start + end) / 2;

    // Проверяем обе половины
    return checkCondition(array, start, mid) || checkCondition(array, mid + 1, end);
}

extern "C" __declspec(dllexport) void checkAndDisplayCondition(ll* array, ll size) {
    if (size <= 0) {
        std::cout << "Массив пуст." << '\n';
        return;
    }

    if (checkCondition(array, 0, size - 1)) {
        std::cout << "Существует хотя бы один элемент Ai, для которого Ai <= i^2." << '\n';
    }
    else {
        std::cout << "Нет элементов Ai, для которых Ai <= i^2." << '\n';
    }
}