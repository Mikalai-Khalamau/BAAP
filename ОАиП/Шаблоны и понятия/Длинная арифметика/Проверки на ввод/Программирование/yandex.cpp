#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


size_t task(const vector<int>& array, long long sum)
{
  std::unordered_map<long long, size_t> counts;
  long long sum_now = 0;
  size_t result = 0;

  
  for (const auto n : array) {
    ++counts[sum_now]; 
    sum_now += n;
    auto count = counts.find(sum_now - sum);
    if (count != counts.end()) {
      result += count->second;
    }
  }
  return result;
} 


int main()
{
  int n;int k;
std::cin>>n>>k;
vector<int> d;
for (int i=0;i<n;i++)
{
  long double r;
  cin>>r;
 d.push_back(r);
}
std::cout<<task( d,  k);
} 