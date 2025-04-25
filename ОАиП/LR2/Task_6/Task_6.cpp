#include <cmath>
#include <iostream>
int main()
{

std::cout<<"Введите значения x,p,h>0,k!=0,c!=0,d!=0(16-byte): ";
long double x,p,h,k,c,d;
std::cin>>x>>p>>h>>k>>c>>d;

/*if ((h>0)&&(k!=0)&&(c!=0)&&(d!=0))
{
*/
long double a=x-p;
long double b=log(h);
long double y=0.78*b+pow(a,3)/k/c/d;
std::cout<<"y="<<y<<"\n";
// }
/*
else 
{
std::cout<<"Введенные данные не соответствуют условиям"<<"\n";
}
*/
}
