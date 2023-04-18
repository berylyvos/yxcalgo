#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
// https://www.acwing.com/problem/content/846/

const int N = 110;
int g[N][N], d[N][N], n, m;

const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};

int bfs() {
    memset(d, -1, sizeof d);
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    d[0][0] = 0;
    
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        int x = t.first, y = t.second;
        for (int i = 0; i < 4; ++i) {
            int a = x + dx[i], b = y + dy[i];
            if (a < n && a >= 0 && b >= 0 && b < m && !g[a][b] && d[a][b] == -1) {
                d[a][b] = d[x][y] + 1;
                q.push(make_pair(a, b));
            }
        }
    }
    
    return d[n - 1][m - 1];
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> g[i][j];
            
    cout << bfs();
    
    return 0;
}