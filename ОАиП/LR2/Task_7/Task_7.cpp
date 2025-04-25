#include <iostream>
int main()
{
    
std::cout<<"Введите значение n(16-byte): ";    
long double c=25.0;
long double a=-13.8;
long double v=a*a*a*a*a*a*a;
long double b=8.9;
long double s=a+b;
long double y;
long long n;
std::cin>>n;

switch (n)
{

case 2 : y=b*c-a*a;
break;

case 3 : y=a-b*c;
break;

case 7 : y=v+c;
break;

case 56 : y=b*c;
break;

default : y=s*s*s;
break;

}

std::cout<<y<<"\n";

}