#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

// Типы групп
enum GroupType {
    STRING_GROUP,
    NUMERIC_GROUP
};

// Минимальная зарплата
static const long double MIN_WAGE = 626.0;

// Структура группы
struct Group {
    GroupType grpType;
    union {
        int groupNum;
        char groupStr[20];
    } group;
};

// Структура студента
struct Student {
    bool isDeleted; // Флаг для пометки удаления
    char fio[60];
    Group group;
    long double averageScore;
    long double income;
};

// Прототипы функций
Student* formArray(int& size);
void viewArray(const Student* students, int size);
Student* addElements(Student* students, int& size, const char* filename);
void searchElements(const Student* students, int size);
Student* deleteElement(Student* students, int& size, const char* filename);
void modifyElement(Student* students, int size, const char* filename);
void sortArrayByAverage(Student* students, int size);
void sortDormList(Student* students, int size);
void loadFromFile(Student*& students, int& count, const char* filename);
void saveToFile(const Student* students, int count, const char* filename);

#endif // HEADER_H