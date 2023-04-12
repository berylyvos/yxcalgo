#include <iostream>
#include <cstring>
using namespace std;
// https://www.acwing.com/problem/content/842/

const int N = 200003, nil = 0x3f3f3f3f;
int h[N];

inline int xhash(const int& x) {
    return (x % N + N) % N;
}

int find(const int& x) {
    int k = xhash(x);
    while (h[k] != nil && h[k] != x)
        if (++k == N) k = 0;
    return k;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    memset(h, 0x3f, sizeof h);
    int m, x;
    cin >> m;
    char op[2];
    while (m--) {
        cin >> op >> x;
        if (*op == 'I') h[find(x)] = x;
        else cout << (h[find(x)] == nil ? "No\n" : "Yes\n");
    }
    return 0;
}