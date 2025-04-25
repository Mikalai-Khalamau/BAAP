#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
int main() {
int n;int k;int ans=0;
cin>>n>>k;int array[n];int prefix[n+1];
prefix[0]=0;
for (int i=0;i<n;i++)
{
  long double r;
  cin>>r;
 array[i]=r;
 prefix[i+1]=prefix[i]+array[i];
   
}
for (int y=0;y<n;y++)
{
for (int b=0;b<n;b++)
{
if (prefix[b+1]-prefix[y]<=k) ans++;
}
}
cout<<ans;
return 0;
}
