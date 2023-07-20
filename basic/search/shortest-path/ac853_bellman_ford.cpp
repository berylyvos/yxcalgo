#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

// https://www.acwing.com/problem/content/description/855/

const int N = 505, M = 10010, INF = 0x3f3f3f3f >> 1;
int d[N], last_d[N];
int n, m, k;

struct E {
    int a, b, c;
} edge[M];


int bellman_ford() {
    memset(d, 0x3f, sizeof d);
    d[1] = 0;
    
    for (int i = 0; i < k; ++i) {
        memcpy(last_d, d, sizeof d);
        for (int j = 0; j < m; ++j) {
            int a = edge[j].a, b = edge[j].b, w = edge[j].c;
            d[b] = min(d[b], last_d[a] + w);
        }
    }
    
    return d[n] > INF ? -INF : d[n];
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) cin >> edge[i].a >> edge[i].b >> edge[i].c;
    
    int t = bellman_ford();
    if (t == -INF) cout << "impossible";
    else cout << t;
    return 0;
}