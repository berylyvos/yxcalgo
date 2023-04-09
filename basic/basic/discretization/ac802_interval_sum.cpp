#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// https://www.acwing.com/problem/content/804/

const int N = 300010;
int s[N], n, m;
vector<int> a;
vector<pair<int, int>> add, query;

// map x to [1..a.size()]
int mapping(int x) {
    int l = 0, r = a.size() - 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (a[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return r + 1;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    add.reserve(n);
    query.reserve(m);
    a.reserve(n + 2 * m);
    
    int x, c, l, r;
    for (int i = 0; i < n; ++i) {
        cin >> x >> c;
        add.emplace_back(x, c);
        a.emplace_back(x);
    }
    for (int i = 0; i < m; ++i) {
        cin >> l >> r;
        query.emplace_back(l, r);
        a.emplace_back(l), a.emplace_back(r);
    }
    
    // sort and deduplicate  a
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    
    // init s by mapping a into s
    for (const auto &it: add) s[mapping(it.first)] += it.second;
    
    // prefix sum of s
    for (int i = 1, sz = a.size(); i <= sz; ++i) s[i] += s[i - 1];
    
    // output interval sum: s[r] - s[l - 1]
    for (const auto &it: query)
        cout << s[mapping(it.second)] - s[mapping(it.first) - 1] << '\n';
    
    return 0;
}