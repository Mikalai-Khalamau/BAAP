/* 
long double normalization (long double x)
{
    if (x>=0)
    { 
    while (x>p) 
    {
     long double k=1;
     while (x-k*2*p>0) 
     {
     k=k*2;
   
     }
     x=x-k*p;
    }
    
    return x;
    }
    else 
    {
        x=x*(-1);
        while (x>p) 
    {
     long double k=1;
     while (x-k*p>0) 
     {
     k=k*p;
     }
     x=x-k;
    }
    
    return x*(-1);
    }
}
*/