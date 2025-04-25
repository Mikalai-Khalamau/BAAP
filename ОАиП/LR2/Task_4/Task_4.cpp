#include <iostream>
int main()
{

std::cout<<"Введите целочисленные x и y: ";
long long x,y;
std::cin>>x>>y;

if (x<y) 
{
x=0;
} 

else if (y<x) 
{
y=0;
}

else 
{
x=0;y=0;
}

std::cout<<"Введите три различных числа a,b,c(16-byte): ";
long double a,b,c;
std::cin>>a>>b>>c;

std::cout<<"Введите k(16-byte): ";
long double k;
std::cin>>k;

if ((a>b)&&(a>c))
{ 
a=a-k;
}

else if ((c>b)&&(c>a)) 
{
c=c-k;
}

else if ((a<b)&&(b>c)) 
{
b=b-k;
}

std::cout<<"x="<<x<<"\n"<<"y="<<y<<"\n"<<"a="<<a<<"\n"<<"b="<<b<<"\n"<<"c="<<c<<"\n";

}