#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
int n;
cin>>n;
vector<int> myvector;
vector<long long> prefixSum;
for (int q=0;q<n;q++)
{
    string s;
    cin>>s;
if (s[0]=='+')
{
s.erase(0,1); 
int number=stoi(s);
myvector.push_back(number);
 if (prefixSum.empty()) 
 {
prefixSum.push_back(number);
} else 
{
 prefixSum.push_back(prefixSum.back()+number);
    }
}
else if (s[0]=='-')
{
cout<<myvector.back()<<'\n';
myvector.pop_back();
prefixSum.pop_back();
}
else if (s[0]=='?')
{
s.erase(0,1); 
int number=stoi(s);
long long sum = 0;
int size = myvector.size();
sum =prefixSum[size-1]; 
if (size-number-1 >= 0) {
sum -=prefixSum[size-number-1]; 
}
cout<<sum<<'\n';
}
}

return 0;
}