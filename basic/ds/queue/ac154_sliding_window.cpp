#include <iostream>
#include <vector>
#include <deque>
using namespace std;
// https://www.acwing.com/problem/content/156/

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    
    deque<int> q;
    for (int i = 0; i < n; ++i) {
        if (q.size() && i - q.front() + 1 > k) q.pop_front();

        while (q.size() && a[q.back()] >= a[i]) q.pop_back();
        q.push_back(i);
        
        if (i >= k - 1) cout << a[q.front()] << ' ';
    }
    cout << '\n';

    q.clear();
    for (int i = 0; i < n; ++i) {
        if (q.size() && i - q.front() + 1 > k) q.pop_front();

        while (q.size() && a[q.back()] <= a[i]) q.pop_back();
        q.push_back(i);
        
        if (i >= k - 1) cout << a[q.front()] << ' ';
    }
    
    return 0;
}