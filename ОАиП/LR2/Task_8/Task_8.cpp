#include <iostream>

//функция вычисления квадрата числа
long double kvadr(long double a)
{
    a=a*a;
    return a;
}

//функция расчета модуля разности 2 чисел abs
long double absrazn(long double a, long double b) 
{   
        long double c=a-b;
        if (c<0) c=-1*c;
        return c;
}

//функция расчета квадратного корня числа
long double my_sqrt(long double n)
{
if (n==0) 
{
return 0;
}

else 
{

const double tochn = 1E-12;
long double x = 1;

for (;;) 
{
double nx = (x + n / x) / 2;
if (absrazn(x,nx)< tochn)  break;
x = nx;
}

return x;
}

}

 //Функция арксинуса
 long double my_arcsin(long double x)
{
    long double tochn=1.0E-12;
    long double n=1;
    long double a=x;
    long double s=1;
    long double r=x;
 
    while (s > tochn)
    {
        a=x*x*(a*(2*n-1))/(2*n);
        s=a/(2*n+1);
        r=r+s;
        n++;
        
    }

    return r;

}

 const long double pi=3.141592653589793;
 
// Функция для вычисления арккосинуса с использованием ряда Тейлора
long double my_arccos(long double x) {
    // arccos(x) = pi/2 - arcsin(x)
    // Реализуем arcsin через ряд Тейлора
    double term = x;
    double sum = term;
    int n = 1;
    double epsilon = 1e-10;

    while (absrazn(term,0) > epsilon) 
    {
        term *= (x*x * (2 * n - 1)) / (2 * n);
        sum += term / (2 * n + 1);
        n++;
    }

    return pi / 2 - sum;

}

//Решение задачи

int main()
{

    long double x1,y1,x2,y2,x3,y3;
    std::cout<<"Введите координаты первой вершины треугольника(16-byte): "<<"\n";
    std::cin>>x1>>y1;
    std::cout<<"Введите координаты второй вершины треугольника(16-byte): "<<"\n";
    std::cin>>x2>>y2;
    std::cout<<"Введите координаты третьей вершины треугольника(16-byte): "<<"\n";
    std::cin>>x3>>y3;

//Посчитаем длины сторон треугольника
long double side1=my_sqrt(kvadr(x2-x1)+kvadr(y2-y1));
long double side2=my_sqrt(kvadr(x3-x1)+kvadr(y3-y1));
long double side3=my_sqrt(kvadr(x2-x3)+kvadr(y2-y3));

//Проверка на существование треугольника
if ((side1+side2<=side3)||(side1+side3<=side2)||(side3+side2<=side1)) 
{
    std::cout<<"Треугольник не существует"<<"\n";
}

else 
{

//Посчитаем периметр и площадь треугольника
long double per=side1+side2+side3;
long double s1=my_sqrt(per/2*(per/2-side1)*(per/2-side2)*(per/2-side3));

//Посчитаем радиусы вписанной и описанной окружностей треугольника
long double rvpis=2*s1/per;
long double ropis=side1*side2*side3/4/s1;

//Посчитаем площадь и периметр этих окружностей
long double svpis=pi*kvadr(rvpis);
long double sopis=pi*kvadr(ropis);
long double pervpis=2*pi*rvpis;
long double peropis=2*pi*ropis;

//Посчитаем длины высот треугольника
long double h1=s1*2/side1;
long double h2=s1*2/side2;
long double h3=s1*2/side3;

//Посчитаем длины медиан треугольника
long double m3=my_sqrt(2*kvadr(side1)+2*kvadr(side2)-kvadr(side3))/2;
long double m1=my_sqrt(2*kvadr(side3)+2*kvadr(side2)-kvadr(side1))/2;
long double m2=my_sqrt(2*kvadr(side1)+2*kvadr(side3)-kvadr(side2))/2;
//Посчитаем косинусы углов
long double cosya=(side3*side3-side1*side1-side2*side2)/-2/side2/side1;
long double cosyb=(side2*side2-side1*side1-side3*side3)/-2/side3/side1;
long double cosyc=(side1*side1-side3*side3-side2*side2)/-2/side2/side3;
//Найдем синусы углов
long double sinya=h3/side2;
long double sinyb=h3/side1;
long double sinyc=h1/side2;

//Найдем углы в радианах 
long double ya=my_arccos(cosya);
long double yb=my_arccos(cosyb);
long double yc=my_arccos(cosyc);

//Посчитаем градусные меры углов
long double gradya=ya/pi*180;
long double gradyb=yb/pi*180;
long double gradyc=yc/pi*180;

//Посчитаем длины биссектрис треугольника
long double b3=2/(side1+side2)*my_sqrt(side1*side2*per*(per-side3));
long double b1=2/(side2+side3)*my_sqrt(side3*side2*per*(per-side1));
long double b2=2/(side1+side3)*my_sqrt(side1*side3*per*(per-side2));
//Еще 2 способа посчитать площадь
long double s2=per/2*rvpis;
long double s3=side1*side2/2*sinyc;

std::cout<<"Стороны треугольника равны: "<<side1<<" "<<side2<<" "<<side3<<"\n";

std::cout<<"Длины высот треугольника равны: "<<h1<<" "<<h2<<" "<<h3<<"\n";

std::cout<<"Длины медиан треугольника равны: "<<m1<<" "<<m2<<" "<<m3<<"\n";

std::cout<<"Длины биссектрис треугольника равны: "<<b1<<" "<<b2<<" "<<b3<<"\n";

std::cout<<"Градусные меры углов треугольника равны: "<<gradya<<" "<<gradyb<<" "<<gradyc<<"\n";

std::cout<<"Радианные меры углов треугольника равны: "<<ya<<" "<<yb<<" "<<yc<<"\n";

std::cout<<"Радиус вписанной окружности равен: "<<rvpis<<"\n";

std::cout<<"Радиус описанной окружности равен: "<<ropis<<"\n";

std::cout<<"Периметр описанного треугольника равен: "<<peropis<<"\n";

std::cout<<"Площадь описанного треугольника равна: "<<sopis<<"\n";

std::cout<<"Периметр вписанного треугольника равен: "<<pervpis<<"\n";

std::cout<<"Площадь вписанного треугольника равна: "<<svpis<<"\n";

std::cout<<"Периметр треугольника равен: "<<per<<"\n";

std::cout<<"Площадь треугольника равна: "<<s1<<" "<<s2<<" "<<s3<<"\n";

}

}