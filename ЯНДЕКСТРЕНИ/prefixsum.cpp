#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
int main() {
int n;
cin>>n;int array[n];int prefix[n+1];
prefix[0]=0;
for (int i=0;i<n;i++)
{
  long double r;
  cin>>r;
 array[i]=r;
 prefix[i+1]=prefix[i]+array[i];
 cout<<prefix[i+1]<<' ';
}

return 0;
}
