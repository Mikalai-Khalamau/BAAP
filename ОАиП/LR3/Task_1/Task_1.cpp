#include <iostream>

// Функция отображения контекстного меню 
void ContextMenu() {
    std::cout << "Лабораторная работа №3, задание №1\n";
    std::cout << "Суть задания:\n";
    std::cout << "Вычисление суммы значений (a-b)^2, зависящих от четности i, для i от 1 до 30.\n";
    std::cout << "Выполнил студент группы 453503 Халамов Николай\n";
}

int main() {
    ContextMenu();

    int i = 1;
    int a;
    int b;
    int sum = 0;

    while (i <= 30) {
        if (i % 2 == 0) {
            a = i / 2;
            b = i * i * i;
        } else {
            a = i;
            b = i * i;
        }

        sum += (a - b) * (a - b);
        i++;
    }

    std::cout << "Сумма равна: " << sum << "\n";

    return 0;
}
