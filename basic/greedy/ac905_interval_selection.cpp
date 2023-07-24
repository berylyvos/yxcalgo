#include <iostream>
#include <algorithm>
using namespace std;

// https://www.acwing.com/problem/content/description/907/

const int N = 100010, INF = 1e9 + 1;
int n;

struct Section {
    int a, b;
    bool operator< (const Section& s) const { return b < s.b; }
} sec[N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++ i) cin >> sec[i].a >> sec[i].b;
    sort(sec, sec + n);
    
    int res = 0, r = -INF;
    for (auto &s: sec) {
        if (s.a > r) {
            ++res;
            r = s.b;
        }
    }
    
    cout << res;
    
    return 0;
}