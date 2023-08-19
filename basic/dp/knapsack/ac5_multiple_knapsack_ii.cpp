#include <iostream>
#include <algorithm>
using namespace std;

// https://www.acwing.com/problem/content/description/5/

const int N = 12010, M = 2010; // N = 1000 * log(2000)
int f[M], v[N], w[N];
int n, m;

int main() {
    cin >> n >> m;
    
    int cnt = 0, a, b, s;
    while (n--) {
        cin >> a >> b >> s;
        for (int k = 1; k <= s; k <<= 1) {
            v[++cnt] = a * k;
            w[cnt] = b * k;
            s -= k;
        }
        if (s > 0) {
            v[++cnt] = a * s;
            w[cnt] = b * s;
        }
    }
    n = cnt;
    
    // 01-knapsack
    for (int i = 1; i <= n; ++i)
        for (int j = m; j >= v[i]; --j)
            f[j] = max(f[j], f[j - v[i]] + w[i]);
    
    cout << f[m];
    
    return 0;
}