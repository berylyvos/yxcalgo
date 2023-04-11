#include <iostream>
#include <algorithm>
using namespace std;
// https://www.acwing.com/problem/content/841/

const int N = 100010;
int h[N], sz, idx, m;

// hd: i to idx
// dh: idx to i
int hd[N], dh[N];

void h_swap(int i, int j) {
    swap(dh[hd[i]], dh[hd[j]]);
    swap(hd[i], hd[j]);
    swap(h[i], h[j]);
}

void down(int u) {
    int t = u, l = u * 2, r = l + 1;
    if (l <= sz && h[l] < h[t]) t = l;
    if (r <= sz && h[r] < h[t]) t = r;
    if (t != u) {
        h_swap(t, u);
        down(t);
    }
}

void up(int u) {
    while (u >> 1 && h[u >> 1] > h[u]) {
        h_swap(u, u >> 1);
        u >>= 1;
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> m;
    char op[3];
    int x, k;
    while (m--) {
        cin >> op;
        if (*op == 'I') {
            cin >> x;
            hd[++sz] = ++idx;
            dh[idx] = sz;
            h[sz] = x;
            up(sz);
        } else if (*op == 'D' && op[1] == 'M') {
            h_swap(1, sz--);
            down(1);
        } else if (*op == 'C') {
            cin >> k >> x;
            k = dh[k];
            h[k] = x;
            down(k), up(k);
        } else if (*op == 'P') {
            cout << h[1] << '\n';
        } else { // D
            cin >> k;
            k = dh[k];
            h_swap(k, sz--);
            down(k), up(k);
        }
    }
    return 0;
}