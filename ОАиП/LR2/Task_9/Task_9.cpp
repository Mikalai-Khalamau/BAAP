#include <cmath>
#include <iostream>
int main()
{

std::cout<<"Выберите функцию f(x) для расчетов:"<<"\n"<<"f(x)=2x-напишите 1"<<"\n"<<"f(x)=x^3-напишите 2"<<"\n"<<"f(x)=x/3-напишите 3"<<"\n";
int p;
std::cin>>p;

long double y;
long double z;
long double x;
long double f;

std::cout<<"Введите значение z(16-byte):"<<"\n";
std::cin>>z;

if (z>1) 
{
x=z;
}
if (z<=1) 
{
x=pow(x,2)+1;
}

switch (p) 
{
    case 1: 
    std::cout<<"Вы выбрали f(x)=2x и мы вычиcляем y=sin(n*2*x)+cos(k*x)+ln(m*x)"<<"\n";
    f=2*x;
    break;

    case 2:
    std::cout<<"Вы выбрали f(x)=x^3 и мы вычиcляем y=sin(n*x^3)+cos(k*x)+ln(m*x)"<<"\n";
    f=pow(x,3);
    break;

    case 3:
    std::cout<<"Вы выбрали f(x)=x/3 и мы вычиcляем y=sin(n*x/3)+cos(k*x)+ln(m*x)"<<"\n";
    f=x/3;
    break;

    default : std::cout<<"Вы не выбрали f(x)"<<"\n";

}

std::cout<<"Введите значения n,k,m(16-byte):"<<"\n";
long double n,k,m;
std::cin>>n>>k>>m;

y=sin(n*f)+cos(k*x)+log(m*x);

std::cout<<"Значение y равно "<<y<<"\n";

}