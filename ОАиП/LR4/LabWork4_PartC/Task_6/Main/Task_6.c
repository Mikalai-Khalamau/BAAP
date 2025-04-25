#include <stdio.h>
#include <stdlib.h>
#include "prot.h"

// Функция для проверки корректного ввода целого положительного числа
int isPositiveInteger(long long *number) {
char buffer[100];
if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
return 0; // Ошибка при чтении
}

char *endptr;
*number = strtoll(buffer, &endptr, 10); // Преобразование строки в число

// Проверка, является ли строка целым положительным числом
if (*endptr != '\n' && *endptr != '\0') {
return 0; // Не число
}

// Проверка на положительность
if (*number <= 0) {
return 0; // Не положительное
}

return 1; // Успех
}

// Функция для отображения контекстного меню
void displayContextMenu() {
    printf("Лабораторная работа №4, задание №6\n");
    printf("Суть задания:\n");
    printf("Построить магический квадрат. Порядок квадрата задаётся пользователем.\n");
    printf("Выполнил студент группы 453503 Халамов Николай\n");
}

// Функция для подсчета количества цифр
int numDigits(long long n) {
    if (n == 0) return 1;
    int count = 0;
    while (n != 0) {
        n /= 10;
        count++;
    }
    return count;
}

// Функция для вывода магического квадрата без пробелов в начале строк
// и ровно один пробел между числами
void printSquare(long long n, unsigned long long **square) {
    if (square == NULL) {
        printf("NO\n");
        return;
    }

    // Найти максимальное число для определения ширины вывода
    unsigned long long maxNumber = n * n;
    int width = numDigits(maxNumber);

    for (long long i = 0; i < n; ++i) {
        for (long long j = 0; j < n; ++j) {
            if (j > 0) {
                printf(" "); // Один пробел между числами
            }
            printf("%llu", square[i][j]);
        }
        printf("\n");
    }

    // Опционально: вывод магической константы
    // unsigned long long magicConstant = ((unsigned long long)n * (n * n + 1)) / 2;
    // printf("Magic constant: %llu\n", magicConstant);
}

// Метод Сиамского квадрата для нечетного порядка
unsigned long long **siameseMethod(long long n) {
    unsigned long long **square = (unsigned long long**)malloc(n * sizeof(unsigned long long *));
    if (square == NULL) {
        perror("Не удалось выделить память для магического квадрата");
        exit(EXIT_FAILURE);
    }
    for (long long i = 0; i < n; ++i) {
        square[i] = (unsigned long long*)calloc(n, sizeof(unsigned long long));
        if (square[i] == NULL) {
            perror("Не удалось выделить память для магического квадрата");
            for (long long j = 0; j < i; j++) {
                free(square[j]);
            }
            free(square);
            exit(EXIT_FAILURE);
        }
    }

    unsigned long long num = 1;
    long long i = 0;
    long long j = n / 2;

    while (num <= (unsigned long long)(n * n)) {
        square[i][j] = num++;
        long long newi = (i == 0) ? n - 1 : i - 1;
        long long newj = (j == n - 1) ? 0 : j + 1;
        if (square[newi][newj]) {
            i = (i + 1) % n;
        } else {
            i = newi;
            j = newj;
        }
    }

    return square;
}

// Метод для двукратного четного порядка (кратен 4)
unsigned long long **doublyEvenMagicSquare(int n) {
    if (n < 4 || n % 4 != 0) return NULL;

    unsigned long long **square = (unsigned long long**)malloc(n * sizeof(unsigned long long*));
    if (square == NULL) {
        perror("Не удалось выделить память для магического квадрата");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < n; i++) {
        square[i] = (unsigned long long*)malloc(n * sizeof(unsigned long long));
        if (square[i] == NULL) {
            perror("Не удалось выделить память для магического квадрата");
            for (int j = 0; j < i; j++) {
                free(square[j]);
            }
            free(square);
            exit(EXIT_FAILURE);
        }
    }

    // Заполнение квадрата числами от 1 до n^2
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            square[i][j] = i * n + j + 1;
        }
    }

    // Замена чисел по стандартному условию
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i % 4 == j % 4) || ((i + j) % 4 == 3)) {
                square[i][j] = (unsigned long long)(n * n + 1) - square[i][j];
            }
        }
    }

    return square;
}

// Метод для однократного четного порядка (кратен 2, но не 4)
unsigned long long **singlyEvenMethod(long long n) {
    if (n < 6 || n % 2 != 0 || n % 4 == 0) {
        return NULL; // Некорректный порядок для этого метода
    }

    long long halfN = n / 2;
    unsigned long long subSquareSize = halfN * halfN;

    // Создаем подрешетку с помощью метода Сиамского квадрата
    unsigned long long **subSquare = siameseMethod(halfN);
    if (!subSquare) {
        return NULL;
    }

    // Инициализация множителей для каждой подрешетки
    unsigned long long gridFactors[] = {0, 2, 3, 1};

    // Выделение памяти для основного квадрата
    unsigned long long **square = (unsigned long long**)malloc(n * sizeof(unsigned long long *));
    if (square == NULL) {
        perror("Не удалось выделить память для магического квадрата");
        // Освобождаем память подрешетки перед выходом
        for (long long i = 0; i < halfN; ++i) {
            free(subSquare[i]);
        }
        free(subSquare);
        exit(EXIT_FAILURE);
    }
    for (long long i = 0; i < n; i++) {
        square[i] = (unsigned long long*)malloc(n * sizeof(unsigned long long));
        if (square[i] == NULL) {
            perror("Не удалось выделить память для магического квадрата");
            // Освобождаем уже выделенную память перед выходом
            for (long long j = 0; j < i; j++) {
                free(square[j]);
            }
            free(square);
            // Освобождаем память подрешетки
            for (long long j = 0; j < halfN; j++) {
                free(subSquare[j]);
            }
            free(subSquare);
            exit(EXIT_FAILURE);
        }
    }

    // Заполнение основного квадрата с учетом множителей
    for (long long r = 0; r < n; r++) {
        for (long long c = 0; c < n; c++) {
            int grid = (r / halfN) * 2 + (c / halfN);
            square[r][c] = subSquare[r % halfN][c % halfN] + gridFactors[grid] * subSquareSize;
        }
    }

    long long nColsLeft = halfN / 2;
    long long nColsRight = nColsLeft - 1;

    // Обмен колонок между подрешетками A и C
    for (long long r = 0; r < halfN; r++) {
        for (long long c = 0; c < n; c++) {
            if (c < nColsLeft || c >= n - nColsRight || (c == nColsLeft && r == nColsLeft)) {
                if (c == 0 && r == nColsLeft)
                    continue;

                unsigned long long tmp = square[r][c];
                square[r][c] = square[r + halfN][c];
                square[r + halfN][c] = tmp;
            }
        }
    }

    // Освобождение памяти подрешетки
    for(long long i = 0; i < halfN; i++) {
        free(subSquare[i]);
    }
    free(subSquare);

    return square;
}

int main() {
    while (1)
    {

    
    long long n;

    displayContextMenu();
    printf("Введите порядок магического квадрата (n): ");
    while (!isPositiveInteger(&n)) {
        printf("Ошибка ввода! Пожалуйста, введите положительное целое число.\n");
        printf("Введите порядок магического квадрата (n): ");
    }

    // Проверка на существование магического квадрата
    if (n == 2) {
        printf("NO\n");
        return 0;
    }

    unsigned long long** magicSquare = NULL;

    // Создание магического квадрата в зависимости от порядка
    if (n == 1) {
        magicSquare = (unsigned long long**)malloc(sizeof(unsigned long long *));
        if (magicSquare == NULL) {
            perror("Не удалось выделить память для магического квадрата");
            exit(EXIT_FAILURE);
        }
        magicSquare[0] = (unsigned long long *)malloc(sizeof(unsigned long long));
        if (magicSquare[0] == NULL) {
            perror("Не удалось выделить память для магического квадрата");
            free(magicSquare);
            exit(EXIT_FAILURE);
        }
        magicSquare[0][0] = 1;
    } else if (n % 2 != 0) {
        magicSquare = siameseMethod(n);
    } else if (n % 4 == 0) {
        magicSquare = doublyEvenMagicSquare(n);
    } else {
        magicSquare = singlyEvenMethod(n); // Для однократных четных порядков
    }

    // Вывод магического квадрата
    printSquare(n, magicSquare);

    // Освобождение памяти
    if (magicSquare != NULL) {
        for (long long i = 0; i < n; ++i) {
            free(magicSquare[i]);
        }
        free(magicSquare);
    }
// Запрос на повторное выполнение
char choice[10]; // Массив для хранения выбора
while (1) {
printf("Хотите выполнить ещё один расчёт? (y/n): ");
fgets(choice, sizeof(choice), stdin); // Чтение строки

// Проверка на корректность ввода
if ((choice[0] == 'y' || choice[0] == 'Y') && (choice[1] == '\n')) {
printf("\n----------------------------------------\n\n");
break; // Если введено 'y', продолжаем
} else {
printf("Завершение программы. До свидания!\n");
return 0; // Завершение программы при любом другом вводе
}
}
    }
    return 0;
}