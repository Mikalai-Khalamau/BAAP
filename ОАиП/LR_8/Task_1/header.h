// header.h
#ifndef TRAIN_H
#define TRAIN_H

#include <iostream>
#include <fstream>
#include <cstring>
// Определите максимальную длину строк
const int DESTINATION_SIZE = 100;
const int TIME_SIZE = 10;

// Объединение для хранения дополнительной информации о поезде
union ExtraInfo {
    float ticket_price;      // Цена билета
    int reservation_code;    // Код резервирования
};

// Структура для хранения информации о поезде с фиксированными размерами строк
typedef struct {
    char destination[DESTINATION_SIZE];    // Пункт назначения
    char departure_time[TIME_SIZE];        // Время отправления
    int free_seats;                        // Количество свободных мест
    int train_number;                      // Номер поезда
    ExtraInfo extra_info;                  // Дополнительная информация (цена или код)
    bool has_ticket_price;                 // Флаг, указывающий, активен ли член union ticket_price
} TrainInfo;

// Объявления функций
void displayMenu();                           
void addTrains(TrainInfo*& trains, int& count); 
void viewTrains(const TrainInfo* trains, int count); 
void appendTrains(TrainInfo*& trains, int& count); 
void searchTrains(const TrainInfo* trains, int count); 
void deleteTrain(TrainInfo*& trains, int& count); 
void modifyTrain(TrainInfo* trains, int count); 
void sortTrains(TrainInfo* trains, int count); 
void saveToFile(const TrainInfo* trains, int count, const char* filename); 
void loadFromFile(TrainInfo*& trains, int& count, const char* filename); 
void correctRecordInFile(const char* filename, int index, const TrainInfo& train); 

#endif // TRAIN_H