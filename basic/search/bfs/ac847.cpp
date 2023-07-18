#include <iostream>
#include <cstring>
using namespace std;

// https://www.acwing.com/problem/content/849/

const int N = 100010;
int h[N], e[N], ne[N], idx;
int d[N], q[N];
int n, m;

void add(int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; }

int bfs() {
    int hh = 0, tt = 0;
    q[0] = 1;
    d[1] = 0;
    
    while (hh <= tt) {
        int u = q[hh++];
        for (int i = h[u]; ~i; i = ne[i]) {
            int j = e[i];
            if (d[j] == -1) {
                d[j] = d[u] + 1;
                q[++tt] = j;
            }
        }
        
    }
    
    return d[n];
}

int main() {
    memset(h, -1, sizeof h);
    memset(d, -1, sizeof d);
    
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        add(a, b);
    }
    
    cout << bfs();
    
    return 0;
}