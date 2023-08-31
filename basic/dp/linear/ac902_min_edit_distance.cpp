#include <iostream>
#include <algorithm>
using namespace std;

// https://www.acwing.com/problem/content/description/904/

const int N = 1010;
char a[N], b[N];
int f[N][N];
int n, m;

int main() {
    cin >> n >> a + 1 >> m >> b + 1;
    
    int i, j;
    for (i = 1; i <= n; ++i) f[i][0] = i;
    for (i = 1; i <= m; ++i) f[0][i] = i;
    
    for (i = 1; i <= n; ++i)
        for (j = 1; j <= m; ++j) {
            // 删除a[i]:        f[i - 1][j] + 1
            // a[i]后添加b[j]:  f[i][j - 1] + 1
            // 替换a[i]:        f[i - 1][j - 1] + (a[i] != b[j])
            f[i][j] = min(f[i - 1][j], f[i][j - 1]) + 1;
            f[i][j] = min(f[i][j], f[i - 1][j - 1] + (a[i] != b[j]));
        }
    
    cout << f[n][m];
    
    return 0;
}