#include <iostream>
#include <algorithm>
using namespace std;

// https://www.acwing.com/problem/content/description/915/
// 排序不等式

const int N = 100010;
int t[N], n;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> t[i];
    sort(t, t + n);
    
    long long res = 0;
    for (int i = 0; i < n; ++i) res += t[i] * (n - i - 1);
    
    cout << res;
    return 0;
}