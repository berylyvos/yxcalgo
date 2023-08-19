#include <iostream>
#include <algorithm>
using namespace std;

// https://www.acwing.com/problem/content/description/4/

const int N = 110;
int f[N][N];
int v[N], w[N], s[N];
int n, m;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> v[i] >> w[i] >> s[i];
    
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            for (int k = 0; k <= s[i] && j >= v[i] * k; ++k) 
                    f[i][j] = max(f[i][j], f[i - 1][j - v[i] * k] + w[i] * k);
    
    cout << f[n][m];
    return 0;
}