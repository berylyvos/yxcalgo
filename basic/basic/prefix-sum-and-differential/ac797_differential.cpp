#include <iostream>
using namespace std;
// https://www.acwing.com/problem/content/799/

const int N = 100010;
int b[N], n, m, l, r, c;

void insert(int l, int r) {
    b[l] += c;
    b[r + 1] -= c;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> c;
        insert(i, i);
    }
    
    while (m--) {
        cin >> l >> r >> c;
        insert(l, r);
    }
    
    for (int i = 1; i <= n; ++i) {
        b[i] += b[i - 1];
        cout << b[i] << ' ';
    }
    
    return 0;
}