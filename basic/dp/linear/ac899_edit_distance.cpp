#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

// https://www.acwing.com/problem/content/description/901/

const int N = 1010, M = 11;
char s[N][M], q[M];
int f[M][M];
int n, m, t;

int edit_dist(const char* a, const char* b) {
    int u = strlen(a), v = strlen(b);
    for (int i = 1; i <= u; ++i)
        for (int j = 1; j <= v; ++j) {
            f[i][j] = min(f[i - 1][j], f[i][j - 1]) + 1;
            f[i][j] = min(f[i][j], f[i - 1][j - 1] + (a[i - 1] != b[j - 1]));
        }
    return f[u][v];
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> s[i];
    
    for (int i = 1; i < M; ++i) f[i][0] = i, f[0][i] = i;
    
    while (m--) {
        cin >> q >> t;
        int res = 0;
        for (int i = 0; i < n; ++i)
            if (edit_dist(s[i], q) <= t) ++res;
        cout << res << '\n';
    }
    
    return 0;
}