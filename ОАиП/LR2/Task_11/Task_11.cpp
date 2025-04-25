#include <iostream>
int main()
{

int h1,min1,h2,min2,h,min;

std::cout<<"Введите время начала(часы и минуты): ";
std::cin>>h1>>min1;

std::cout<<"Введите время окончания(часы и минуты): ";
std::cin>>h2>>min2;

if ((h2==h1)&&(min2==min1)) 
{
h=24;
min=0;
}

else if ((h2>=h1)&&(min2>=min1)) 
{
h=h2-h1;
min=min2-min1;
}

else if ((h2>h1)&&(min2<min1)) 
{
h=h2-h1-1;
min=min2+60-min1;
}

else if ((h2<h1)&&(min2>=min1)) 
{
h=h2+24-h1;
min=min2-min1;
}

else if ((h2<=h1)&&(min2<min1)) 
{
h=h2+23-h1;
min=min2+60-min1;
}

if (min<=9) 
{
std::cout<<"Студент решал задачи "<<h<<":0"<<min<<std::endl;
}

else 
{
std::cout<<"Студент решал задачи "<<h<<":"<<min<<std::endl;
}

}