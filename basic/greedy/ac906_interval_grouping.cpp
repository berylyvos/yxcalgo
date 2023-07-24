#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

// https://www.acwing.com/problem/content/description/908/

const int N = 100010, INF = 1e9 + 1;
int n;

struct Section {
    int a, b;
    bool operator< (const Section& s) const { return a < s.a; }
} sec[N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++ i) cin >> sec[i].a >> sec[i].b;
    sort(sec, sec + n);
    
    // 小根堆存所有组中右端点的最大值
    priority_queue<int, vector<int>, greater<int>> q;
    q.push(sec[0].b);
    for (int i = 1; i < n; ++i) {
        if (sec[i].a <= q.top()) q.push(sec[i].b);
        else {
            q.pop();
            q.push(sec[i].b);
        }
    }
    
    cout << q.size();
    
    return 0;
}
