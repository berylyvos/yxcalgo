#include <iostream>
#include <algorithm>
using namespace std;

// https://www.acwing.com/problem/content/description/909/

const int N = 100010, INF = 2e9;
int n, st, ed;

struct Section {
    int a, b;
    bool operator< (const Section& s) const { return a < s.a; }
} sec[N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> st >> ed >> n;
    for (int i = 0; i < n; ++i) cin >> sec[i].a >> sec[i].b;
    sort(sec, sec + n);
    
    int res = 0;
    bool success = false;
    for (int i = 0; i < n;) {
        int j = i, r = -INF;
        for (; j < n && sec[j].a <= st; ++j) r = max(r, sec[j].b);
        if (r < st) break;
        
        ++res;
        if (r >= ed) {
            success = true;
            break;
        }
        
        st = r;
        
        i = j;
    }
    
    cout << (success ? res : -1);
    
    return 0;
}