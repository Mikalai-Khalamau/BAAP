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
        arr[i].isDeleted = false; // Инициализируем как не удалённую

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
        if (arr[i].isDeleted) continue; // Пропускаем удалённые записи

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
Student* addElements(Student* arr, int& size, const char* filename) {
    std::cout << "Сколько новых записей хотите добавить? ";
    int count;
    std::cin >> count;
    std::cin.ignore(10000, '\n');

    if (count <= 0) {
        std::cout << "Ничего не добавлено.\n";
        return arr;
    }

    // Открываем файл для добавления новых записей
    std::ofstream file(filename, std::ios::binary | std::ios::app);
    if (!file) {
        std::cout << "Ошибка открытия файла для добавления.\n";
        return arr;
    }

    // Расширяем массив в памяти
    Student* newArr = new Student[size + count];
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }

    for (int i = size; i < size + count; i++) {
        std::cout << "\n=== Новая запись №" << (i + 1) << " ===\n";
        newArr[i].isDeleted = false; // Инициализируем как не удалённую

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

        // Записываем новую запись в файл
        file.write(reinterpret_cast<char*>(&newArr[i]), sizeof(Student));
    }

    file.close();
    std::cout << "Новые записи добавлены.\n";

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
                if (arr[i].isDeleted) continue;

                if (std::strncmp(fioSearch, arr[i].fio, 60) == 0) {
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
                    if (arr[i].isDeleted) continue;

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
                    if (arr[i].isDeleted) continue;

                    if (arr[i].group.grpType == STRING_GROUP && std::strncmp(grpStr, arr[i].group.group.groupStr, 20) == 0) {
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
                if (arr[i].isDeleted) continue;

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
                if (arr[i].isDeleted) continue;

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
Student* deleteElement(Student* arr, int& size, const char* filename) {
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
        if (arr[i].isDeleted) continue;

        if (std::strncmp(fioDel, arr[i].fio, 60) == 0) {
            indexToDelete = i;
            break;
        }
    }
    if (indexToDelete == -1) {
        std::cout << "Элемент с таким Ф.И.О. не найден.\n";
        return arr;
    }

    // Открываем файл для обновления записи
    std::fstream file(filename, std::ios::binary | std::ios::in | std::ios::out);
    if (!file) {
        std::cout << "Ошибка открытия файла для обновления.\n";
        return arr;
    }

    // Помечаем запись как удалённую
    arr[indexToDelete].isDeleted = true;
    file.seekp(indexToDelete * sizeof(Student), std::ios::beg);
    file.write(reinterpret_cast<char*>(&arr[indexToDelete]), sizeof(Student));

    file.close();
    std::cout << "Элемент успешно удалён.\n";
    return arr;
}

// Функция для изменения элемента по ФИО
void modifyElement(Student* arr, int size, const char* filename) {
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
        if (arr[i].isDeleted) continue;

        if (std::strncmp(fioMod, arr[i].fio, 60) == 0) {
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

    // Открываем файл для обновления записи
    std::fstream file(filename, std::ios::binary | std::ios::in | std::ios::out);
    if (!file) {
        std::cout << "Ошибка открытия файла для обновления.\n";
        return;
    }

    // Записываем изменённую запись в файл
    file.seekp(indexToModify * sizeof(Student), std::ios::beg);
    file.write(reinterpret_cast<char*>(&arr[indexToModify]), sizeof(Student));

    file.close();
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
            if (arr[j].isDeleted) continue;
            for (int k = j + 1; k < size; k++) {
                if (arr[k].isDeleted) continue;
                if (arr[j].averageScore > arr[k].averageScore) {
                    // Обмен
                    Student temp = arr[j];
                    arr[j] = arr[k];
                    arr[k] = temp;
                    swapped = true;
                }
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

    // Сортируем сначала тех, кто имеет доход < 2*MIN_WAGE, затем по убыванию балла
    // Используем простой алгоритм сортировки пузырьком
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j].isDeleted) continue;
            for (int k = j + 1; k < size; k++) {
                if (arr[k].isDeleted) continue;
                bool condition = false;
                if (arr[j].income < 2.0L * MIN_WAGE && arr[k].income >= 2.0L * MIN_WAGE) {
                    condition = false;
                }
                else if (arr[j].income >= 2.0L * MIN_WAGE && arr[k].income < 2.0L * MIN_WAGE) {
                    condition = true;
                }
                else {
                    if (arr[j].averageScore < arr[k].averageScore) {
                        condition = true;
                    }
                }
                if (condition) {
                    // Обмен
                    Student temp = arr[j];
                    arr[j] = arr[k];
                    arr[k] = temp;
                }
            }
        }
    }

    std::cout << "Сортировка для общежития выполнена (сначала доход < 2*MIN_WAGE, затем по убыванию балла).\n";
}

// Функция для сохранения студентов в бинарный файл
void saveToFile(const Student* students, int count, const char* filename) {
    std::ofstream file(filename, std::ios::binary | std::ios::trunc);
    if (!file) {
        std::cout << "Ошибка открытия файла для записи.\n";
        return;
    }

    for (int i = 0; i < count; ++i) {
        file.write(reinterpret_cast<const char*>(&students[i]), sizeof(Student));
    }

    file.close();
    std::cout << "Студенты успешно сохранены в файл.\n";
}

// Функция для загрузки студентов из бинарного файла
void loadFromFile(Student*& students, int& count, const char* filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cout << "Ошибка открытия файла для чтения.\n";
        return;
    }

    // Определение количества записей
    file.seekg(0, std::ios::end);
    std::streampos fileSize = file.tellg();
    file.seekg(0, std::ios::beg);
    int totalRecords = fileSize / sizeof(Student);

    if (totalRecords <= 0) {
        std::cout << "Файл пуст или содержит некорректные данные.\n";
        file.close();
        return;
    }

    // Выделение памяти для студентов
    Student* allStudents = new Student[totalRecords];
    file.read(reinterpret_cast<char*>(allStudents), fileSize);
    file.close();

    // Подсчёт активных записей
    int activeCount = 0;
    for (int i = 0; i < totalRecords; i++) {
        if (!allStudents[i].isDeleted) {
            activeCount++;
        }
    }

    // Создание массива только активных записей
    delete[] students;
    students = new Student[activeCount];
    int idx = 0;
    for (int i = 0; i < totalRecords; i++) {
        if (!allStudents[i].isDeleted) {
            students[idx++] = allStudents[i];
        }
    }
    count = activeCount;
    delete[] allStudents;

    std::cout << "Студенты успешно загружены из файла.\n";
}