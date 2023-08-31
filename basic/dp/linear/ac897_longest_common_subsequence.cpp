#include <iostream>
#include <algorithm>
using namespace std;

// https://www.acwing.com/problem/content/description/899/

const int N = 1010;
char a[N], b[N];
int f[N][N];
int n, m;

int main() {
    cin >> n >> m >> a + 1 >> b + 1;
    
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            if (a[i] == b[j]) f[i][j] = f[i - 1][j - 1] + 1;
            else f[i][j] = max(f[i - 1][j], f[i][j - 1]);
        }
    
    cout << f[n][m];
    
    return 0;
}