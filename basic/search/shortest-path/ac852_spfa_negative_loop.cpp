#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

// https://www.acwing.com/problem/content/854/

const int N = 100010;
int h[N], e[N], w[N], ne[N], idx;
int d[N], cnt[N];
bool st[N];
int n, m;

void add(int a, int b, int c) { e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++; }

bool spfa() {
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        q.push(i);
        st[i] = true;
    }
    
    while (q.size()) {
        int u = q.front();
        q.pop();
        st[u] = false;
        for (int i = h[u]; ~i; i = ne[i]) {
            int j = e[i];
            if (d[j] > d[u] + w[i]) {
                d[j] = d[u] + w[i];
                cnt[j] = cnt[u] + 1;
                if (cnt[j] >= n) return true;
                if (!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    
    return false;
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
    
    cout << (spfa() ? "Yes" : "No");
    
    return 0;
}