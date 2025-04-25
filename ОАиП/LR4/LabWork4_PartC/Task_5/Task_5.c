#include <stdio.h>
#include <stdlib.h>

// Функция для отображения контекстного меню
void displayContextMenu() {
    printf("Лабораторная работа №4, задание №5\n");
    printf("Суть задания:\n");
    printf("На вход подаётся поле для игры в сапёр размером n*m символов, "
           "где символ '.' означает пустое место, а символ '*' - бомба. "
           "Требуется дополнить это поле числами, как в оригинальной игре.\n");
    printf("Выполнил студент группы 453503 Халамов Николай\n");
}

// Функция для проверки, находится ли позиция (x, y) внутри поля
int isValid(int x, int y, int n, int m) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

// Функция для проверки корректного ввода целого числа
int isInteger(int *number) {
    char c;
    if (scanf("%d%c", number, &c) != 2 || c != '\n') {
        while (getchar() != '\n'); // Очистка ввода
        return 0; // Ввод некорректен
    }
    return 1; // Ввод корректен
}

// Функция для ввода элемента поля
char readFieldElement(int i, int j) {
    char input[100]; // Буфер для ввода
    while (1) { // Бесконечный цикл до получения корректного ввода
        printf("Введите элемент для позиции (%d, %d): ", i, j);
        fgets(input, sizeof(input), stdin); // Читаем строку

        // Проверка, что введено только один символ и он допустим
        if (input[0] == '.' || input[0] == '*') {
            if (input[1] == '\n') {
                return input[0]; // Возврат корректного ввода
            } else {
                printf("Введите еще раз.\n");
            }
        } else {
            printf("Введите еще раз.\n");
        }
    }
}

int main() {
    while (1) { // Цикл для повторного запуска программы
        displayContextMenu();
        int n, m;

        // Ввод размеров поля
        printf("Введите количество строк (n): ");
        while (!isInteger(&n) || n <= 0) {
            printf("Введите еще раз.\n"); // Простое сообщение об ошибке
        }

        printf("Введите количество столбцов (m): ");
        while (!isInteger(&m) || m <= 0) {
            printf("Введите еще раз.\n"); // Простое сообщение об ошибке
        }

        // Динамическое выделение памяти для исходного поля
        char **field = (char **)malloc(n * sizeof(char *));
        for (int i = 0; i < n; ++i) {
            field[i] = (char *)malloc(m * sizeof(char));
        }

        // Ввод исходного поля
        printf("Введите поле (каждая позиция должна содержать один символ '.' или '*'):\n");
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                field[i][j] = readFieldElement(i, j);
            }
        }

        // Динамическое выделение памяти для результирующего поля
        char **result = (char **)malloc(n * sizeof(char *));
        for (int i = 0; i < n; ++i) {
            result[i] = (char *)malloc(m * sizeof(char));
        }

        // Направления для проверки соседних клеток (8 направлений)
        int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

        // Обработка поля
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (field[i][j] == '*') {
                    result[i][j] = '*';
                } else {
                    int bombCount = 0;
                    // Проверка всех соседних клеток
                    for (int k = 0; k < 8; ++k) {
                        int ni = i + dx[k];
                        int nj = j + dy[k];
                        if (isValid(ni, nj, n, m) && field[ni][nj] == '*') {
                            bombCount++;
                        }
                    }
                    // Преобразование числа в символ
                    result[i][j] = bombCount + '0';
                }
            }
        }

        // Вывод результирующего поля
        printf("\nРезультирующее поле:\n");
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                printf("%c ", result[i][j]); // Вывод без форматирования
            }
            printf("\n"); // Переход на новую строку
        }

        // Освобождение выделенной памяти
        for (int i = 0; i < n; ++i) {
            free(field[i]);
            free(result[i]);
        }
        free(field);
        free(result);

        // Проверка на выполнение ещё одного расчёта
        char choice;
        while (1) {
            printf("Хотите выполнить ещё один расчёт? (y/n): ");
            scanf(" %c", &choice); // Пробел перед %c для игнорирования пробелов

            if (choice == 'y' || choice == 'Y') {
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