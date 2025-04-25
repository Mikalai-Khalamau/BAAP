#include "..\StaticLibrary\Header.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

#define ll long long

// ������� ��� ����������� ������������ ����
void displayContextMenu() {
    std::cout << "������������ ������ �5, ������� �4\n";
    std::cout << "���� �������:\n";
    std::cout << "������� ��������� ������������ ������ ������������ �����. ����������, "
        "����������� �� ����� ��� �������� � ������� ���������. ���� ����������� "
        "����� ��������, �� ���������� �� ������� � ����� ����������. ����������� "
        "�������� ����� ������� � �������� ������� � ������� �� �����.\n";
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

// ������� ��� ����� ���������� ����� � ��������
void inputDimensions(ll& lines, ll& columns) {
    std::cout << "������� ���������� ����� ���������� ������� (����� �����):\n";
    while (true) {
        if (isLongLong(lines) && lines > 0) {
            break;
        }
        else {
            std::cout << "������: ������� ������������ �����. ���������� �����.\n";
        }
    }

    std::cout << "������� ���������� �������� ���������� ������� (����� �����):\n";
    while (true) {
        if (isLongLong(columns) && columns > 0) {
            break;
        }
        else {
            std::cout << "������: ������� ������������ �����. ���������� �����.\n";
        }
    }
}

// ������� ��� ��������� ������ ��� ���������� �������
long double** create2DArray(ll lines, ll columns) {
    long double** array = new long double* [lines];
    for (ll i = 0; i < lines; ++i) {
        array[i] = new long double[columns];
    }
    return array;
}

void inputArray(long double** array, ll lines, ll columns) {
    for (ll i = 0; i < lines; i++) {
        for (ll j = 0; j < columns; j++) {
            // � ������������ 20% ����������� 0
            if (rand() % 100 < 20) {
                array[i][j] = 0;
            }
            else {
                array[i][j] = static_cast<long double>(rand()) / RAND_MAX * 200.0 - 100.0;
            }
        }
    }
}


// ������� ��� ������ ���������� �������
void print2DArray(long double** array, ll lines, ll columns) {
    std::cout << "��������� ������ ��������� ����� ���� long double:\n";
    for (ll i = 0; i < lines; i++) {
        for (ll j = 0; j < columns; j++) {
            std::cout << array[i][j] << " ";
        }
        std::cout << "\n";
    }
}

// ������� ��� ������������ ������ ���������� �������
void freeArray(long double** array, ll lines) {
    for (ll i = 0; i < lines; ++i) {
        delete[] array[i];
    }
    delete[] array;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    setlocale(LC_ALL, "Russian_Russia.1251");

    do {
        ll lines, columns;

        // ����������� ������������ ����
        displayContextMenu();

        // ���� �������� �������
        inputDimensions(lines, columns);

        // ��������� ������ ��� ���������� �������
        long double** array = create2DArray(lines, columns);

        // ���� ��������� �������
        inputArray(array, lines, columns);

        // ����� ���������� �������
        print2DArray(array, lines, columns);

        // ������� ������� ���������
        Zeros(array, lines, columns);

        // ������������ ���������
        reverseMatrix(array, lines, columns);

        std::cout << "���������� ������:\n";
        // ����� ����������� ���������� �������
        print2DArray(array, lines, columns);

        // ������������ ������
        freeArray(array, lines);

    } while (askForRepeat());

    return 0;
}