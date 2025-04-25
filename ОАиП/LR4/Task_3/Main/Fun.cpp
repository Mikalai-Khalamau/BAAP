#include "prot.h"
// Функция для вычисления суммы и произведения заштрихованных элементов
void MainQuestion(long double** matrix, long long N, long double& sum, long double& product) {
    sum = 0.0;     // Сумма элементов
    product = 1.0; // Произведение элементов
    int k = 0, l = N;

    if (N % 2 == 1) {
        for (int i = 0; i < N; i++) {
            for (int j = k; j < l; j++) {
                product *= matrix[i][j];
                sum += matrix[i][j];
            }
            if (i <= N / 2 - 1) {
                k++;
                l--;
            } else {
                k--;
                l++;
            }
        }
    } else {
        for (int i = 0; i < N; i++) {
            for (int j = k; j < l; j++) {
                product *= matrix[i][j];
                sum += matrix[i][j];
            }
            if (i < N / 2 - 1) {
                k++;
                l--;
            }
            if (i >= N / 2) {
                k--;
                l++;
            }
        }
    }
}
