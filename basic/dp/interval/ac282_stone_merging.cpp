#include <iostream>
#include <algorithm>
using namespace std;

// https://www.acwing.com/problem/content/description/284/

const int N = 310, INF = 1e9;
int f[N][N], s[N];
int n;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> s[i], s[i] += s[i - 1];
    
    for (int t = 2; t <= n; ++t)
        for (int i = 1; i + t - 1 <= n; ++i) {
            int j = i + t - 1;
            f[i][j] = INF;
            for (int k = i; k < j; ++k) f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j]);
            f[i][j] += s[j] - s[i - 1];
        }
    
    cout << f[1][n];
    
    return 0;
}