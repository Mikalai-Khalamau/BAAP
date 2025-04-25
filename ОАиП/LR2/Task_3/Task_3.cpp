#include <iostream>
int main()
{

std::cout<<"Введите первый член геометрической прогрессии(16-byte): ";
long double b1;
std::cin>>b1;

long double n=28.0;
long double q=1.0/(n+1.0);
long double sum=b1/(1.0-q);

std::cout<<"Сумма всех членов бесконечно убывающей геометрической прогрессии равна: "<<sum<<"\n";

}