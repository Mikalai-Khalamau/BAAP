#include <iostream>
#include <iomanip>
#include <limits>

// Функция для очистки входного потока при ошибке ввода
void clearInputStream() {
    std::cin.clear(); // Сброс флагов ошибки
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Игнорирование некорректного ввода
}

// Функция для построения магического квадрата нечетного порядка (метод Сиамского метода)
void generateOddMagicSquare(long long n, long long** magicSquare) {
    long long num = 1;
    long long i = 0;
    long long j = n / 2;

    while (num <= n * n) {
        magicSquare[i][j] = num++;
        long long newi = (i == 0) ? n - 1 : i - 1;
        long long newj = (j + 1) % n;
        if (magicSquare[newi][newj] != 0) {
            i = (i + 1) % n;
        } else {
            i = newi;
            j = newj;
        }
    }
}

// Функция для построения магического квадрата двойно четного порядка (кратный 4)
void generateDoublyEvenMagicSquare(long long n, long long** magicSquare) {
    long long num = 1;
    // Заполнение квадрата по порядку
    for (long long i = 0; i < n; ++i) {
        for (long long j = 0; j < n; ++j) {
            magicSquare[i][j] = num++;
        }
    }

    // Замена определенных ячеек
    for (long long i = 0; i < n; ++i) {
        for (long long j = 0; j < n; ++j) {
            if ( (i % 4 == j % 4) || ((i + j) % 4 == 3) ) {
                magicSquare[i][j] = (n * n + 1) - magicSquare[i][j];
            }
        }
    }
}

// Функция для построения магического квадрата одиночно четного порядка (кратный 2, но не 4)
void generateSinglyEvenMagicSquare(long long n, long long** magicSquare) {
    long long halfN = n / 2;
    long long subSquareSize = halfN;
    long long subSquareArea = subSquareSize * subSquareSize;

    // Создание под-квадратов
    long long** subSquares = new long long*[4];
    for (long long i = 0; i < 4; ++i) {
        subSquares[i] = new long long*[subSquareSize];
        for (long long j = 0; j < subSquareSize; ++j) {
            subSquares[i][j] = new long long[subSquareSize];
            for (long long k = 0; k < subSquareSize; ++k) {
                subSquares[i][j][k] = 0;
            }
        }
    }

    // Заполнение каждого под-квадрата как магического квадрата нечетного порядка
    // Здесь можно использовать рекурсию или вызвать generateOddMagicSquare
    // Для упрощения будем использовать метод Сиамского метода вручную
    for (long long index = 0; index < 4; ++index) {
        long long num = 1;
        long long i = 0;
        long long j = subSquareSize / 2;

        while (num <= subSquareSize * subSquareSize) {
            subSquares[index][i][j] = num++;
            long long newi = (i == 0) ? subSquareSize - 1 : i - 1;
            long long newj = (j + 1) % subSquareSize;
            if (subSquares[index][newi][newj] != 0) {
                i = (i + 1) % subSquareSize;
            } else {
                i = newi;
                j = newj;
            }
        }
    }

    // Объединение под-квадратов в основной квадрат с корректировкой номеров
    for (long long quadrant = 0; quadrant < 4; ++quadrant) {
        long long add = quadrant * subSquareArea;
        for (long long i = 0; i < subSquareSize; ++i) {
            for (long long j = 0; j < subSquareSize; ++j) {
                magicSquare[i + (quadrant < 2 ? 0 : subSquareSize)][j + (quadrant % 2 == 0 ? 0 : subSquareSize)] = subSquares[quadrant][i][j] + add;
            }
        }
    }

    // Определение количества столбцов для обмена
    long long k = (n - 2) / 4;

    // Обмен ячеек
    for (long long i = 0; i < subSquareSize; ++i) {
        for (long long j = 0; j < n; ++j) {
            if (j < k || j >= n - k || (j == k && i == k)) {
                // Обмен между квадрантами
                std::swap(magicSquare[i][j], magicSquare[i + subSquareSize][j]);
            }
        }
    }

    // Очистка памяти под-квадратов
    for (long long i = 0; i < 4; ++i) {
        for (long long j = 0; j < subSquareSize; ++j) {
            delete[] subSquares[i][j];
        }
        delete[] subSquares[i];
    }
    delete[] subSquares;
}

int main() {
    long long n;

    while (true) {
        std::cout << "Введите порядок магического квадрата (целое число >=1, не равно 2, максимум 4294967295): ";
        std::cin >> n;

        if (std::cin.fail() || n < 1 || n == 2) {
            std::cout << "Некорректный ввод. Порядок должен быть целым числом >=1 и не равным 2.\n";
            clearInputStream();
            continue;
        }

        // Проверка на максимально допустимый размер (2^32 -1)
        // Так как n - порядок, и для n=4294967295 размер квадрата будет огромным,
        // на практике мы ограничимся гораздо меньшими значениями из-за ограничений памяти.
        // Однако, согласно условию, мы не накладываем дополнительных ограничений.

        break;
    }

    // Динамическое выделение памяти для магического квадрата
    long long** magicSquare = new long long*[n];
    for (long long i = 0; i < n; ++i) {
        magicSquare[i] = new long long[n];
        for (long long j = 0; j < n; ++j) {
            magicSquare[i][j] = 0;
        }
    }

    // Построение магического квадрата в зависимости от порядка
    if (n == 1) {
        magicSquare[0][0] = 1;
    }
    else if (n % 2 == 1) {
        generateOddMagicSquare(n, magicSquare);
    }
    else if (n % 4 == 0) {
        generateDoublyEvenMagicSquare(n, magicSquare);
    }
    else {
        generateSinglyEvenMagicSquare(n, magicSquare);
    }

    // Вывод магического квадрата
    std::cout << "\nМагический квадрат порядка " << n << ":\n";
    for (long long i = 0; i < n; ++i) {
        for (long long j = 0; j < n; ++j) {
            std::cout << std::setw(6) << magicSquare[i][j] << " ";
        }
        std::cout << "\n";
    }

    // Очистка выделенной памяти
    for (long long i = 0; i < n; ++i) {
        delete[] magicSquare[i];
    }
    delete[] magicSquare;

    return 0;
}