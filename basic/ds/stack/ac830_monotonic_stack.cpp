#include <iostream>
using namespace std;
// https://www.acwing.com/problem/content/832/

const int N = 100010;
int st[N], tt, n, x;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        cin >> x;
        // 维护st严格单调递增
        while (tt && st[tt] >= x) --tt;
        if (tt) cout << st[tt] << ' ';
        else cout << "-1 ";
        st[++tt] = x;
    }
    
    return 0;
}