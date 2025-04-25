constexpr long double kPi = 3.14159265358979323846264338327950288419716939937510;

// Функция вычисления абсолютного значения для типа long double
long double my_abs(long double x) {
    return x < 0 ? -x : x;
}
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
long double my_sin(long double y)
{
    long double x=normalization(y);
 
      
    
    
    long double term = x; // Первый член ряда
    long double sum = term;
    int n = 1;
    const int MAX_ITERATIONS = 200;
    const long double EPSILON = 1e-10;
    
    while(n < MAX_ITERATIONS) {
        // Вычисление следующего члена ряда
        term *= -1 * x * x / ((2 * n) * (2 * n + 1));
        sum += term;
        if (my_abs(term) < EPSILON)
            break;
        n++;
    }
    
    return sum;

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
// Реализация функции тангенса
double tang (double x) {
    double cosx = my_cos(x);
    if(my_abs(cosx) < 1e-10) { // Проверка на близость к разрыву
        // Возвращаем большое число вместо бесконечности
        return (x > 0) ? 1e10 : -1e10;
    }
    return my_sin(x) / cosx;
}