/* 
constexpr long double kPi = 3.14159265358979323846264338327950288419716939937510;

long double normalization (long double x)
{
    if (x>=0)
    { 
    while (x>kPi) 
    {
     long double k=1;
     while (x-k*2*kPi>0) 
     {
     k=k*2;
   
     }
     x=x-k*kPi;
    }
    
    return x;
    }
    else 
    {
        x=x*(-1);
        while (x>kPi) 
    {
     long double k=1;
     while (x-k*kPi>0) 
     {
     k=k*kPi;
     }
     x=x-k;
    }
    
    return x*(-1);
    }
}
// Функция для вычисления cos(x) с использованием ряда Тейлора
long double my_cos(long double y){
    long double x=normalization(y);

    long double term = 1.0; // Первый член ряда
    long double sum = term;
    int n = 1;
    const int TERMS = 10; // Количество членов ряда

    for(int i = 1; i < TERMS; ++i){
        term *= -x * x / ((2 * i - 1) * (2 * i));
        sum += term;
    }
    return sum;
}
*/