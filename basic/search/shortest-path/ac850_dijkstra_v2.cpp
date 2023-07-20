#include <iostream>
#include <cstring>
#include <queue>

// https://www.acwing.com/problem/content/852/

using namespace std;
using PII = pair<int, int>;

const int N = 1.5e5 + 10, INF = 0x3f3f3f3f;
int h[N], e[N], ne[N], w[N], idx;
int d[N];
bool st[N];
int n, m;

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dijkstra() {
    memset(d, 0x3f, sizeof d);
    d[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.emplace(0, 1);
    
    while (q.size()) {
        auto [t, u] = q.top();
        q.pop();
        if (st[u]) continue;
        st[u] = true;
        
        for (int i = h[u]; ~i; i = ne[i]) {
            int j = e[i];
            if (d[j] > t + w[i]) {
                d[j] = t + w[i];
                q.emplace(d[j], j);
            }
        }
    }
    
    return d[n] == INF ? -1 : d[n];
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    memset(h, -1, sizeof h);
    int a, b, c;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        add(a, b, c);
    }
    
    cout << dijkstra();
    
    return 0;
}