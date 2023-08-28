#include <iostream>
#include <algorithm>
using namespace std;

// https://www.acwing.com/problem/content/description/897/

const int N = 1010;
int a[N], f[N], n;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i], f[i] = 1;
    
    int res = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j < i; ++j)
            if (a[j] < a[i]) {
                f[i] = max(f[i], f[j] + 1);
                res = max(res, f[i]);
            }
    
    cout << res;
    return 0;
}