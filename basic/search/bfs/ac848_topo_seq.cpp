#include <iostream>
#include <cstring>
using namespace std;

// https://www.acwing.com/problem/content/850/

const int N = 100010;
int h[N], e[N], ne[N], idx;
int q[N], in[N];
int n, m;

void add(int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; }

bool topo_sort() {
    int hh = 0, tt = -1;
    for (int i = 1; i <= n; ++i)
        if (in[i] == 0) q[++tt] = i;
    
    while (hh <= tt) {
        int u = q[hh++];
        for (int i = h[u]; ~i; i = ne[i]) {
            int j = e[i];
            if (--in[j] == 0) q[++tt] = j;
        }
    }
    
    return tt == n - 1;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    memset(h, -1, sizeof h);
    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        add(a, b);
        in[b]++;
    }
    
    if (topo_sort()) {
        for (int i = 0; i < n; ++i) cout << q[i] << " ";
    } else cout << -1;
    
    return 0;
}