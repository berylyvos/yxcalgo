#include <iostream>
#include <cstring>
using namespace std;
// https://www.acwing.com/problem/content/842/

const int N = 100003;
int h[N], e[N], ne[N], idx;

inline int xhash(const int& x) {
    return (x % N + N) % N;
}

void insert(const int& x) {
    int k = xhash(x);
    e[idx] = x, ne[idx] = h[k], h[k] = idx++;
}

bool find(const int& x) {
    int k = xhash(x);
    for (int i = h[k]; ~i; i = ne[i])
        if (e[i] == x) return true;
    return false;
}


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    memset(h, -1, sizeof h);
    int m, x;
    cin >> m;
    char op[2];
    while (m--) {
        cin >> op >> x;
        if (*op == 'I') insert(x);
        else cout << (find(x) ? "Yes\n" : "No\n");
    }
    return 0;
}