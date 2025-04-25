#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
int n;
cin>>n;
int a[n];
int b[n];
for (int q=0;q<n;q++)
{
    int y;
    cin>>y;
    a[q]=y;
    b[q]=-1;
}
stack<int> mystack;
mystack.push(0);
for (int i=1;i<n;i++)
{
if (a[i]>=a[mystack.top()])
{
mystack.push(i);
}
else 
{
    while (  !mystack.empty()  && a[i]<a[mystack.top()])
    {

    
    b[mystack.top()]=i;
    mystack.pop();
}
mystack.push(i);
}

}
for (int u=0;u<n;u++)
{
    cout<<b[u]<<" ";
}

return 0;
}