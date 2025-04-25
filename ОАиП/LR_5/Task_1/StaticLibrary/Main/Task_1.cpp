#include <iostream>
#include "..\StaticLibrary\Header.h"
#define ll long long

// ������� ��� ����������� ������������ ����
void displayContextMenu() {
    std::cout << "������������ ������ �5, ������� �1\n";
    std::cout << "���� �������:\n";
    std::cout << "��������� �������, � ������� �������� ����� ����� ��������� �� 2 ��������� �������� ������ �� ��������������� �������.\n";
}

// ������� ��� �������� ����������� ����� long long �����
bool isLongLong(ll& number) {
    std::cin >> number;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return false;
    }
    if (std::cin.peek() != '\n') {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return false;
    }
    return true;
}

// ������� ��� ��������� ������ ��� ��������� ������
long double** createMatrix(ll n) {
    long double** matrix = new long double* [n];
    for (ll i = 0; i < n; i++) {
        matrix[i] = new long double[n];
    }
    return matrix;
}

// ������� ��� ������������ ������ ���������� �������
void freeMatrix(long double** matrix, ll n) {
    for (ll i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

// ������� ��� �������� ����������� ����� long double �����
bool isLongDouble(long double& number) {
    std::cin >> number;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return false;
    }
    if (std::cin.peek() != '\n') {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return false;
    }
    return true;
}

// ������� ��� ����� ��������� �������
void inputMatrix(long double** matrix, ll n, char name) {
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            while (true) {
                std::cout << "������� ������� ������� " << name << " �� ������� " << i << "," << j << ":\n";
                if (isLongDouble(matrix[i][j])) {
                    break;
                }
                else {
                    std::cout << "������: ������� ������������ �����. ���������� �����.\n";
                }
            }
        }
    }
}

// ������� ��� ������ �������
void printMatrix(long double** matrix, ll n, char name) {
    std::cout << "������� " << name << ":\n";
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << '\n';
    }
}

// ������� ��� ���������� ������� �������
bool askForRepeat() {
    std::string choice;
    while (true) {
        std::cout << "������ ��������� ��� ���� ������? (y/n): ";
        std::cin >> choice;
        std::cin.clear();
        std::cin.ignore(10000, '\n');

        if (choice == "y" || choice == "Y" || choice == "��" || choice == "��" || choice == "yes" || choice == "YES") {
            std::cout << "\n----------------------------------------\n\n";
            return true;
        }
        else if (choice == "n" || choice == "N" || choice == "���" || choice == "���" || choice == "no" || choice == "NO") {
            std::cout << "���������� ���������. �� ��������!" << '\n';
            return false;
        }
        else {
            std::cout << "������������ ����. ����������, ������� 'y' ��� 'n'.\n";
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian_Russia.1251");

    while (true) {
        displayContextMenu();
        ll n;
        std::cout << "������� ����������� �������� (����� ������������� �����):\n";
        while (true) {
            if (isLongLong(n) && n > 0) {
                break;
            }
            else {
                std::cout << "������: ������� ������������ �����. ���������� �����.\n";
            }
        }

        // ��������� ������ ��� ������
        long double** b = createMatrix(n);
        long double** c = createMatrix(n);
        long double** a = createMatrix(n);

        // ���� ��������� ��� ������� b
        inputMatrix(b, n, 'b');

        // ���� ��������� ��� ������� c
        inputMatrix(c, n, 'c');

        // ���������� ������� a
        fillMatrixA(a, b, c, n);

        // ����� ������� a
        printMatrix(a, n, 'a');

        // ������������ ������
        freeMatrix(a, n);
        freeMatrix(b, n);
        freeMatrix(c, n);

        // �������� �� ��������� ����
        if (!askForRepeat()) {
            break;
        }
    }

    return 0;
}