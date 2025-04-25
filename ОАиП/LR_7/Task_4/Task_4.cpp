#include <iostream>

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

// Функция для вычитания двух чисел без использования операции вычитания
int subtract(int x, int y) {
    // Пока есть заем
    while (y != 0) {
        // Находим позиции, где у x нет бита, а у y есть (нужно занимать)
        int borrow = (~x) & y;
        // Вычисляем разницу без учета займа
        x = x ^ y;
        // Переносим заем на следующий разряд
        y = borrow << 1;
    }
    return x;
}

// Функция для проверки делимости числа N на простое P
bool isDivisible(long long N, int P) {
    int result = 0; // Инициализируем остаток

    // Обрабатываем каждый бит числа N начиная с самого старшего бита
    for (int i = 127; i >= 0; --i) {
        // Сдвигаем остаток влево на 1 бит (умножаем на 2)
        result = result << 1;

        // Если текущий бит в числе N установлен, добавляем 1 к результату
        if ((N >> i) & 1) {
            result = result + 1;
        }

        // Если результат больше или равен P, вычитаем P без использования операции вычитания
        if (result >= P) {
            result = subtract(result, P);
        }
    }

    // Если остаток равен 0, то число N делится нацело на P
    return (result == 0);
}

void input(long long& n) {
    std::cout << "Введите целое положительное число N:\n";
    while (true) {
        if (isLongLong(n) && n > 0) {
            break;
        }
        else {
            std::cout << "Неверный ввод,попробуйте еще раз\n";
        }
    }
    }

int main() {

    long long N;
    input(N);

    // Проверяем делимость на 3
    if (isDivisible(N, 3)) {
        std::cout << N << " делится на 3" << '\n';
    } else {
        std::cout << N << " не делится на 3" << '\n';
    }

    // Проверяем делимость на 23
    if (isDivisible(N, 23)) {
        std::cout << N << " делится на 23" << '\n';
    } else {
        std::cout << N << " не делится на 23" << '\n';
    }

    // Проверяем делимость на 107
    if (isDivisible(N, 107)) {
        std::cout << N << " делится на 107" << '\n';
    } else {
        std::cout << N << " не делится на 107" << '\n';
    }

    return 0;
}