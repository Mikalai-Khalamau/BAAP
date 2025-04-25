#include <iostream>  

long double const PI=3.14159265358979323846;

long double modul(long double a)
 {
    if (a<0) a=a*(-1);
    return a;
 }

 long double pow(long double a,long double x)
{
 long double b=1;
    for (long long i=1;i<=x;i++)
    {
        b=b*a;
    }
    return b;
}

// Функция для вычисления арккосинуса с использованием ряда Тейлора
long double arccos(long double x) {
    // arccos(x) = pi/2 - arcsin(x)
    // Реализуем arcsin через ряд Тейлора
    double term = x;
    double sum = term;
    int n = 1;
    double epsilon = 1e-10;

    while (modul(term) > epsilon) 
    {
        term *= (pow(x, 2) * (2 * n - 1)) / (2 * n);
        sum += term / (2 * n + 1);
        n++;
    }

    return PI / 2 - sum;

}

// Функция для вычисления косинуса с использованием ряда Тейлора
double cos(double x) {
    // Приведение x к диапазону [-pi, pi]
    while (x > PI) x -= 2 * PI;
    while (x < -PI) x += 2 * PI;
    double term = 1.0; // Первый член ряда
    double sum = term;
    int n = 1;
    double epsilon = 1e-10;
    while (modul(term) > epsilon) {
        term *= -1 * x * x / ((2 * n - 1) * (2 * n));
        sum += term;
        n++;
    }
    return sum;

}
long double absrazn(long double a, long double b) 
    {   
        long double c=a-b;
        if (c<0) c=-1*c;
        return c;
}

// Функция для вычисления кубического корня с использованием метода Ньютона
long double cbrt(long double x) {
    if (x == 0)
        return 0;
    long double guess = x;
    long double tochn = 1e-10;
    while (true) {
        long double new_guess = guess - (guess * guess * guess - x) / (3 * guess * guess);
        if (absrazn(new_guess,guess) < tochn)
            break;
        guess = new_guess;
    }
    return guess;
}

long double sqrt(long double n)
{
const double tochn = 1E-20;
long double x = 1;
for (;;) {
	long double nx = (x + n / x) / 2;
	if (absrazn(x,nx)< tochn)  break;
	x = nx;
}
return x;

}

int main() {
    // Объявляем переменные для коэффициентов уравнения
    long double p, q;

    // Запрашиваем у пользователя коэффициенты p и q
    std::cout << "Введите коэффициент p: "<<"\n";
    std::cin >> p;
    std::cout << "Введите коэффициент q: "<<"\n";
    std::cin >> q;

    // Вычисляем дискриминант Δ = (q/2)^2 + (p/3)^3
    double delta = pow(q / 2.0, 2) + pow(p / 3.0, 3);

    // Проверяем знак дискриминанта и решаем уравнение в зависимости от его значения
    if (delta > 0) {
        // Один действительный корень и два комплексных
        double sqrt_delta = sqrt(delta);
        double u = cbrt(-q / 2.0 + sqrt_delta);  // Вычисляем кубический корень
        double v = cbrt(-q / 2.0 - sqrt_delta);
        double x = u + v;  // Действительный корень

        std::cout << "Один действительный корень: x = " << x << std::endl;
    }
    else if (abs(delta) < 1e-8) {
        // Все корни действительные и по крайней мере два из них совпадают
        double u = cbrt(-q / 2.0);
        double x1 = 2 * u;
        double x2 = -u;

        std::cout << "Все корни действительные: "<< x1 << " " << x2 << std::endl;
    }
    else {
        // Все корни действительные и различны (delta < 0)
        double p_div_3 = p / 3.0;
        double p_div_3_cubed = p_div_3 * p_div_3 * p_div_3;

        // Вычисляем радиус и угол для тригонометрической формулы
        double r = 2 * sqrt(-p_div_3);

        // Вычисляем аргумент для функции acos, обеспечивая его попадание в диапазон [-1, 1]
        double acos_arg = -q / (2 * sqrt(-p_div_3_cubed));
        if (acos_arg < -1.0) acos_arg = -1.0;
        if (acos_arg > 1.0) acos_arg = 1.0;

        double phi = arccos(acos_arg);

        // Вычисляем три действительных корня
        double x1 = r * cos(phi / 3.0);
        double x2 = r * cos((phi + 2 * PI) / 3.0);
        double x3 = r * cos((phi + 4 * PI) / 3.0);

        std::cout << "Все корни действительные и различны:" << std::endl;
        std::cout << "x1 = " << x1 << std::endl;
        std::cout << "x2 = " << x2 << std::endl;
        std::cout << "x3 = " << x3 << std::endl;
    }

    return 0;
}