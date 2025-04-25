#include <stdio.h>
#include <stdlib.h>

// Максимальная длина строки ввода
#define MAX_INPUT_LENGTH 100

// Функция для удаления символа новой строки из строки
void removeNewline(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
    }
}

// Функция для проверки корректности ввода неотрицательного целого числа
int readNonNegativeLongLong(long long* number) {
    char input[MAX_INPUT_LENGTH];
    
    while (1) {
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("Ошибка чтения ввода. Пожалуйста, попробуйте снова.\n");
            continue;
        }
        
        removeNewline(input);
        
        // Преобразование строки в число
        long long value = 0;
        int i = 0;
        
        while (input[i] != '\0' && input[i] != '\n') {
            if (input[i] < '0' || input[i] > '9') {
                printf("Некорректный ввод. Пожалуйста, введите неотрицательное целое число.\n");
                break;
            }
            value = value * 10 + (input[i] - '0');
            i++;
        }
        
        if (input[i] == '\0' || input[i] == '\n') {
            *number = value;
            return 1;
        }
    }
}

// Функция для освобождения памяти
void myFree(void*** ptr, long long n1, long long n2) {
    for (long long i = 0; i < n1; i++) {
        for (long long j = 0; j < n2; j++) {
            if (ptr[i][j] != NULL) {
                free(ptr[i][j]);
            }
        }
        free(ptr[i]);
    }
    free(ptr);
}

// Функция для вычисления максимальной суммы диагоналей
long long calculateMaxDiagonalSum(long long*** array, long long n) {
    long long sum1 = 0; // (i, i, i)
    long long sum2 = 0; // (i, i, n-1-i)
    long long sum3 = 0; // (i, n-1-i, i)
    long long sum4 = 0; // (i, n-1-i, n-1-i)
    
    for (long long i = 0; i < n; i++) {
        sum1 += array[i][i][i];
        sum2 += array[i][i][n - 1 - i];
        sum3 += array[i][n - 1 - i][i];
        sum4 += array[i][n - 1 - i][n - 1 - i];
    }
    
    // Нахождение максимальной суммы
    long long maxSum = sum1;
    if (sum2 > maxSum) maxSum = sum2;
    if (sum3 > maxSum) maxSum = sum3;
    if (sum4 > maxSum) maxSum = sum4;

    return maxSum;
}

// Функция для запроса повторного выполнения
int askToRepeat() {
    char choice[10]; // Массив для хранения выбора
    
    while (1) {
        printf("Хотите выполнить ещё один расчёт? (y/n): ");
        fgets(choice, sizeof(choice), stdin); // Чтение строки

        // Проверка на корректность входа
        if ((choice[0] == 'y' || choice[0] == 'Y') && (choice[1] == '\n')) {
            printf("\n----------------------------------------\n\n");
            return 1; // Если введено 'y', продолжаем
        } else {
            printf("Завершение программы. До свидания!\n");
            return 0; // Завершение программы при любом другом вводе
        }
    }
}

int main() {
    while (1) {
        long long n;
        
        printf("Введите размер n для массива n^3: ");
        if (!readNonNegativeLongLong(&n) || n <= 0) {
            printf("Некорректный ввод. Пожалуйста, введите положительное целое число.\n");
            continue;
        }

        // Выделение памяти для 3D массива
        long long*** array = (long long***)malloc(n * sizeof(long long**));
        if (array == NULL) {
            printf("Ошибка выделения памяти.\n");
            return 1;
        }

        for (long long i = 0; i < n; i++) {
            array[i] = (long long**)malloc(n * sizeof(long long*));
            if (array[i] == NULL) {
                printf("Ошибка выделения памяти.\n");
                myFree((void***)array, i, n);
                return 1;
            }

            for (long long j = 0; j < n; j++) {
                array[i][j] = (long long*)malloc(n * sizeof(long long));
                if (array[i][j] == NULL) {
                    printf("Ошибка выделения памяти.\n");
                    myFree((void***)array, i + 1, n);
                    return 1;
                }
            }
        }
        
        // Ввод элементов массива
        printf("Введите %lld неотрицательных целых чисел для массива:\n", n * n * n);
        
        for (long long i = 0; i < n; i++) {
            for (long long j = 0; j < n; j++) {
                for (long long k = 0; k < n; k++) {
                    while (1) {
                        printf("Элемент [%lld][%lld][%lld]: ", i, j, k);
                        long long value;
                        if (readNonNegativeLongLong(&value)) {
                            array[i][j][k] = value;
                            break;
                        }
                    }
                }
            }
        }

        // Вычисление максимальной суммы диагоналей
        long long maxSum = calculateMaxDiagonalSum(array, n);
        
        printf("Наибольшая сумма диагонали: %lld\n", maxSum);
        
        // Освобождение памяти
        myFree((void***)array, n, n);
        
        // Проверка на выполнение ещё одного расчёта
        if (!askToRepeat()) {
            break; // Завершение программы при любом другом вводе
        }
    }

    return 0;
}