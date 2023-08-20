#include <iostream>
#include <algorithm>
using namespace std;
// https://www.acwing.com/problem/content/description/9/

const int N = 110;
int f[N][N], s[N];
int v[N][N], w[N][N];
int n, m;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
        for (int j = 0; j < s[i]; ++j) cin >> v[i][j] >> w[i][j];
    }
    
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            f[i][j] = f[i - 1][j];
            for (int k = 0; k < s[i]; ++k)
                if (j >= v[i][k]) f[i][j] = max(f[i][j], f[i - 1][j - v[i][k]] + w[i][k]);
        }
    
    cout << f[n][m];
    return 0;
}

void main2() {
    int f[N];

    for (int i = 1; i <= n; ++i)
        for (int j = m; j >= 0; --j)
            for (int k = 0; k < s[i]; ++k)
                if (j >= v[i][k]) f[j] = max(f[j], f[j - v[i][k]] + w[i][k]);
    
    cout << f[m];
}