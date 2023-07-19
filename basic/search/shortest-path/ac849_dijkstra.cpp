#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

// https://www.acwing.com/problem/content/description/851/

const int N = 505, M = 100010, INF = 0x3f3f3f3f;
int g[N][N], d[N];
bool st[N];
int n, m;

int dijkstra() {
    memset(d, 0x3f, sizeof d);
    d[1] = 0;
    
    for (int i = 0; i < n; ++i) {
        int t = -1;
        for (int j = 1; j <= n; ++j)
            if (!st[j] && (t == -1 || d[j] < d[t])) t = j;
        
        st[t] = true;
        for (int j = 1; j <= n; ++j)
            if (g[t][j] != INF) d[j] = min(d[j], d[t] + g[t][j]);
    }
    
    return d[n] != INF ? d[n] : -1;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    int a, b, c;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c);
    }
    
    cout << dijkstra();
    
    return 0;
}