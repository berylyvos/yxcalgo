#include <iostream>
#include <algorithm>
using namespace std;

// https://www.acwing.com/problem/content/127/

const int N = 50010;

struct Cow{
    int w, s;
    bool operator<(const Cow& c) const { return w + s < c.w + c.s; }
} a[N];

int main () {
    int n, w, s;
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i].w >> a[i].s;
    sort(a, a + n);
    
    int res = -0x3f3f3f3f;
    for (int i = 0, w = 0; i < n; ++i) {
        res = max(res, w - a[i].s);
        w += a[i].w;
    }
    
    cout << res;
    return 0;
}