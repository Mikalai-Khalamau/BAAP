#include "header.h"

// Функция для отображения меню выбора
void displayMenu() {
    std::cout << "\n--- Меню выбора функций для управления поездами ---\n";
    std::cout << "1. Сформировать список поездов\n";
    std::cout << "2. Просмотреть поезда\n";
    std::cout << "3. Добавить поезда в список\n";
    std::cout << "4. Найти поезда по пункту назначения\n";
    std::cout << "5. Удалить поезд из списка\n";
    std::cout << "6. Изменить значения для поезда\n";
    std::cout << "7. Сортировать поезда по количеству свободных мест (Убывание)\n";
    std::cout << "8. Сохранить поезда в двоичный файл\n";
    std::cout << "9. Загрузить поезда из двоичного файла\n";
    std::cout << "0. Выход из программы\n";
    std::cout << "Введите ваш выбор (цифра от 0 до 9): ";
}

// Функция для добавления поездов
void addTrains(TrainInfo*& trains, int& count) {
    std::cout << "\nДобавление поездов...\n";
    int choice;
    int newCount = 0;
    std::cout << "Выберите способ ввода:\n";
    std::cout << "1. Ввести предопределенное количество поездов\n";
    std::cout << "2. Вводить до появления поезда с заданным пунктом назначения\n";
    std::cout << "3. Вводить поезда с подсказкой пользователю\n";
    std::cout << "Введите ваш выбор: ";
    std::cin >> choice;
    std::cin.ignore();

    switch (choice) {
    case 1: {
        int num;
        std::cout << "Введите количество поездов для добавления: ";
        std::cin >> num;
        std::cin.ignore();

        trains = new TrainInfo[num];
        count = num;

        for (int i = 0; i < num; ++i) {
            std::cout << "\nПоезд " << i + 1 << ":\n";
            std::cout << "Введите пункт назначения: ";
            std::cin.getline(trains[i].destination, DESTINATION_SIZE);
            std::cout << "Введите время отправления (ЧЧ:ММ): ";
            std::cin.getline(trains[i].departure_time, TIME_SIZE);
            std::cout << "Введите количество свободных мест: ";
            std::cin >> trains[i].free_seats;
            std::cout << "Введите номер поезда: ";
            std::cin >> trains[i].train_number;
            std::cin.ignore();
            std::cout << "Есть ли у этого поезда цена билета? (y/n): ";
            char opt;
            std::cin >> opt;
            std::cin.ignore();
            if (opt == 'y' || opt == 'Y') {
                std::cout << "Введите цену билета: ";
                std::cin >> trains[i].extra_info.ticket_price;
                trains[i].has_ticket_price = true;
            } else {
                std::cout << "Введите код резервирования: ";
                std::cin >> trains[i].extra_info.reservation_code;
                trains[i].has_ticket_price = false;
            }
            std::cin.ignore();
        }
        break;
    }
    case 2: {
    char stopDestination[DESTINATION_SIZE];
    std::cout << "Введите пункт назначения для завершения ввода: ";
    std::cin.getline(stopDestination, DESTINATION_SIZE);

    TrainInfo tempTrain;
    while (true) {
        std::cout << "\nПоезд " << newCount + 1 << ":\n";
        std::cout << "Введите пункт назначения: ";
        std::cin.getline(tempTrain.destination, DESTINATION_SIZE);
        if (std::string(tempTrain.destination) == stopDestination) {
            break;
        }
        std::cout << "Введите время отправления (ЧЧ:ММ): ";
        std::cin.getline(tempTrain.departure_time, TIME_SIZE);
        std::cout << "Введите количество свободных мест: ";
        std::cin >> tempTrain.free_seats;
        std::cout << "Введите номер поезда: ";
        std::cin >> tempTrain.train_number;
        std::cin.ignore();
        std::cout << "Есть ли у этого поезда цена билета? (y/n): ";
        char opt;
        std::cin >> opt;
        std::cin.ignore();
        if (opt == 'y' || opt == 'Y') {
            std::cout << "Введите цену билета: ";
            std::cin >> tempTrain.extra_info.ticket_price;
            tempTrain.has_ticket_price = true;
        } else {
            std::cout << "Введите код резервирования: ";
            std::cin >> tempTrain.extra_info.reservation_code;
            tempTrain.has_ticket_price = false;
        }
        std::cin.ignore();

        // Добавление tempTrain в массив trains
        TrainInfo* tempArray = new TrainInfo[newCount + 1];
        for (int i = 0; i < newCount; ++i) {
            tempArray[i] = trains[i];
        }
        tempArray[newCount] = tempTrain;
        delete[] trains;
        trains = tempArray;
        ++newCount;
    }
    count = newCount;
    break;
}
    case 3: {
        char cont = 'y';
        while (cont == 'y' || cont == 'Y') {
            TrainInfo tempTrain;
            std::cout << "\nПоезд " << newCount + 1 << ":\n";
            std::cout << "Введите пункт назначения: ";
            std::cin.getline(tempTrain.destination, DESTINATION_SIZE);
            std::cout << "Введите время отправления (ЧЧ:ММ): ";
            std::cin.getline(tempTrain.departure_time, TIME_SIZE);
            std::cout << "Введите количество свободных мест: ";
            std::cin >> tempTrain.free_seats;
            std::cout << "Введите номер поезда: ";
            std::cin >> tempTrain.train_number;
            std::cin.ignore();
            std::cout << "Есть ли у этого поезда цена билета? (y/n): ";
            char opt;
            std::cin >> opt;
            std::cin.ignore();
            if (opt == 'y' || opt == 'Y') {
                std::cout << "Введите цену билета: ";
                std::cin >> tempTrain.extra_info.ticket_price;
                tempTrain.has_ticket_price = true;
            } else {
                std::cout << "Введите код резервирования: ";
                std::cin >> tempTrain.extra_info.reservation_code;
                tempTrain.has_ticket_price = false;
            }
            std::cin.ignore();

            // Добавление tempTrain в массив trains
            TrainInfo* tempArray = new TrainInfo[newCount + 1];
            for (int i = 0; i < newCount; ++i) {
                tempArray[i] = trains[i];
            }
            tempArray[newCount] = tempTrain;
            delete[] trains;
            trains = tempArray;
            ++newCount;

            std::cout << "Хотите добавить еще один поезд? (y/n): ";
            std::cin >> cont;
            std::cin.ignore();
        }
        count = newCount;
        break;
    }
    default:
        std::cout << "Неверный выбор.\n";
    }

    std::cout << "Поезд(а) успешно добавлены.\n";
}

// Функция для просмотра поездов
void viewTrains(const TrainInfo* trains, int count) {
    std::cout << "\nОтображение поездов...\n";
    for (int i = 0; i < count; ++i) {
        std::cout << "\nПоезд " << i + 1 << ":\n";
        std::cout << "Пункт назначения: " << trains[i].destination << '\n';
        std::cout << "Время отправления: " << trains[i].departure_time << '\n';
        std::cout << "Свободные места: " << trains[i].free_seats << '\n';
        std::cout << "Номер поезда: " << trains[i].train_number << '\n';
        if (trains[i].has_ticket_price) {
            std::cout << "Цена билета: BYN" << trains[i].extra_info.ticket_price << '\n';
        } else {
            std::cout << "Код резервирования: " << trains[i].extra_info.reservation_code << '\n';
        }
    }
}

// Функция для добавления поездов
void appendTrains(TrainInfo*& trains, int& count) {
    std::cout << "\nДобавление поездов...\n";
    int num;
    std::cout << "Введите количество поездов для добавления: ";
    std::cin >> num;
    std::cin.ignore();

    TrainInfo* tempArray = new TrainInfo[count + num];
    for (int i = 0; i < count; ++i) {
        tempArray[i] = trains[i];
    }

    for (int i = 0; i < num; ++i) {
        std::cout << "\nПоезд " << count + i + 1 << ":\n";
        std::cout << "Введите пункт назначения: ";
        std::cin.getline(tempArray[count + i].destination, DESTINATION_SIZE);
        std::cout << "Введите время отправления (ЧЧ:ММ): ";
        std::cin.getline(tempArray[count + i].departure_time, TIME_SIZE);
        std::cout << "Введите количество свободных мест: ";
        std::cin >> tempArray[count + i].free_seats;
        std::cout << "Введите номер поезда: ";
        std::cin >> tempArray[count + i].train_number;
        std::cin.ignore();
        std::cout << "Есть ли у этого поезда цена билета? (y/n): ";
        char opt;
        std::cin >> opt;
        std::cin.ignore();
        if (opt == 'y' || opt == 'Y') {
            std::cout << "Введите цену билета: ";
            std::cin >> tempArray[count + i].extra_info.ticket_price;
            tempArray[count + i].has_ticket_price = true;
        } else {
            std::cout << "Введите код резервирования: ";
            std::cin >> tempArray[count + i].extra_info.reservation_code;
            tempArray[count + i].has_ticket_price = false;
        }
        std::cin.ignore();
    }

    delete[] trains;
    trains = tempArray;
    count += num;

    std::cout << "Поезд(а) успешно добавлены.\n";
}

// Функция для поиска поездов по пункту назначения
void searchTrains(const TrainInfo* trains, int count) {
    std::cout << "\nПоиск поездов...\n";
    char searchDestination[DESTINATION_SIZE];
    std::cout << "Введите пункт назначения для поиска: ";
    std::cin.getline(searchDestination, DESTINATION_SIZE);

    bool found = false;
    for (int i = 0; i < count; ++i) {
        if (std::string(trains[i].destination) == searchDestination) {
            if (!found) {
                std::cout << "\nНайденные поезда:\n";
            }
            found = true;
            std::cout << "\nПоезд " << i + 1 << ":\n";
            std::cout << "Пункт назначения: " << trains[i].destination << '\n';
            std::cout << "Время отправления: " << trains[i].departure_time << '\n';
            std::cout << "Свободные места: " << trains[i].free_seats << '\n';
            std::cout << "Номер поезда: " << trains[i].train_number << '\n';
            if (trains[i].has_ticket_price) {
                std::cout << "Цена билета: BYN" << trains[i].extra_info.ticket_price << '\n';
            } else {
                std::cout << "Код резервирования: " << trains[i].extra_info.reservation_code << '\n';
            }
        }
    }
    if (!found) {
        std::cout << "Поезда с пунктом назначения " << searchDestination << " не найдены.\n";
    }
}

// Функция для удаления поезда по номеру
void deleteTrain(TrainInfo*& trains, int& count) {
    std::cout << "\nУдаление поезда...\n";
    int trainNumber;
    std::cout << "Введите номер поезда для удаления: ";
    std::cin >> trainNumber;
    std::cin.ignore();

    bool found = false;
    for (int i = 0; i < count; ++i) {
        if (trains[i].train_number == trainNumber) {
            found = true;
            for (int j = i; j < count - 1; ++j) {
                trains[j] = trains[j + 1];
            }
            --count;
            std::cout << "Поезд номер " << trainNumber << " успешно удален.\n";
            break;
        }
    }
    if (!found) {
        std::cout << "Поезд номер " << trainNumber << " не найден.\n";
    }
}

void correctRecordInFile(const char* filename, int index, const TrainInfo& train) {
    // Открытие файла для чтения и записи в бинарном формате
    std::fstream file(filename, std::ios::binary | std::ios::in | std::ios::out);
    if (!file) {
        // Проверка на успешное открытие файла
        std::cout << "Ошибка открытия файла для обновления.\n";
        return;
    }

    // Чтение количества записей в файле
    int count;
    file.read((char*)&count, sizeof(count));
    
    // Проверка корректности индекса записи
    if (index < 0 || index >= count) {
        std::cout << "Неверный индекс записи.\n";
        file.close(); // Закрытие файла перед выходом
        return;
    }

    // Вычисление смещения для нужной записи
    std::streampos pos = sizeof(count); // Начинаем с размера заголовка (количества записей)
    const std::streamsize recordSize = DESTINATION_SIZE + TIME_SIZE + sizeof(int) + sizeof(int) + sizeof(bool) + sizeof(float); 

    // Увеличиваем смещение на размер всех предыдущих записей
    pos += index * recordSize;

    // Установка указателя записи на нужную позицию
    file.seekp(pos, std::ios::beg);
    if (!file) {
        // Проверка на успешное перемещение указателя
        std::cout << "Ошибка установки позиции записи.\n";
        file.close(); // Закрытие файла перед выходом
        return;
    }

    // Подготовка записи для записи в файл
    TrainInfo temp = train; // Копируем данные о поезде

    // Создание буфера для пункта назначения
    char destinationBuffer[DESTINATION_SIZE] = {0};
    strncpy(destinationBuffer, temp.destination, DESTINATION_SIZE - 1); // Копируем строку с ограничением

    // Создание буфера для времени отправления
    char departureTimeBuffer[TIME_SIZE] = {0};
    strncpy(departureTimeBuffer, temp.departure_time, TIME_SIZE - 1); // Копируем строку с ограничением

    // Запись данных о пункте назначения в файл
    file.write(destinationBuffer, DESTINATION_SIZE);
    
    // Запись данных о времени отправления в файл
    file.write(departureTimeBuffer, TIME_SIZE);
    
    // Запись остальных полей структуры TrainInfo
    file.write((char*)&temp.free_seats, sizeof(temp.free_seats)); // Число свободных мест
    file.write((char*)&temp.train_number, sizeof(temp.train_number)); // Номер поезда
    file.write((char*)&temp.has_ticket_price, sizeof(temp.has_ticket_price)); // Наличие цены на билет
    
    // Условная запись дополнительной информации
    if (temp.has_ticket_price) {
        // Если цена на билет существует, записываем ее
        file.write((char*)&temp.extra_info.ticket_price, sizeof(temp.extra_info.ticket_price));
    } else {
        // Если цены нет, записываем код резервирования
        file.write((char*)&temp.extra_info.reservation_code, sizeof(temp.extra_info.reservation_code));
    }

    // Закрытие файла после завершения записи
    file.close();
    std::cout << "Запись успешно обновлена в файле.\n"; // Сообщение об успешном обновлении
}

void modifyTrain(TrainInfo* trains, int count) {
    std::cout << "\nИзменение поезда...\n";
    int trainNumber;
    std::cout << "Введите номер поезда для изменения: ";
    std::cin >> trainNumber;
    std::cin.ignore();

    bool found = false;
    int index = -1;
    for (int i = 0; i < count; ++i) {
        if (trains[i].train_number == trainNumber) {
            found = true;
            index = i;
            std::cout << "\nВведите новые данные для поезда номер " << trainNumber << ":\n";
            std::cout << "Введите пункт назначения: ";
            std::cin.getline(trains[i].destination, DESTINATION_SIZE);
            std::cout << "Введите время отправления (ЧЧ:ММ): ";
            std::cin.getline(trains[i].departure_time, TIME_SIZE);
            std::cout << "Введите количество свободных мест: ";
            std::cin >> trains[i].free_seats;
            std::cin.ignore();
            std::cout << "Есть ли у этого поезда цена билета? (y/n): ";
            char opt;
            std::cin >> opt;
            std::cin.ignore();
            if (opt == 'y' || opt == 'Y') {
                std::cout << "Введите цену билета: ";
                std::cin >> trains[i].extra_info.ticket_price;
                trains[i].has_ticket_price = true;
            } else {
                std::cout << "Введите код резервирования: ";
                std::cin >> trains[i].extra_info.reservation_code;
                trains[i].has_ticket_price = false;
            }
            std::cin.ignore();
            std::cout << "Поезд номер " << trainNumber << " успешно изменен в памяти.\n";

            // Обновление записи в файле
            const char* filename = "trains.dat"; 
            correctRecordInFile(filename, index, trains[i]);

            break;
        }
    }
    if (!found) {
        std::cout << "Поезд номер " << trainNumber << " не найден.\n";
    }
}

// Функция для сортировки поездов по свободным местам (по убыванию)
void sortTrains(TrainInfo* trains, int count) {
    std::cout << "\nСортировка поездов по свободным местам (по убыванию)...\n";

    for (int i = 1; i < count; ++i) {
        TrainInfo key = trains[i];
        int j = i - 1;
        while (j >= 0 && trains[j].free_seats < key.free_seats) {
            trains[j + 1] = trains[j];
            j = j - 1;
        }
        trains[j + 1] = key;
    }
    std::cout << "Поезда успешно отсортированы.\n";
}

// Функция для сохранения поездов в бинарный файл с фиксированными размерами записей
void saveToFile(const TrainInfo* trains, int count, const char* filename) {
    std::ofstream file(filename, std::ios::binary);
    if (!file) {
        std::cout << "Ошибка открытия файла для сохранения.\n";
        return;
    }

    // Запись количества поездов
    file.write((char*)&count, sizeof(count));

    // Запись каждой записи о поезде
    for (int i = 0; i < count; ++i) {
        char destinationBuffer[DESTINATION_SIZE] = {0};
        strncpy(destinationBuffer, trains[i].destination, DESTINATION_SIZE - 1);
        
        char departureTimeBuffer[TIME_SIZE] = {0};
        strncpy(departureTimeBuffer, trains[i].departure_time, TIME_SIZE - 1);
        
        file.write(destinationBuffer, DESTINATION_SIZE);
        file.write(departureTimeBuffer, TIME_SIZE);
        file.write((char*)&trains[i].free_seats, sizeof(trains[i].free_seats));
        file.write((char*)&trains[i].train_number, sizeof(trains[i].train_number));
        file.write((char*)&trains[i].has_ticket_price, sizeof(trains[i].has_ticket_price));
        
        if (trains[i].has_ticket_price) {
            file.write((char*)&trains[i].extra_info.ticket_price, sizeof(trains[i].extra_info.ticket_price));
        } else {
            file.write((char*)&trains[i].extra_info.reservation_code, sizeof(trains[i].extra_info.reservation_code));
        }
    }

    file.close();
    std::cout << "Данные успешно сохранены в файл " << filename << ".\n";
}

// Функция для загрузки поездов из бинарного файла
void loadFromFile(TrainInfo*& trains, int& count, const char* filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cout << "Ошибка открытия файла для загрузки.\n";
        return;
    }

    // Чтение количества поездов
    file.read((char*)&count, sizeof(count));
    trains = new TrainInfo[count];

    // Чтение записей о поездах
    for (int i = 0; i < count; ++i) {
        char destinationBuffer[DESTINATION_SIZE] = {0};
        char departureTimeBuffer[TIME_SIZE] = {0};

        file.read(destinationBuffer, DESTINATION_SIZE);
        file.read(departureTimeBuffer, TIME_SIZE);
        file.read((char*)&trains[i].free_seats, sizeof(trains[i].free_seats));
        file.read((char*)&trains[i].train_number, sizeof(trains[i].train_number));
        file.read((char*)&trains[i].has_ticket_price, sizeof(trains[i].has_ticket_price));

        strncpy(trains[i].destination, destinationBuffer, DESTINATION_SIZE - 1);
        strncpy(trains[i].departure_time, departureTimeBuffer, TIME_SIZE - 1);

        if (trains[i].has_ticket_price) {
            file.read((char*)&trains[i].extra_info.ticket_price, sizeof(trains[i].extra_info.ticket_price));
        } else {
            file.read((char*)&trains[i].extra_info.reservation_code, sizeof(trains[i].extra_info.reservation_code));
        }
    }

    file.close();
    std::cout << "Данные успешно загружены из файла " << filename << ".\n";
}

// Главная функция
int main() {
    TrainInfo* trains = nullptr;
    int count = 0;
    int choice;

    do {
        displayMenu();
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1:
                addTrains(trains, count);
                break;
            case 2:
                viewTrains(trains, count);
                break;
            case 3:
                appendTrains(trains, count);
                break;
            case 4:
                searchTrains(trains, count);
                break;
            case 5:
                deleteTrain(trains, count);
                break;
            case 6:
                modifyTrain(trains, count);
                break;
            case 7:
                sortTrains(trains, count);
                break;
            case 8:
                saveToFile(trains, count, "trains.dat");
                break;
            case 9:
                loadFromFile(trains, count, "trains.dat");
                break;
            case 0:
                std::cout << "Выход из программы.\n";
                break;
            default:
                std::cout << "Неверный выбор. Пожалуйста, попробуйте снова.\n";
        }
    } while (choice != 0);

    delete[] trains; // Освобождение памяти
    return 0;
}