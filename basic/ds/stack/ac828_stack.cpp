#include <iostream>
using namespace std;
// https://www.acwing.com/problem/content/830/

const int N = 100010;

int st[N], tt = 0;

void push(int x) {
    st[++tt] = x;
}

void pop() {
    --tt;
}

int top() {
    return st[tt];
}

bool empty() {
    return tt == 0;
}

int main() {
    int m;
    cin >> m;
    while (m--) {
        int x;
        string op;
        cin >> op;
        if (op == "push") {
            cin >> x;
            push(x);
        } else if (op == "pop") {
            pop();
        } else if (op == "query") {
            cout << top() << endl;
        } else {
            cout << (empty() ? "YES" : "NO") << endl; 
        }
    }
    
    return 0;
}