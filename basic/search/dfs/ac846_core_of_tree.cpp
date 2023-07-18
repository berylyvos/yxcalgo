#include <iostream>
#include <cstring>
using namespace std;

// https://www.acwing.com/problem/content/848/

const int N = 100010, M = 2 * N;
int h[N], e[M], ne[M], idx;
bool st[N];
int n, ans = N;

void add(int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; }

int dfs(int u) {
    st[u] = true;
    int total = 1, res = 0;
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (!st[j]) {
            int s = dfs(j);
            total += s;
            res = max(res, s);
        }
    }
    
    res = max(res, n - total);
    ans = min(ans, res);
    return total;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    memset(h, -1, sizeof h);
    int a, b;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    
    dfs(1);
    cout << ans;
    
    return 0;
}