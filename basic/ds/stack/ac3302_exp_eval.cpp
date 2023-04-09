#include <iostream>
#include <cstring>
#include <stack>
#include <unordered_map>
// https://www.acwing.com/problem/content/3305/

using namespace std;

stack<int> st;
stack<char> op;

const unordered_map<char, int> pr = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};

void eval() {
    auto b = st.top(); st.pop();
    auto a = st.top(); st.pop();
    auto c = op.top(); op.pop();
    if (c == '+') st.push(a + b);
    else if (c == '-') st.push(a - b);
    else if (c == '*') st.push(a * b);
    else st.push(a / b);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string exp;
    cin >> exp;
    
    for (int i = 0, n = exp.size(); i < n; ++i) {
        char c = exp[i];
        if (isdigit(c)) {
            int x = 0, j = i;
            for (;j < n && isdigit(exp[j]); ++j) x = x * 10 + (exp[j] - '0');
            i = j - 1;
            st.push(x);
        } else if (c == '(') {
            op.push(c);
        } else if (c == ')') {
            while (op.top() != '(') eval();
            op.pop();
        } else {
            while (op.size() && op.top() != '(' && pr.at(op.top()) >= pr.at(c)) eval();
            op.push(c);
        }
    }
    
    while (op.size()) eval();
    cout << st.top();
    
    return 0;
}