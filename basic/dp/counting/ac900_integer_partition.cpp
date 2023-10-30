#include <iostream>
using namespace std;
// https://www.acwing.com/problem/content/description/902/

const int N = 1010, MOD = 1e9 + 7;
int f[N];
int n;

int main()
{
    cin >> n;
    f[0] = 1;
    // 完全背包求方案数    
    for (int i = 1; i <= n; ++i)
        for (int j = i; j <= n; ++j)
            f[j] = (f[j] + f[j - i]) % MOD;
    
    cout << f[n];
    
    return 0;
}