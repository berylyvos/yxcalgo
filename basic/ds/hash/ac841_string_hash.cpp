#include <iostream>
using namespace std;
// https://www.acwing.com/problem/content/843/

using ull = unsigned long long;
const int N = 100010, P = 131;

int h[N], p[N], n, m, l1, l2, r1, r2;
char s[N];

inline ull get(int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    cin >> s + 1;
    
    p[0] = 1;
    for (int i = 1; i <= n; ++i) {
        p[i] = p[i - 1] * P;
        h[i] = h[i - 1] * P + s[i];
    }
    
    while (m--) {
        cin >> l1 >> r1 >> l2 >> r2;
        cout << (get(l1, r1) == get(l2, r2) ? "Yes\n" : "No\n");
    }
    
    return 0;
}