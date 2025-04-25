#include "Header.h"

// ������� ��� �������� ���������� ������� �� �������� ��������� ������ ��������
ll* createFinalArray(ll** array, ll lines, ll columns, ll& final_array_size) {
    final_array_size = 0;

    // ������� ������� ���������� �������
    for (ll i = 0; i < lines; i++) {
        for (ll j = 0; j < columns; j++) {
            if (j % 2 == 0 && array[i][j] % 2 != 0) {
                final_array_size++;
            }
        }
    }

    // �������� ���������� �������
    ll* final_array = new ll[final_array_size];
    ll k = 0;

    // ���������� ���������� �������
    for (ll i = 0; i < lines; i++) {
        for (ll j = 0; j < columns; j++) {
            if (j % 2 == 0 && array[i][j] % 2 != 0) {
                final_array[k] = array[i][j];
                k++;
            }
        }
    }

    return final_array;
}

// ������� ��� �������� ����� ��������� �������
ll calculateSum(const ll* array, ll size) {
    ll sum = 0;
    for (ll i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum;
}

// ������� ��� ���������� �������� ��������
double calculateAverage(const ll* array, ll size) {
    if (size == 0) return 0.0; // ������������� ������� �� ����
    return static_cast<double>(calculateSum(array, size)) / size;
}