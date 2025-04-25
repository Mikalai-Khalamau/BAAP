#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
 long long n,r;long long sum=0;
 cin>>n>>r;long long a[n];
 for (long long i=0;i<n;i++)
 {
long long q;
cin>>q;
a[i]=q;
 }
 long long e=0;
 
 for (long long i=0;i<n;i++)
 {


 while (e<n && a[e]-a[i]<=r)
 {
 e++;
 }
  sum=sum+n-e;
 }
 cout<<sum<<'\n';
    
}