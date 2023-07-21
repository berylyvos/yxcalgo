#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

// https://www.acwing.com/problem/content/description/860/

const int N = 505, INF = 0x3f3f3f3f;
int g[N][N], d[N];
bool st[N];
int n, m;

int prim() {
    int s = 0;
    memset(d, 0x3f, sizeof d);
    d[1] = 0;
    
    for (int i = 0; i < n; ++i) {
        int t = -1;
        for (int j = 1; j <= n; ++j)
            if (!st[j] && (t == -1 || d[j] < d[t])) t = j;
        
        if (d[t] == INF) return INF;
        st[t] = true;
        s += d[t];
        
        for (int j = 1; j <= n; ++j) d[j] = min(d[j], g[t][j]);
    }
    
    return s;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    int a, b, c;
    while (m--) {
        cin >> a >> b >> c;
        g[b][a] = g[a][b] = min(g[a][b], c);
    }
    
    int t = prim();
    if (t == INF) cout << "impossible";
    else cout << t;
    
    return 0;
}