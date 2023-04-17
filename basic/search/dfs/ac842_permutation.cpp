#include <iostream>
using namespace std;
// https://www.acwing.com/problem/content/844/

const int N = 10;
int p[N], n;
bool st[N];

void dfs(int u) {
    if (u == n) {
        for (int i = 0; i < n; ++i) cout << p[i] << " \n"[i == n - 1];
        return;
    }
    
    for (int i = 1; i <= n; ++i)
        if (!st[i]) {
            p[u] = i;
            st[i] = true;
            dfs(u + 1);
            st[i] = false;
        }
}

void dfs(int u, int state) {
    if (u == n) {
        for (int i = 0; i < n; ++i) cout << p[i] << " \n"[i == n - 1];
        return;
    }
    
    for (int i = 0; i < n; ++i) 
        if (!(state >> i & 1)) {
            p[u] = i + 1;
            dfs(u + 1, state + (1 << i));
        }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    
    dfs(0, 0);
    
    return 0;
}