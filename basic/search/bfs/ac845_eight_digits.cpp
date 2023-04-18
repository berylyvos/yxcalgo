#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;
// https://www.acwing.com/problem/content/847/

const string target = "12345678x";
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};

int bfs(string start) {
    queue<string> q;
    q.push(start);
    unordered_map<string, int> d;
    d[start] = 0;
    
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        
        int dist = d[t];
        if (t == target) return dist;
        
        int k = t.find('x');
        int x = k / 3, y = k % 3;
        for (int i = 0; i < 4; ++i) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < 3 && b >= 0 && b < 3) {
                int u = a * 3 + b;
                swap(t[k], t[u]);
                if (d.find(t) == d.end()) {
                    q.push(t);
                    d[t] = dist + 1;
                }
                swap(t[k], t[u]);
            }
        }
    }
    
    return -1;
}

int main() {
    string start;
    char c;
    for (int i = 0; i < 9; ++i) {
        cin >> c;
        start += c;
    }
    
    cout << bfs(start);
    
    return 0;
}