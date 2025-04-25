#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
int main() 
{
    long double k, x, y, r;
    std::cin >> k >> x >> y;

   
    if (((x == 0) && (y >= 0) && (y <= k)) ||
        ((x == k) && (y >= 0) && (y <= k)) ||
        ((y == 0) && (x >= 0) && (x <= k)) ||
        ((y == k) && (x >= 0) && (x <= k))) 
    {
        r = 0;
    }
   
    else if ((x >= k) && (y >= k)) 
    {
        r = std::sqrt((x - k) * (x - k) + (y - k) * (y - k));
    }
    else if ((x >= k) && (y <= 0)) 
    {
        r = std::sqrt((x - k) * (x - k) + y * y);
    }
    else if ((x >= k) && (y >= 0) && (y <= k)) 
    {
        r = std::fabs(x - k);
    }
    else if ((x <= 0) && (y >= k)) 
    {
        r = std::sqrt(x * x + (y - k) * (y - k));
    }
    else if ((x <= 0) && (y <= 0)) 
    {
        r = std::sqrt(x * x + y * y);
    }
    else if ((x <= 0) && (y >= 0) && (y < k)) 
    {
        r = std::fabs(x);
    }
    else if ((x >= 0) && (x <= k) && (y >= k)) 
    {
        r = std::fabs(y - k);
    }
    else if ((x >= 0) && (x <= k) && (y <= 0)) 
    {
        r = std::fabs(y);
    }
  
    else 
    {
        //r = std::min(std::min(std::fabs(x), std::fabs(y)) ,std::min(std::fabs(k - x), std::fabs(k - y)));
     r = std::min({std::fabs(x), std::fabs(k - x), std::fabs(y), std::fabs(k - y)});
    }

    
    std::cout << std::setprecision(22) << r;
    
    return 0;
}
