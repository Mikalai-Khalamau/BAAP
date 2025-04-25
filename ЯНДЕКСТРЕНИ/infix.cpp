#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string input;
    getline(cin, input);

    stack<char> operators;
    string postfix;

    for (int i = 0; i < input.length(); i++) {
        char c = input[i];
        if (isspace(c)) continue;

        if (isdigit(c)) {
            while (isdigit(c)) {
                postfix += c; 
                i++;
                if (i < input.length()) c = input[i]; 
                else break;
            }
            postfix += ','; 
            i--; 
        } else if (c == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                postfix += ','; 
                operators.pop();
            }
            if (!operators.empty()) operators.pop();
            else {
                cout << "WRONG\n";
                return 0; // Ошибка: лишняя закрывающая скобка
            }
        } else if (c == '+' || c == '-') {
            while (!operators.empty() && (operators.top() == '*' || operators.top() == '+' || operators.top() == '-')) {
                postfix += operators.top();
                postfix += ','; 
                operators.pop();
            }
            operators.push(c);
        } else if (c == '*') {
            while (!operators.empty() && (operators.top() == '*')) {
                postfix += operators.top();
                postfix += ','; 
                operators.pop();
            }
            operators.push(c);
        }
    }

    while (!operators.empty()) {
        if (operators.top() == '(') {
            cout << "WRONG\n";
            return 0; // Ошибка: лишняя открывающая скобка
        }
        postfix += operators.top();
        postfix += ','; 
        operators.pop();
    }

    stack<int> st;
    string символ;
    istringstream ss(postfix);

    while (getline(ss, символ, ',')) { 
        if (isdigit(символ[0])) {
            st.push(stoi(символ));
        } else {
            if (st.size() < 2) {
                cout << "WRONG\n";
                return 0;
            }
            int e = st.top(); st.pop();
            int d = st.top(); st.pop();
            if (символ == "-") {
                st.push(d - e);
            } else if (символ == "+") {
                st.push(d + e);
            } else if (символ == "*") {
                st.push(d * e);
            }
        }
    }

    if (st.size() != 1) {
        cout << "WRONG\n";
    } else {
        cout << st.top() << "\n";
    }

    return 0;
}