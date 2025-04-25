// Task_1.cpp
#include "header.h"

int main() {
    TrainInfo* trains = nullptr;          
    int count = 0;                        
    bool exitProgram = false;             
    const char* filename = "trains.dat";  

    // Главный цикл программы
    while (!exitProgram) {
        displayMenu();                    
        int choice;                      
        std::cin >> choice;              
        std::cin.ignore();               

        // Обработка выбора пользователя
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
            saveToFile(trains, count, filename); 
            break;
        case 9:
            loadFromFile(trains, count, filename); 
            break;
        case 0:
            exitProgram = true;            
            break;
        default:
            std::cout << "Неверный выбор. Пожалуйста, попробуйте снова.\n"; 
        }
    }

    // Освобождение памяти, выделенной под массив поездов
    delete[] trains;
    std::cout << "Выход из программы. До свидания!\n"; 
    return 0; 
}