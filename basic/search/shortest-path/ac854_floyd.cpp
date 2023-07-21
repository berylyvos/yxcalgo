#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

// https://www.acwing.com/problem/content/description/856/

const int N = 205, INF = 0x3f3f3f3f;
int d[N][N];
int n, m, k, T;

void floyd() {
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m >> T;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (i != j) d[i][j] = INF;
    
    int a, b, c;    
    while (m--) {
        cin >> a >> b >> c;
        d[a][b] = min(d[a][b], c);
    }
    
    floyd();
    
    while (T--) {
        cin >> a >> b;
        int res = d[a][b];
        if (res > INF / 2) cout << "impossible\n";
        else cout << res << '\n';
    }
    
    return 0;
}