#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);

    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    // Сортируем массив дел
    std::sort(a.begin(), a.end());

    int days = 0;
    
    // Обрабатываем все дела
    while (!a.empty()) {
        days++; // Начинаем новый день
        int current = a[0]; // Текущее дело

        // Удаляем только одно похожее дело
        // Находим первое дело, которое мы можем удалить
        auto it = std::remove_if(a.begin(), a.end(), 
            [current, k](int x) { return x - current <= k; });

        // Удаляем одно дело, которое подходит под условие
        if (it != a.end()) {
            a.erase(it); // Удаляем только одно похожее дело
        }

        // Удаляем текущее дело
        a.erase(a.begin()); // Удаляем текущее дело
    }
    
    std::cout << days << std::endl;

    return 0;
}