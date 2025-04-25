#include <bits/stdc++.h>
using namespace std;

int main(){

ios::sync_with_stdio(false);
cin.tie(nullptr);

int n,k;
cin>>n>>k;

vector<int> array(n);
for(int i=0;i<n;i++) {
cin>>array[i];
}

deque<int> mydeque;
vector<int> result;

    for(int i=0;i<n;i++){
        if(!mydeque.empty() && mydeque.front()<i-k+1) {
            mydeque.pop_front();
        }

        while(!mydeque.empty() && array[mydeque.back()]>array[i]) {
            mydeque.pop_back();
        }

        mydeque.push_back(i);

        if(i>=k-1) {
            result.push_back(array[mydeque.front()]);
        }
    }

for(int i=0;i<result.size();i++) {
cout<<result[i]<<'\n';
}

return 0;
}