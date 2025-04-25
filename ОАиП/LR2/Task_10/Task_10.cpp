#include <iostream>

long double abs(long double a, long double b) 
{   
long double c=a-b;
if (c<0) c=-1*c;
return c;
}
long double sqrt(long double n)
{
const double tochn = 1E-20;
long double x = 1;

for (;;)
{
long double nx = (x + n / x) / 2;
if (abs(x,nx)< tochn)  break;
x = nx;
}

return x;

}

int main()
{
 
long double x1,y1,r;
long double x2,y2,R;

std::cout<<"Введите координаты центра первого круга(16-byte): "<<std::endl;
std::cin>>x1>>y1;

std::cout<<"Введите радиус первого круга(16-byte): "<<std::endl;
std::cin>>r;

std::cout<<"Введите координаты центра второго круга(16-byte): "<<std::endl;
std::cin>>x2>>y2;

std::cout<<"Введите радиус второго круга(16-byte): "<<std::endl;
std::cin>>R;

long double s=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));

if (s + r <= R) 
{
std::cout << "Да" << std::endl;
}

else if (s + R <= r) 
{
std::cout << "Да, но справедливо обратное для двух фигур" << std::endl;
}

else if (s < r + R) 
{
std::cout << "Фигуры пересекаются" << std::endl; 
}

else 
{
std::cout << "Ни одно условие не выполнено" << std::endl;
}

}