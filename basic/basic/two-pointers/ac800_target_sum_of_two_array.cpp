#include <iostream>
using namespace std;
// https://www.acwing.com/problem/content/802/

const int N = 100010;
int a[N], b[N], n, m, x;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m >> x;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];
    
    for (int i = 0, j = m - 1;;) {
        int s = a[i] + b[j];
        if (s > x) {
            --j;
        } else if (s < x) {
            ++i;
        } else {
            cout << i << ' ' << j;
            break;
        }
    }
    
    return 0;
}