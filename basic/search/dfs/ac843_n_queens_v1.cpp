#include <iostream>
using namespace std;
// https://www.acwing.com/problem/content/845/

const int N = 10;
bool col[N], dg[N * 2], udg[N * 2];
int row[N], n;

void dfs(int u) {
    if (u == n) {
        for (int i = 0; i < n; ++i) { 
            for (int j = 0; j < n; ++j)
                cout << ".Q"[j == row[i]];
            cout << '\n';
        }
        cout << '\n';
        return;
    }
    
    for (int i = 0; i < n; ++i)
        if (!col[i] && !dg[u + i] && !udg[u - i + n]) {
            col[i] = dg[u + i] = udg[u - i + n] = true;
            row[u] = i;
            dfs(u + 1);
            col[i] = dg[u + i] = udg[u - i + n] = false;
        }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    
    dfs(0);
    
    return 0;
}