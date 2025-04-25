#include <iostream>
using namespace std;
int main()
{

//Вычисляем НОД по алгоритму Еквклида
std::cout<<"Введите 2 целых числа для вычисления НОД по алгоритму Евклида: ";
long long x,y;
std::cin>>x>>y;
std::cout<<"x="<<x<<" "<<"y= "<<y<<std::endl;

 while ((x!=0)&&(y!=0))
{

if (x>=y) 
{
x=x%y;
}

else if (x<y) 
{
y=y%x;
}

    std::cout<<"x="<<x<<" "<<"y= "<<y<<std::endl;

}

if (x<y) 
{
    std::cout<<"НОД="<<y<<"\n";
}

else 
{
std::cout<<"НОД="<<x<<"\n";
}

}
