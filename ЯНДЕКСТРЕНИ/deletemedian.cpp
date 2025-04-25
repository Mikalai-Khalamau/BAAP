#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
int n;
cin>>n;
std::vector<int> vec(n);
for (int i=0;i<n;i++)
{
    int q;
    cin>>q;
    vec[i]=q;
    //cout<<vec[i];
}
std::sort(vec.begin(), vec.end());
int u=n;
std::vector<int> vec2(n);
while (n>0)
{
    int num;
    if (n%2==1) 
    {
         num=(n-1)/2;
 //delete (n-1)/2
    }
    if (n%2==0)
    {
        if (vec[n/2]<=vec[(n/2)-1]) num=n/2;
        else  num=(n/2)-1;
       
//delete min n/2 or (n/2)-1
    }
      vec2.insert(vec2.begin(),vec[num]);
    vec.erase(vec.begin()+num);

    n--;
}

for (int i=u-1;i>=0;i--)
{
   
    cout<<vec2[i]<<' ';
}

 return 0;
    
}