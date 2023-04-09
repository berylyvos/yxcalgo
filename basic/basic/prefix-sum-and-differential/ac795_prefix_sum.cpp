#include <iostream>
using namespace std;
// https://www.acwing.com/problem/content/submission/797/

const int N = 100010;
int a[N], n, m, l, r;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    
    while (m--) {
        cin >> l >> r;
        cout << a[r] - a[l - 1] << '\n';
    }
    
    return 0;
}