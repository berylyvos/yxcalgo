#include <iostream>
using namespace std;
// https://www.acwing.com/problem/content/156/

const int N = 1000010;
int a[N], q[N], hh, tt = -1;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    
    for (int i = 0; i < n; ++i) {
        if (hh <= tt && i - q[hh] + 1 > k) ++hh;
        // 维护队列q单调递增
        while (hh <= tt && a[i] <= a[q[tt]]) --tt;
        q[++tt] = i;
        if (i >= k - 1) cout << a[q[hh]] << ' ';
    }

    /* deque version
    for (int i = 0; i < n; ++i) {
        if (!q.empty() && i - q.front() >= k) q.pop_front();
        while (!q.empty() && a[i] <= a[q.back()]) q.pop_back();
        q.push_back(i);
        if (i >= k - 1) cout << a[q.front()] << ' ';
    }
    */

    cout << '\n';
    
    hh = 0, tt = -1; 
    for (int i = 0; i < n; ++i) {
        if (hh <= tt && i - q[hh] + 1 > k) ++hh;
        // 维护队列q单调递减
        while (hh <= tt && a[i] >= a[q[tt]]) --tt;
        q[++tt] = i;
        if (i >= k - 1) cout << a[q[hh]] << ' ';
    }
    
    return 0;
}