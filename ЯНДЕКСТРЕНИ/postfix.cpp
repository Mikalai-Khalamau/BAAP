#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string input;
    getline(cin, input); 
    stack<int> st;
    long long l = input.length(); 
    string s = "";

    for (int i = 0; i < l; i++) {
        char c = input[i];
        if (isdigit(c) ) {
            s += c;
        } 
        else if (c == ' ' && !s.empty()) {
            st.push(stoi(s));
            s = "";
        } 
        else if (c == '-' || c == '+' || c == '*') {
            if (st.size() < 2) {
                return 1; 
            }
            int e = st.top(); st.pop();
            int d = st.top(); st.pop();
            if (c == '-') {
                st.push(d - e);
            } 
            else if (c == '+') {
                st.push(d + e);
            } 
            else if (c == '*') {
                st.push(d * e);
            }
        }
    }

    if (!s.empty()) {
        st.push(stoi(s));
    }

    if (!st.empty()) {
        cout << st.top() << endl;
    }

    return 0;
}