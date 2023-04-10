#include <iostream>
using namespace std;
// https://www.acwing.com/problem/content/838/

const int N = 100010;
int p[N], n, m;

int find(int x) {
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}

inline void merge(int a, int b) {
    p[find(a)] = find(b);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) p[i] = i;
    char op;
    int a, b;
    while (m--) {
        cin >> op >> a >> b;
        if (op == 'M') {
            merge(a, b);
        } else {
            cout << (find(a) == find(b) ? "Yes\n" : "No\n");
        }
    }
    return 0;
}