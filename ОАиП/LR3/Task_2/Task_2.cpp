#include <iostream>
//hcvsmhc
void ContextMenu() {
    std::cout << "Лабораторная работа №3, задание №2\n";
    std::cout << "Суть задания:\n";
    std::cout << "Найти сумму ряда с заданным общим членом, достигая определенной точности, "
                 "используя цикл do while.\n";
    std::cout << "Выполнил студент группы 453503 Халамов Николай\n";
}

int main() {
    ContextMenu();

    long double sum = 0.0;
    int n = 1;
    long double d_n;
    const long double epsilon = 1e-3;

    do {
        long double term1 = 1.0;
        long double term2 = 1.0;

        for (int i = 0; i < n; ++i) {
            term1 /= 2.0;
        }

        for (int i = 0; i < n; ++i) {
            term2 /= 3.0;
        }

        d_n = term1 + term2;
        sum += d_n;
        n++;

    } while (d_n >= epsilon);

    std::cout << "Сумма ряда с точностью " << epsilon << " равна " << sum << "\n";

    return 0;
}
