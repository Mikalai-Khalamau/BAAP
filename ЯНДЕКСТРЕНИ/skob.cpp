#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    string a;
    cin>>a;
    int m=0;
    std::stack<char> st;

    for (int i=0; i <a.length();i++) {
        if (a[i] == '(' || a[i] == '{' || a[i] == '[') st.push(a[i]);
        else if (a[i] == ')' || a[i] == '}' || a[i] == ']') {
            if (st.empty()) {
                m = 1;
                break;
 }
            if ((a[i]==')' && st.top()=='(') || (a[i]=='}' && st.top()=='{') || (a[i]==']' && st.top()=='[')) st.pop();
            else {
                m = 1;
                break;
 }
    }
    }

    if (m == 0 && st.empty()) cout<<"yes";
    else cout<<"no";

    return 0;
}