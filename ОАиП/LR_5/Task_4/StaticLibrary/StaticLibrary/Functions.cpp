#include "Header.h"
#include <iostream>

// ������� ��� �������� ���������� ������� ��������� � ������ �� �������
void Zeros(long double** array, ll lines, ll columns) {
    ll zeros = 0;
    for (ll i = 0; i < lines; i++) {
        for (ll j = 0; j < columns; j++) {
            if (array[i][j] == 0) {
                zeros++;
                std::cout << "������� ������� �� ������� " << i << "," << j << '\n';
            }
        }
    }
    std::cout << "���������� ����� � ��������� ������� ����� " << zeros << '\n';
}

// ������� ��� ������������ ��������� ���������� ������� � �������� �������
void reverseMatrix(long double** array, ll rows, ll cols) {
    for (ll i = 0; i < rows; i++) {
        for (ll j = 0; j < cols / 2; j++) {
            std::swap(array[i][j], array[i][cols - 1 - j]);
        }
    }
}