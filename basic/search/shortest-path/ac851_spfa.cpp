#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

// https://www.acwing.com/problem/content/description/853/

const int N = 100010, INF = 0x3f3f3f3f;
int h[N], e[N], ne[N], w[N], idx;
int d[N];
bool st[N];
int n, m;

void add(int a, int b, int c) { e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++; }

int spfa() {
    memset(d, 0x3f, sizeof d);
    d[1] = 0;
    
    queue<int> q;
    q.push(1);
    st[1] = true;
    while (q.size()) {
        int u = q.front();
        q.pop();
        st[u] = false;
        for (int i = h[u]; ~i; i = ne[i]) {
            int j = e[i];
            if (d[j] > d[u] + w[i]) {
                d[j] = d[u] + w[i];
                if (!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    
    return d[n];
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    memset(h, -1, sizeof h);
    int a, b, c;
    while (m--) {
        cin >> a >> b >> c;
        add(a, b, c);
    }
    
    int t = spfa();
    if (t == INF) cout << "impossible";
    else cout << t;
    
    return 0;
}