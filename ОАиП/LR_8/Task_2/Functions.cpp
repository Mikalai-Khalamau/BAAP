#include "header.h"

// Функция для ввода положительного long double
long double inputPositiveLongDouble(const char* prompt) {
    long double value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail() || value <= 0) {
            std::cout << "Ошибка! Введите положительное число.\n";
            std::cin.clear(); // Сбрасываем флаг ошибки
            std::cin.ignore(10000, '\n'); // Игнорируем остаток строки
        } else {
            std::cin.ignore(10000, '\n'); // Игнорируем остаток строки
            return value;
        }
    }
}

// Функция для формирования массива студентов
Student* formArray(int& size) {
    std::cout << "Введите количество записей: ";
    std::cin >> size;
    std::cin.ignore(10000, '\n'); // Игнорируем остаток строки

    if (size <= 0) {
        std::cout << "Некорректный размер. Создаём массив из 0 элементов.\n";
        size = 0;
        return nullptr;
    }

    Student* arr = new Student[size];
    for (int i = 0; i < size; i++) {
        std::cout << "\n=== Запись №" << (i + 1) << " ===\n";

        std::cout << "Введите Ф.И.О.: ";
        std::cin.getline(arr[i].fio, 60);

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }

        // Определение типа группы по первому символу Ф.И.О.
        if (arr[i].fio[0] >= '0' && arr[i].fio[0] <= '9') {
            arr[i].group.grpType = NUMERIC_GROUP;
            arr[i].group.group.groupNum = 0;
            // Преобразование всей строки в число (предполагается, что Ф.И.О. - число)
            for (int j = 0; arr[i].fio[j] != '\0'; j++) {
                if (arr[i].fio[j] < '0' || arr[i].fio[j] > '9') {
                    arr[i].group.group.groupNum = 0;
                    break;
                }
                arr[i].group.group.groupNum = arr[i].group.group.groupNum * 10 + (arr[i].fio[j] - '0');
            }
        } else {
            arr[i].group.grpType = STRING_GROUP;
            std::cout << "Введите группу (строка): ";
            std::cin.getline(arr[i].group.group.groupStr, 20);
        }

        arr[i].averageScore = inputPositiveLongDouble("Введите средний балл: ");
        arr[i].income = inputPositiveLongDouble("Введите доход на члена семьи: ");
    }

    return arr;
}

// Функция для просмотра содержимого массива
void viewArray(const Student* arr, int size) {
    if (!arr || size == 0) {
        std::cout << "Массив пуст или не создан.\n";
        return;
    }

    std::cout << "\nСодержимое массива:\n";
    for (int i = 0; i < size; i++) {
        std::cout << "\n=== Элемент №" << (i + 1) << " ===\n";
        std::cout << "Ф.И.О.: " << arr[i].fio << "\n";
        if (arr[i].group.grpType == NUMERIC_GROUP) {
            std::cout << "Группа (число): " << arr[i].group.group.groupNum << "\n";
        } else {
            std::cout << "Группа (строка): " << arr[i].group.group.groupStr << "\n";
        }
        std::cout << "Средний балл: " << arr[i].averageScore << "\n";
        std::cout << "Доход на члена семьи: " << arr[i].income << "\n";
    }
}

// Функция для добавления элементов в существующий массив
Student* addElements(Student* arr, int& size) {
    std::cout << "Сколько новых записей хотите добавить? ";
    int count;
    std::cin >> count;
    std::cin.ignore(10000, '\n');

    if (count <= 0) {
        std::cout << "Ничего не добавлено.\n";
        return arr;
    }

    Student* newArr = new Student[size + count];
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }

    for (int i = size; i < size + count; i++) {
        std::cout << "\n=== Новая запись №" << (i + 1) << " ===\n";
        std::cout << "Введите Ф.И.О.: ";
        std::cin.getline(newArr[i].fio, 60);

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }

        // Определение типа группы по первому символу Ф.И.О.
        if (newArr[i].fio[0] >= '0' && newArr[i].fio[0] <= '9') {
            newArr[i].group.grpType = NUMERIC_GROUP;
            newArr[i].group.group.groupNum = 0;
            // Преобразование всей строки в число (предполагается, что Ф.И.О. - число)
            for (int j = 0; newArr[i].fio[j] != '\0'; j++) {
                if (newArr[i].fio[j] < '0' || newArr[i].fio[j] > '9') {
                    newArr[i].group.group.groupNum = 0;
                    break;
                }
                newArr[i].group.group.groupNum = newArr[i].group.group.groupNum * 10 + (newArr[i].fio[j] - '0');
            }
        } else {
            newArr[i].group.grpType = STRING_GROUP;
            std::cout << "Введите группу (строка): ";
            std::cin.getline(newArr[i].group.group.groupStr, 20);
        }

        newArr[i].averageScore = inputPositiveLongDouble("Введите средний балл: ");
        newArr[i].income = inputPositiveLongDouble("Введите доход на члена семьи: ");
    }

    delete[] arr; // Освобождаем память старого массива
    size += count;
    return newArr;
}

// Функция для поиска элементов
void searchElements(const Student* arr, int size) {
    if (!arr || size == 0) {
        std::cout << "Массив пуст.\n";
        return;
    }
    std::cout << "Выберите поле для поиска:\n";
    std::cout << "1 - По Ф.И.О.\n";
    std::cout << "2 - По группе (число или строка).\n";
    std::cout << "3 - По среднему баллу.\n";
    std::cout << "4 - По доходу.\n";
    std::cout << "Ваш выбор: ";
    int choice;
    std::cin >> choice;
    std::cin.ignore(10000, '\n');

    bool found = false;
    switch (choice) {
        case 1: {
            char fioSearch[60];
            std::cout << "Введите Ф.И.О. для поиска: ";
            std::cin.getline(fioSearch, 60);
            for (int i = 0; i < size; i++) {
                bool match = true;
                for (int j = 0; fioSearch[j] != '\0' || arr[i].fio[j] != '\0'; j++) {
                    if (fioSearch[j] != arr[i].fio[j]) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    found = true;
                    std::cout << "\nНайден элемент №" << (i + 1) << ":\n";
                    std::cout << "Ф.И.О.: " << arr[i].fio << "\n";
                    if (arr[i].group.grpType == NUMERIC_GROUP) {
                        std::cout << "Группа (число): " << arr[i].group.group.groupNum << "\n";
                    } else {
                        std::cout << "Группа (строка): " << arr[i].group.group.groupStr << "\n";
                    }
                    std::cout << "Средний балл: " << arr[i].averageScore << "\n";
                    std::cout << "Доход: " << arr[i].income << "\n";
                }
            }
            break;
        }
        case 2: {
            std::cout << "Ищем по группе. Группа может быть числом или строкой.\n";
            std::cout << "Вы хотите искать число (1) или строку (2)? ";
            int subChoice;
            std::cin >> subChoice;
            std::cin.ignore(10000, '\n');
            if (subChoice == 1) {
                int grpNum;
                std::cout << "Введите числовую группу: ";
                std::cin >> grpNum;
                std::cin.ignore(10000, '\n');
                for (int i = 0; i < size; i++) {
                    if (arr[i].group.grpType == NUMERIC_GROUP && arr[i].group.group.groupNum == grpNum) {
                        found = true;
                        std::cout << "\nНайден элемент №" << (i + 1) << ":\n";
                        std::cout << "Ф.И.О.: " << arr[i].fio << "\n";
                        std::cout << "Группа (число): " << arr[i].group.group.groupNum << "\n";
                        std::cout << "Средний балл: " << arr[i].averageScore << "\n";
                        std::cout << "Доход: " << arr[i].income << "\n";
                    }
                }
            } else if (subChoice == 2) {
                char grpStr[20];
                std::cout << "Введите группу (строка): ";
                std::cin.getline(grpStr, 20);
                for (int i = 0; i < size; i++) {
                    bool match = true;
                    for (int j = 0; grpStr[j] != '\0' || arr[i].group.group.groupStr[j] != '\0'; j++) {
                        if (grpStr[j] != arr[i].group.group.groupStr[j]) {
                            match = false;
                            break;
                        }
                    }
                    if (arr[i].group.grpType == STRING_GROUP && match) {
                        found = true;
                        std::cout << "\nНайден элемент №" << (i + 1) << ":\n";
                        std::cout << "Ф.И.О.: " << arr[i].fio << "\n";
                        std::cout << "Группа (строка): " << arr[i].group.group.groupStr << "\n";
                        std::cout << "Средний балл: " << arr[i].averageScore << "\n";
                        std::cout << "Доход: " << arr[i].income << "\n";
                    }
                }
            } else {
                std::cout << "Неверный выбор.\n";
                return;
            }
            break;
        }
        case 3: {
            long double avgSearch = inputPositiveLongDouble("Введите средний балл для поиска: ");
            for (int i = 0; i < size; i++) {
                if (arr[i].averageScore == avgSearch) {
                    found = true;
                    std::cout << "\nНайден элемент №" << (i + 1) << ":\n";
                    std::cout << "Ф.И.О.: " << arr[i].fio << "\n";
                    if (arr[i].group.grpType == NUMERIC_GROUP) {
                        std::cout << "Группа (число): " << arr[i].group.group.groupNum << "\n";
                    } else {
                        std::cout << "Группа (строка): " << arr[i].group.group.groupStr << "\n";
                    }
                    std::cout << "Средний балл: " << arr[i].averageScore << "\n";
                    std::cout << "Доход: " << arr[i].income << "\n";
                }
            }
            break;
        }
        case 4: {
            long double incSearch = inputPositiveLongDouble("Введите доход для поиска: ");
            for (int i = 0; i < size; i++) {
                if (arr[i].income == incSearch) {
                    found = true;
                    std::cout << "\nНайден элемент №" << (i + 1) << ":\n";
                    std::cout << "Ф.И.О.: " << arr[i].fio << "\n";
                    if (arr[i].group.grpType == NUMERIC_GROUP) {
                        std::cout << "Группа (число): " << arr[i].group.group.groupNum << "\n";
                    } else {
                        std::cout << "Группа (строка): " << arr[i].group.group.groupStr << "\n";
                    }
                    std::cout << "Средний балл: " << arr[i].averageScore << "\n";
                    std::cout << "Доход: " << arr[i].income << "\n";
                }
            }
            break;
        }
        default:
            std::cout << "Неверный выбор.\n";
    }
    if (!found) {
        std::cout << "Ничего не найдено.\n";
    }
}

// Функция для удаления элемента по ФИО
Student* deleteElement(Student* arr, int& size) {
    if (!arr || size == 0) {
        std::cout << "Массив пуст.\n";
        return arr;
    }
    std::cout << "Удаление по Ф.И.О. (в качестве примера).\n";
    std::cout << "Введите Ф.И.О. для удаления: ";
    char fioDel[60];
    std::cin.getline(fioDel, 60);

    int indexToDelete = -1;
    for (int i = 0; i < size; i++) {
        bool match = true;
        for (int j = 0; fioDel[j] != '\0' || arr[i].fio[j] != '\0'; j++) {
            if (fioDel[j] != arr[i].fio[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            indexToDelete = i;
            break;
        }
    }
    if (indexToDelete == -1) {
        std::cout << "Элемент с таким Ф.И.О. не найден.\n";
        return arr;
    }

    Student* newArr = nullptr;
    if (size - 1 > 0) {
        newArr = new Student[size - 1];
        for (int i = 0, j = 0; i < size; i++) {
            if (i != indexToDelete) {
                newArr[j++] = arr[i];
            }
        }
    }
    delete[] arr;
    size--;
    std::cout << "Элемент успешно удалён.\n";
    return newArr;
}

// Функция для изменения элемента по ФИО
void modifyElement(Student* arr, int size) {
    if (!arr || size == 0) {
        std::cout << "Массив пуст.\n";
        return;
    }
    std::cout << "Изменение по Ф.И.О. (в качестве примера).\n";
    std::cout << "Введите Ф.И.О. студента, запись которого хотите изменить: ";
    char fioMod[60];
    std::cin.getline(fioMod, 60);

    int indexToModify = -1;
    for (int i = 0; i < size; i++) {
        bool match = true;
        for (int j = 0; fioMod[j] != '\0' || arr[i].fio[j] != '\0'; j++) {
            if (fioMod[j] != arr[i].fio[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            indexToModify = i;
            break;
        }
    }
    if (indexToModify == -1) {
        std::cout << "Студент с таким Ф.И.О. не найден.\n";
        return;
    }

    std::cout << "Введите новые данные.\n";
    std::cout << "Ф.И.О.: ";
    std::cin.getline(arr[indexToModify].fio, 60);

    std::cout << "Группа — введите 1 для числовой или 2 для строковой: ";
    int subChoice;
    std::cin >> subChoice;
    std::cin.ignore(10000, '\n');
    if (subChoice == 1) {
        arr[indexToModify].group.grpType = NUMERIC_GROUP;
        std::cout << "Введите числовую группу: ";
        std::cin >> arr[indexToModify].group.group.groupNum;
        std::cin.ignore(10000, '\n');
    } else if (subChoice == 2) {
        arr[indexToModify].group.grpType = STRING_GROUP;
        std::cout << "Введите строку для группы: ";
        std::cin.getline(arr[indexToModify].group.group.groupStr, 20);
    } else {
        std::cout << "Неверный выбор типа группы. Группа не изменена.\n";
    }

    arr[indexToModify].averageScore = inputPositiveLongDouble("Введите средний балл: ");
    arr[indexToModify].income = inputPositiveLongDouble("Введите доход на члена семьи: ");

    std::cout << "Данные успешно изменены.\n";
}

// Функция для сортировки массива по среднему баллу (по возрастанию)
void sortArrayByAverage(Student* arr, int size) {
    if (!arr || size < 2) {
        std::cout << "Сортировка не требуется.\n";
        return;
    }
    // Пузырьковая сортировка
    bool swapped;
    for (int i = 0; i < size - 1; i++) {
        swapped = false;
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j].averageScore > arr[j + 1].averageScore) {
                // Обмен
                Student temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
    std::cout << "Сортировка по среднему баллу (возрастание) выполнена.\n";
}

// Функция для сортировки списка общежития
void sortDormList(Student* arr, int size) {
    if (!arr || size < 2) {
        std::cout << "Сортировка не требуется.\n";
        return;
    }

    // Разделение на две группы
    Student* group1 = new Student[size];
    Student* group2 = new Student[size];
    int count1 = 0, count2 = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i].income < 2.0L * MIN_WAGE) {
            group1[count1++] = arr[i];
        } else {
            group2[count2++] = arr[i];
        }
    }

    // Сортировка каждой группы по убыванию среднего балла
    auto sortGroupDesc = [](Student* group, int count) {
        for (int i = 0; i < count - 1; i++) {
            for (int j = 0; j < count - 1 - i; j++) {
                if (group[j].averageScore < group[j + 1].averageScore) {
                    Student temp = group[j];
                    group[j] = group[j + 1];
                    group[j + 1] = temp;
                }
            }
        }
    };

    sortGroupDesc(group1, count1);
    sortGroupDesc(group2, count2);

    // Объединение обратно
    int idx = 0;
    for (int i = 0; i < count1; i++) {
        arr[idx++] = group1[i];
    }
    for (int i = 0; i < count2; i++) {
        arr[idx++] = group2[i];
    }

    delete[] group1;
    delete[] group2;

    std::cout << "Сортировка для общежития выполнена (сначала доход < 2*MIN_WAGE, затем по убыванию балла).\n";
}

// Функция для сохранения студентов в текстовый файл
void saveToFile(const Student* students, int count, const char* filename) {
    std::ofstream file(filename);
    if (!file) {
        std::cout << "Ошибка открытия файла для записи.\n";
        return;
    }

    for (int i = 0; i < count; ++i) {
        file << students[i].fio << "\n";
        if (students[i].group.grpType == NUMERIC_GROUP) {
            file << "NUMERIC " << students[i].group.group.groupNum << "\n";
        } else {
            file << "STRING " << students[i].group.group.groupStr << "\n";
        }
        file << students[i].averageScore << "\n";
        file << students[i].income << "\n";
    }

    file.close();
    std::cout << "Студенты успешно сохранены в файл.\n";
}

// Функция для загрузки студентов из текстового файла
void loadFromFile(Student*& students, int& count, const char* filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cout << "Ошибка открытия файла для чтения.\n";
        return;
    }

    // Определение количества записей
    count = 0;
    std::string line;
    while (std::getline(file, line)) {
        count++;
    }

    // Каждый студент занимает 4 строки, поэтому корректируем количество
    count /= 4;
    file.clear();
    file.seekg(0, std::ios::beg);

    if (count <= 0) {
        std::cout << "Файл пуст или содержит некорректные данные.\n";
        return;
    }

    // Выделение памяти для студентов
    delete[] students;
    students = new Student[count];

    for (int i = 0; i < count; i++) {
        // Чтение Ф.И.О.
        std::getline(file, line);
       size_t j;
for (j = 0; j < 59 && line[j] != '\0'; ++j) {
    students[i].fio[j] = line[j];
}
students[i].fio[j] = '\0';
        students[i].fio[59] = '\0';

        // Чтение типа группы и значения
        std::getline(file, line);
        if (line.substr(0, 7) == "NUMERIC") {
            students[i].group.grpType = NUMERIC_GROUP;
            students[i].group.group.groupNum = atoi(line.substr(8).c_str());
        } else if (line.substr(0, 6) == "STRING") {
            students[i].group.grpType = STRING_GROUP;
            size_t j;
for (j = 0; j < 19 && line[j + 7] != '\0'; ++j) {
    students[i].group.group.groupStr[j] = line[j + 7];
}
students[i].group.group.groupStr[j] = '\0'; // Завершаем строку нулевым символом
            students[i].group.group.groupStr[19] = '\0';
        } else {
            std::cout << "Некорректный тип группы в файле.\n";
            delete[] students;
            students = nullptr;
            count = 0;
            return;
        }

        // Чтение среднего балла
        std::getline(file, line);
        students[i].averageScore = atof(line.c_str());

        // Чтение дохода
        std::getline(file, line);
        students[i].income = atof(line.c_str());
    }

    file.close();
    std::cout << "Студенты успешно загружены из файла.\n";
}