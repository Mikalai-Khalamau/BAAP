#include "..\StaticLibrary\Header.h"
#include <iostream>
#include <iomanip> // ��� std::setprecision
#define ll long long

// ������� ��� ����������� ������������ ����
void displayContextMenu() {
    std::cout << "������������ ������ �5, ������� �3\n";
    std::cout << "���� �������:\n";
    std::cout << "��� ��������� ������������ ������ ����� �����. �������� ��������� "
        << "������� ������� ������ � ����������. ������� ������������ ������ �� "
        << "���������, ������������� �� ������� ��������� ������� � ������� "
        << "������ ��������. ��������� ������������ ��������� ������������� �������.\n";
}

// ������� ��� �������� ����������� ����� long long �����
bool isLongLong(long long& number) {
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
ll** create2DArray(ll lines, ll columns) {
    ll** array = new ll * [lines];
    for (ll i = 0; i < lines; ++i) {
        array[i] = new ll[columns];
    }
    return array;
}

// ������� ��� ����� ��������� ���������� �������
void inputArray(ll** array, ll lines, ll columns) {
    std::cout << "������� �������� ������� (����� �����):\n";
    for (ll i = 0; i < lines; i++) {
        for (ll j = 0; j < columns; j++) {
            std::cout << "������� [" << i << "][" << j << "]: ";
            while (true) {
                if (isLongLong(array[i][j])) {
                    break;
                }
                else {
                    std::cout << "������: ������� ������������ �����. ���������� �����.\n";
                }
            }
        }
    }
}

// ������� ��� ������������ ������ ���������� �������
void freeArray(ll** array, ll lines) {
    for (ll i = 0; i < lines; ++i) {
        delete[] array[i];
    }
    delete[] array;
}

// ������� ��� ������ �������
void printArray(const ll* array, ll size) {
    for (ll i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";
}

// ������� ��� ������ ���������� �������
void print2DArray(ll** array, ll lines, ll columns) {
    std::cout << "��������� ������:\n";
    for (ll i = 0; i < lines; i++) {
        for (ll j = 0; j < columns; j++) {
            std::cout << array[i][j] << " ";
        }
        std::cout << "\n";
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

// ������� �������
int main() {
    setlocale(LC_ALL, "Russian_Russia.1251");

    while (true) {
        displayContextMenu();
        ll lines, columns;

        // ���� �������� �������
        inputDimensions(lines, columns);

        // ��������� ������ ��� ���������� �������
        ll** array = create2DArray(lines, columns);

        // ���� ��������� �������
        inputArray(array, lines, columns);

        // ����� ���������� �������
        print2DArray(array, lines, columns);

        // �������� ���������� �������
        ll final_array_size = 0;
        ll* final_array = createFinalArray(array, lines, columns, final_array_size);

        // ����� ���������� �������
        std::cout << "��������� ������ (������ �������� ������� ���������):\n";
        printArray(final_array, final_array_size);

        // ���������� � ����� ������������
        ll product = calculateProduct(final_array, final_array_size);
        std::cout << "������������ ��������� ������������� ������� ����� "
            << product << '\n';

        // ������������ ������
        delete[] final_array;
        freeArray(array, lines);

        // �������� �� ���������� ��� ������ �������
        if (!askForRepeat()) {
            break;
        }
    }

    return 0;
}