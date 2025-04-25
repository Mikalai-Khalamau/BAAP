#include "header.h"

// Основная функция
int main() {
    Student* students = nullptr; // Динамический массив студентов
    int size = 0;                // Текущее количество студентов

    const char* filename = "students.txt"; // Используем бинарный файл

    int choice;
    do {
        std::cout << "\n========= МЕНЮ =========\n";
        std::cout << "1. Сформировать список студентов\n";
        std::cout << "2. Просмотреть содержимое списка\n";
        std::cout << "3. Дополнить список новыми студентами\n";
        std::cout << "4. Поиск по заданному значению и вывод результатов\n";
        std::cout << "5. Удалить студента\n";
        std::cout << "6. Изменить значения студента\n";
        std::cout << "7. Отсортировать по среднему баллу (по возрастанию)\n";
        std::cout << "8. Сортировать для общежития (доход < 2*MIN_WAGE, затем по убыванию балла)\n";
        std::cout << "9. Сохранить в файл\n";
        std::cout << "10. Загрузить из файла\n";
        std::cout << "0. Выход\n";
        std::cout << "Выберите пункт меню: ";
        std::cin >> choice;
        std::cin.ignore(); // Очистка буфера

        switch (choice) {
            case 1:
                // Если массив уже существовал, освободим память
                if (students) {
                    delete[] students;
                    students = nullptr;
                    size = 0;
                }
                students = formArray(size);
                std::cout << "Массив сформирован.\n";
                break;
            case 2:
                viewArray(students, size);
                break;
            case 3:
                if (!students) {
                    std::cout << "Сначала нужно сформировать массив.\n";
                } else {
                    students = addElements(students, size, filename);
                }
                break;
            case 4:
                if (!students) {
                    std::cout << "Массив не создан.\n";
                } else {
                    searchElements(students, size);
                }
                break;
            case 5:
                if (!students) {
                    std::cout << "Массив не создан.\n";
                } else {
                    students = deleteElement(students, size, filename);
                }
                break;
            case 6:
                if (!students) {
                    std::cout << "Массив не создан.\n";
                } else {
                    modifyElement(students, size, filename);
                }
                break;
            case 7:
                if (!students) {
                    std::cout << "Массив не создан.\n";
                } else {
                    sortArrayByAverage(students, size);
                }
                break;
            case 8:
                if (!students) {
                    std::cout << "Массив не создан.\n";
                } else {
                    sortDormList(students, size);
                }
                break;
            case 9:
                if (!students || size == 0) {
                    std::cout << "Массив пуст или не создан.\n";
                } else {
                    saveToFile(students, size, filename);
                }
                break;
            case 10:
                loadFromFile(students, size, filename);
                break;
            case 0:
                std::cout << "Выход из программы.\n";
                break;
            default:
                std::cout << "Неверный выбор. Повторите попытку.\n";
        }
    } while (choice != 0);

    // Освобождаем память, если была выделена
    if (students) {
        delete[] students;
        students = nullptr;
    }

    return 0;
}