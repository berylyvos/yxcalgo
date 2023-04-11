#include <iostream>
#include <algorithm>
using namespace std;
// https://www.acwing.com/problem/content/840/

const int N = 100010;
int h[N], sz, n, m;

void down(int u) {
    int t = u, l = u * 2, r = l + 1;
    if (l <= sz && h[l] < h[t]) t = l;
    if (r <= sz && h[r] < h[t]) t = r;
    if (t != u) {
        swap(h[t], h[u]);
        down(t);
    }
}

void init() {
    sz = n;
    for (int i = n / 2; i >= 1; --i) down(i);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> h[i];
    init();
    while (m--) {
        cout << h[1] << ' ';
        h[1] = h[sz--];
        down(1);
    }
    
    return 0;
}