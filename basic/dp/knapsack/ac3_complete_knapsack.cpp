#include <iostream>
#include <algorithm>
using namespace std;
// https://www.acwing.com/problem/content/3/

const int N = 1010;
int f[N][N];
int v[N], w[N];
int n, m;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> v[i] >> w[i];
    
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            f[i][j] = f[i - 1][j];
            if (j >= v[i]) 
                f[i][j] = max(f[i][j], f[i][j - v[i]] + w[i]);
        }
    
    cout << f[n][m];
}

void main2() {
    int f[N];
    // init v, w

    for (int i = 1; i <= n; ++i)
        for (int j = v[i]; j <= m; ++j) 
                f[j] = max(f[j], f[j - v[i]] + w[i]);
    
    cout << f[m];
}