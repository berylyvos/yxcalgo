#include <iostream>
using namespace std;
// https://www.acwing.com/problem/content/145/

const int N = 100010;
int son[N * 31][2], idx;
int a[N], n;

void insert(int x) {
    int p = 0;
    for (int i = 30; ~i; --i) {
        int &s = son[p][x >> i & 1];
        if (!s) s = ++idx;
        p = s;
    }
}

int query(int x) {
    int p = 0, res = 0;
    for (int i = 30; ~i; --i) {
        int u = (x >> i & 1);
        if (son[p][!u]) {
            res += (1 << i);
            p = son[p][!u];
        } else {
            p = son[p][u];
        }
    }
    return res;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        insert(a[i]);
    }
    
    int res = 0;
    for (int i = 0; i < n; ++i) {
        res = max(res, query(a[i]));
    }
    cout << res;
    
    return 0;
}