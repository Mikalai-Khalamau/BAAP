#include <iostream>
#include <string>

// Функция отображения контекстного меню.
void DisplayContextMenu() {
  std::cout << "Лабораторная работа №3, задание №3\n";
  std::cout << "Суть задания:\n";
  std::cout << "Вычисление значений функции y = sin(x) - cos(x) на отрезке [A, B].\n";
  std::cout << "Выполнил студент группы 453503 Халамов Николай\n";
}

// Функция для проверки корректности ввода long double.
bool IsValidLongDouble(const std::string& str) {
  size_t i = 0;
  const size_t n = str.length();

  // Пропускаем начальные пробелы.
  while (i < n && std::isspace(str[i])) {
    ++i;
  }

  // Проверяем на наличие знака '+' или '-'.
  if (i < n && (str[i] == '+' || str[i] == '-')) {
    ++i;
  }

  bool has_digits = false;

  // Числа перед десятичной точкой.
  while (i < n && std::isdigit(str[i])) {
    ++i;
    has_digits = true;
  }

  // Десятичная точка и числа после нее.
  if (i < n && str[i] == '.') {
    ++i;
    // Должна быть хотя бы одна цифра после точки, если не было цифр до нее.
    if (!has_digits && (i >= n || !std::isdigit(str[i]))) {
      return false;
    }
    while (i < n && std::isdigit(str[i])) {
      ++i;
      has_digits = true;
    }
  }

  // Проверяем на экспоненциальную часть.
  if (i < n && (str[i] == 'e' || str[i] == 'E')) {
    ++i;
    // Возможный знак '+' или '-'.
    if (i < n && (str[i] == '+' || str[i] == '-')) {
      ++i;
    }
    bool has_exp_digits = false;
    // Цифры в экспоненциальной части.
    if (i >= n || !std::isdigit(str[i])) {
      return false;
    }
    while (i < n && std::isdigit(str[i])) {
      ++i;
      has_exp_digits = true;
    }
    if (!has_exp_digits) {
      return false;
    }
  }

  // Пропускаем конечные пробелы.
  while (i < n && std::isspace(str[i])) {
    ++i;
  }

  // Проверяем, что достигли конца строки.
  return i == n && has_digits;
}

//  функция проверки ввода.
long double CorrectInput(const std::string& request) {
  while (true) {
    std::cout << request;
    std::string input;
    std::getline(std::cin, input);

    if (IsValidLongDouble(input)) {
      try {
        // Преобразуем строку в long double.
        long double value = std::stold(input);
        return value;
      } catch (const std::out_of_range&) {
        std::cout
            << "Введенное число слишком большое или слишком маленькое. Пожалуйста, попробуйте снова.\n";
      } catch (const std::invalid_argument&) {
        // Это не должно произойти, так как мы уже проверили валидность.
        std::cout << "Некорректный ввод. Пожалуйста, попробуйте снова.\n";
      }
    } else {
      std::cout << "Некорректный ввод. Пожалуйста, попробуйте снова.\n";
    }
  }
}

// Определение константы pi.
constexpr long double kPi = 3.14159265358979323846;

// Функция для вычисления факториала.
long double Factorial(int n) {
  if (n == 0 || n == 1) {
    return 1.0;
  }
  long double result = 1.0;
  for (int i = 2; i <= n; ++i) {
    result *= i;
  }
  return result;
}

// Функция для вычисления x^n.
long double Power(long double x, int n) {
  long double result = 1.0;
  for (int i = 0; i < n; ++i) {
    result *= x;
  }
  return result;
}

// Реализация синуса через ряд Тейлора.
inline long double MySin(long double x) {
  long double term = x;  // Первый член ряда.
  long double sum = term;
  // Используем 10 членов ряда для достаточной точности.
  for (int i = 1; i < 10; ++i) {
    term *= -1.0 * x * x / ((2 * i) * (2 * i + 1));
    sum += term;
  }
  return sum;
}

// Реализация косинуса через ряд Тейлора.
long double MyCos(long double x) {
  long double term = 1.0;  // Первый член ряда.
  long double sum = term;
  // Используем 10 членов ряда для достаточной точности.
  for (int i = 1; i < 10; ++i) {
    term *= -1.0 * x * x / ((2 * i - 1) * (2 * i));
    sum += term;
  }
  return sum;
}

int main() {
  while (true) {
    // Отображение контекстного меню.
    DisplayContextMenu();

    // Запрос контрольных значений.
    long double a = CorrectInput("Введите значение A (начало отрезка), 16-byte: ");
    long double b = CorrectInput("Введите значение B (конец отрезка), 16-byte: ");
    const int m = 20;  // Количество шагов фиксировано.

    if (a >= b) {
      std::cout << "Значение A должно быть меньше значения B. Введите значения снова.\n\n";
      continue;
    }

    long double h = (b - a) / m;

    std::cout << "\nВычисляем значения функции y = sin(x) - cos(x) на отрезке ["
              << a << "," << b << "]:\n";

    for (int i = 0; i <= m; ++i) {
      long double x = a + i * h;
      long double y = MySin(x) - MyCos(x);
      std::cout << "При i=" << i << ", X=" << x
                << " значение выражения равно " << y << "\n";
    }

    // Запрос на повторный ввод или выход.
    char choice;
    std::cout << "\nХотите выполнить ещё одно вычисление? (y/n): ";
    std::cin >> choice;
    std::cin.ignore(1000, '\n');  // Очистка буфера ввода.

    if (choice != 'y' && choice != 'Y') {
      std::cout << "Выход из программы.\n";
      break;
    }

    std::cout << "\n";
  }

  return 0;
}