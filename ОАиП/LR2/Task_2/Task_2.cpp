#include <iostream>
int main()
{

std::cout<<"Введите действительные положительные длины сторон треугольника(16-byte): ";
long double side1,side2,side3;
std::cin>>side1>>side2>>side3;

if ((side1+side2>side3)&&(side1+side3>side2)&&(side3+side2>side1)) 
{
std::cout <<"Треугольник с заданными сторонами существует"<<"\n";
} 

else {
std::cout<<"Треугольник с заданными сторонами не существует"<<"\n";
}

}