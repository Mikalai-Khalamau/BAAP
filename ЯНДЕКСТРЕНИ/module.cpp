#include <bits/stdc++.h>
using namespace std;
const int modul=1000000007;
const int i=500000004;
int main()
{
ios::sync_with_stdio(false);
cin.tie(0);
    
int n;
cin>>n;
 vector <long long> a(n);
 for (int i=0;i<n;i++)
 {
    int x;
    cin>>x;
    a[i]=x;
 }
long long sum1=0;
long long sum2=0;

long long finale=0;
    for (int k = 0; k < n; ++k)
    {
        if (k >= 2)     {
           
             long long nowad = (sum1*sum1)%modul;
nowad = (nowad-sum2+modul)%modul;
nowad = (nowad*i)%modul;
           
finale = (finale+(a[k]%modul)*nowad)%modul;
                         }
       
sum1 = (sum1+a[k])%modul;
sum2 = (sum2+(a[k] * a[k])%modul)%modul;
    }


cout<<finale;
    return 0;
}