#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// https://www.acwing.com/problem/content/805/

vector<pair<int, int>> interval, merged;
int n, a, b;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    while (n--) {
        cin >> a >> b;
        interval.emplace_back(a, b);
    }
    
    // sort by left endpoints
    sort(interval.begin(), interval.end());
    
    merged.emplace_back(0, -0x3fffffff);
    
    for (auto &cur: interval) {
        auto &right = merged.back().second;
        if (cur.first > right) {
            merged.emplace_back(cur);
        } else {
            right = max(right, cur.second);
        }
    }
    
    cout << merged.size() - 1;
    
    return 0;
}