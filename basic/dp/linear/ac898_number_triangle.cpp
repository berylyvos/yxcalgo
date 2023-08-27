#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

// https://www.acwing.com/problem/content/900/

const int N = 510;
int f[N][N];
int n;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i; ++j)
            cin >> f[i][j];
    
    for (int i = n; i >= 1; --i)
        for (int j = 1; j <= i; ++j)
            f[i][j] += max(f[i + 1][j], f[i + 1][j + 1]);
    
    cout << f[1][1];
    
    return 0;
}