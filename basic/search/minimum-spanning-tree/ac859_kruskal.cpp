#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

// https://www.acwing.com/problem/content/description/861/

const int N = 100010, M = 2 * N;
int p[N];
int n, m, res;

struct E {
    int a, b, c;
    bool operator< (const E& e) const { return c < e.c; }
} edge[M];

int find(int x) {
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}

bool kruskal() {
    int cnt = 0;
    sort(edge, edge + m);
    
    for (int i = 0; i < m; ++i) {
        int a = edge[i].a, b = edge[i].b, c = edge[i].c;
        a = find(a), b = find(b);
        if (a != b) {
            p[b] = a;
            res += c;
            ++cnt;
        }
    }
    
    return cnt >= n - 1;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    int a, b, c;
    for (int i = 0; i < m; ++i) cin >> edge[i].a >> edge[i].b >> edge[i].c;
    for (int i = 1; i <= n; ++i) p[i] = i;
    
    if (kruskal()) cout << res;
    else cout << "impossible";
    
    return 0;
}
