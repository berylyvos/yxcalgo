#include <iostream>
#include <string>
using namespace std;
// https://www.acwing.com/problem/content/831/

const int N = 100010;
int q[N], hh, tt = -1;

void push(int x) { q[++tt] = x; }

void pop() { ++hh; }

int top() { return q[hh]; }

bool empty() { return hh > tt; }

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, x;
    cin >> n;
    string op;
    while (n--) {
        cin >> op;
        if (op == "push") {
            cin >> x;
            push(x);
        } else if (op == "query") {
            cout << top() << '\n';
        } else if (op == "pop") {
            pop();
        } else {
            cout << (empty() ? "YES" : "NO") << endl;
        }
    }
    
    return 0;
}